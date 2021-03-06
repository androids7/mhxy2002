//By tianlin@mhxy for 2001.10.1
//八月十五制作,加入sld门派
#include <ansi.h>
#define MAX_TRY 20
inherit NPC;
string ask_me();
string ask_mieyao();
string ask_cancel();
inherit F_MASTER;

void create()
{
	set_name("六耳猕猴", ({"liuer mihou", "liuer", "mihou"}));
	set("title", CYN"灵通子"NOR);
       set("nickname","[1;33m齐天小圣[m");
	set("gender", "男性" );
	set("age", 35);
	set("per", 14);
	set("str", 30);
  set("long", "
六耳灵猴本来居住在雪山，不知为何他会在这里出现。六耳猕猴冷酷无情，
不过要是投其所好,你让他把自己老子杀了都行！！。\n");
  set("combat_exp", 5000000);
  set("daoxing", 3456789);
  set("max_mana",5000);
  set("max_force",5000);
  set("force",5000);
  set("mana",5000);
  set("mana_factor",200);
  set("force_factor",200);
  set("attitude", "heroism");
  set_skill("unarmed", 290);
  set_skill("dodge", 260);
  set_skill("stick",280);
  set_skill("qitian-gun",280);
  set_skill("mihouxinjing",270);
  set_skill("mihou-force",280);
  set_skill("force",280);
  set_skill("spells",250);
  set_skill("jindouyun",260);
  set_skill("houquan",290);
  set_skill("parry", 260);
  set("per", 40);
  set("max_kee", 3500);
  set("max_gin", 3000);
  set("max_sen", 3000);
  map_skill("parry","qitian-gun");
  map_skill("dodge","jindouyun");
  map_skill("unarmed","houquan");
  map_skill("stick","qitian-gun");
  map_skill("spells","mihouxinjing");
  map_skill("force","mihou-force");
  set("chat_chance_combat", 90);
   set("chat_msg_combat", ({
    (: perform_action, "stick.wu" :)
   }) );
  create_family("水帘洞", 2, "洞主");
  setup();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/stick/xiangmo")->wield();
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "houyao");
                ob->set("title", "[1;32m花果山[41m[1;37m水帘洞六耳猕猴传人[2;37;0m");
}
void init()
{
  object ob;
  ::init();
  set("chat_chance", 11);
  set("inquiry", ([
		"name": "齐天大圣孙悟空是也。\n",
		"here": "。。。\n",
		"人参果": "猴爷我最喜欢的就是人参果。\n",
		"杀人": "杀人？只要你有人参果，什么都好商量。\n",
		"秘诀": "秘诀？只要你有人参果，什么都好商量。\n",
		"猕猴手记": "手记？只要你有人参果，什么都好商量。\n",
              "孙悟空" : "就他那种道行也配称战斗胜佛？？我就是来找他麻烦的！！",
              "斗佛" : (: ask_mieyao :),
              "cancel" : (: ask_cancel :),
		"包裹"     : (: ask_me :),
		"真假"     : (: ask_me :),
	]) );

}

int accept_object(object me, object ob)
{
	object book;

	if ( (string)ob->query("id") != "renshen guo" ) {
		message_vision("六耳猕猴尖声叫道：去！去！去！你家猴爷没空理你！\n", me);
		command("kick " + me->query("id"));
		//call_out("do_drop", 2, ob);
		return 1;
	}

	else {
		command("jump ");
		command("say 这位" + RANK_D->query_respect(me) + "果然是痛快人！\n");
		//first give a book...
 book = new("/d/obj/book/mihou-book");
		book->move(me);
		message_vision("$N对$n道：那猴爷我也不能小气。说罢递给$n一本小册子。\n除了这本书外，别的我帮不上，但杀个人是没问题的。你要杀人的话，尽可附耳说来(whisper liuer enemy_id)。\n", this_object(), me);
		me->set_temp("rsg_given", 1);
       		return 1;
	}
}

void do_drop(object ob)
{
	command("drop "+ob->query("id"));
}

void relay_whisper(object me, string msg)
{
	object target, where;

	if (me->query_temp("rsg_given") != 1)
	{
		message_vision((string)this_object()->query("name") + "对着$N冷冷地看了一眼。\n", me);
		return;
	}

	if( query_temp("I_am_busy") == 1 )
	{
		message_vision((string)this_object()->query("name") + "对$N道：我现在正忙着，你等会再来吧。\n", me);
		return;
	}

	
	target = find_player(msg);
	if( !target )
	{ 
		message_vision((string)this_object()->query("name") + "对$N说道：好像找不到这个人。\n", me);
		return;
	}

	where = environment(target);
	if( !where )
	{ 
		message_vision((string)this_object()->query("name") + "对$N说道：这个人是有，但是躲起来了。\n", me);
		return;
	}

	//now got the target player...
	message_vision((string)this_object()->query("name") + "对$N说道：好，你就静候佳音吧！\n", me);

	me->delete_temp("rsg_given");
	set_temp("I_am_busy", 1);
	set_temp("kill_count", MAX_TRY);

	remove_call_out ("try_kill");
	call_out ("try_kill", 3, msg);
	call_out ("check_finish", 3, msg);
	//note, here we still use target id for future trying...
}

void check_finish(string target_id)
{
	object target;

	//here alway set fali back, since liuer mihou is in a "bian" status...
	if( (int)this_object()->query("mana") < (int)this_object()->query("max_mana") )
		this_object()->set("mana", 2*(int)this_object()->query("max_mana"));

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("check_finish");
		call_out ("check_finish", 15, target_id);//try every 15 second.
		return; 
	}

	if( target->is_ghost() )
	{//means the target is dead.
		//bian back now...
		command("bian");
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		remove_call_out ("try_kill");
		remove_call_out ("check_finish");
		return;
	}
	else
	{
		remove_call_out ("check_finish");
		call_out ("check_finish", 15, target_id);//try every 15 second.
		return; 
	}
}

void  try_kill(string target_id)
{
	object target, where;

	if( (int)query_temp("kill_count") <= 0 )
	{//tried too long
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		return;
	}

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 900, target_id);//try every 15 minutes.
		return; 
	}

	where = environment(target);
	if( !where )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 900, target_id);//try every 15 minutes.
		return; 
	}

	//now kill...
	if( where != environment(this_object()) )
	{
		this_object()->move(where);
		message_vision(YEL "只见几道金光乱晃不止，$N一个筋斗翻了出来。\n" NOR, this_object());
	}
	message_vision(RED "$N抓耳挠腮地对$n尖声说道：到了阎王那儿休怪猴爷无情。阁下要是有人参果我一样能替你杀人。\n" NOR, this_object(), target);

	if( (int)query_temp("kill_count") == MAX_TRY ) 
	{//first time, always need to initialize kill...
		command("bian " + target_id);
		//this_object()->kill_ob(target);
		//need consider this carefully, is it ok to make safe place unsafe?
		command("kill " + target_id);
	}
	else command("kill " + target_id);
	//problem here, if kill_ob(), may bypass no_fight, ...etc;
	//if kill command, may confuse with NPC of the same name?
	command("follow "+target_id);

	set_temp("kill_count", (int)query_temp("kill_count")-1);

	remove_call_out ("try_kill");
	call_out ("try_kill", 900, target_id);//try every 15 minutes.
}

//LPG 19990925 真假美猴王

string ask_me()
{
  if (this_player()->query("obstacle/liuer-mihou") == "done" || this_player()->query("obstacle/biqiu") != "done")
return 0;
else
{
	this_player()->set_temp("liuer-mihou_ask","done");
	call_out("autokill",1,this_player(),this_object());
	return "嘿嘿";
}
}
void autokill (object me, object who)
{
  message_vision ("$n大喝一声要杀死$N！\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
}
void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N大怒：哪个泼贼子冒充你家猴爷！\n",this_player());

  set_temp("my_killer",ob);
  this_player()->kill_ob(me);
}

void unconcious()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object baoguo;
  message_vision(HIY "\n观音突然从彩云间现身。\n" NOR,me);
  message_vision(HIY "\n观音对$N一点手，你这猴头！\n" NOR,me);
  message_vision(HIY "$N哎呀一声，现了真身。\n\n" NOR,me);
  if ((ob) && (ob->query_temp("liuer-mihou_ask") == "done"))
  {
  	ob->set_temp("obstacle/liuer-mihou/liuer-mihou_killed",1);
	message_vision(HIC "观音说道：这厮我带走，你安心取经去吧。\n\n" NOR,me);
  	baoguo = new ("/d/obj/misc/baoguo");
  	baoguo -> move(ob);
	message_vision("$N拿出个包裹。\n\n",me);
  	call_out ("guan_appearing",1,ob);
  }
  ob->set_temp("liuer-mihou_ask","no");
  message_vision("$N悻悻地走了。\n\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void guan_appearing (object who)
{
  object guan = new ("/d/qujing/mihou/guanyin");
  guan->announce_success (who);
  destruct (guan); 
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}
string ask_cancel()
{
    object me=this_player();
    if("/d/obj/mieyao"->delete_mieyao(me))
    me->add("faith",-5);
    return ("没用的东西！");
}

string ask_mieyao()
{
    object me=this_player();

    if(me->query("family/family_name")!="水帘洞")
      return ("你不是本门中人!");
   command("pat "+me->query("id"));
  write(WHT+"/d/obj/mieyao"->query_yao(me)+NOR);
   return "有志气！\n";
}

void attempt_apprentice(object ob)
{
 
        if ((int)ob->query_skill("mihouxinjing",1) <80) {
        command("say 你的法术太低了,还是努努力先提高一下吧!");
        command("slap " + ob->query("id"));
                return;
    }
        
        if ((int)ob->query_skill("mihou-force",1) < 80){
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
        command("kick2 " + ob->query("id"));                
                return;
    }

    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
}

