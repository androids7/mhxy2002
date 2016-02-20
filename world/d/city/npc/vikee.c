// zong guan vikee.c
// created by vikee 2000.11
//by tianlin 2001.5.1
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(""CYN"总管"NOR"", ({HIR"gua"NOR, "gua", "gua"}));
       set("long", "一位英俊潇洒，附有男子美丽和绝世才华的人"BLINK+HIR"(list)"NOR"。\n");
	set("gender", "男性");
	set("age", 20);
	set("per", 40);
	set("title",""WHT"装备贩子"NOR);
	set_skill("literate", 141);
	set("chat_chance",20);
    set("chat_msg", ({
        "南瓜轻声告诉你：你可以用"HIR"list"NOR"指令列出想要的东西！\n",
        "南瓜轻声告诉你：你可以用"HIR"yao"NOR"指令向总管我索取装备。\n",
        "南瓜很神气的说：我就是总管，总管就是我！\n",               
        }));
	setup();
	carry_object("/d/obj/cloth/magua")->wear();
}

void init()
{
	::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_ji","ji");
  add_action("do_throw","throw");
  add_action("do_list","list");
  add_action("do_yao","yao");
}

void die()
{
 return;
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
        message_vision("$N看样子想打架，但南瓜很有涵养,不和$N动粗。\n",who,me);
     return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
message_vision("$N看样子想杀死南瓜，但南瓜是文化人,没跟$N一般见识。\n",who,me);

    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N对着南瓜结结巴巴的念了几句咒语，自己都感觉难听死了。\n",who,me);

  return 1;
}


int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想偷东西，但总是有贼心没贼胆。\n",who,me);

  return 1;
}


int do_ji(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想对麦克小狼祭法宝，前思后想，还是没敢。\n",who,me);

  return 1;
}

int do_throw(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N掏出暗器，看了看麦克小狼，信心不足，又把暗器收了起来。\n",who,me);

  return 1;
}

int do_list(string arg)
{
	object who = this_player();
	object me = this_object();
  message("vision",""HIG"\n─────────────────────────────────────
          \n"HIY"盔甲："NOR CYN"
          1.金甲(armor)     2. 披风(pifeng)   3.盾牌(shield)
          4.铁盔(kui)       5. 战袍(cloth)    6.踏云靴(shoes)
          \n"HIY"兵器："NOR CYN" 
          1.降魔棒(stick)   2. 青虹剑(sword)  3.软龙筋(whip)
          4.金刀(blade)     5. 短铁爪(zhua)   6.黄铜禅杖(staff)
          7.宣花斧(axe)     8. 月牙铲(fork)   9.梅花锤(hammer)
          10.点金枪(spear)  11.凤凰琴(qin)  12.无量神伞(san)
"HIG"\n─────────────────────────────────────\n"NOR"",who,me);

  return 1;
}

int do_yao(string arg)
{
	string type;
	object ob;
	object who=this_player();
	object me=this_object();
/*
	if (who->query("combat_exp")>500000)
		return notify_fail("凭您的功夫，还是自己去打装备吧! :P\n");
*/
    if (!arg)
		return notify_fail("你想要什么？兵器？还是盔甲？(比如:yao sword)\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
			//盔甲
			case "armor":
				ob=new("/d/city/npc/obj/armor.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "pifeng":
				ob=new("/d/city/npc/obj/pifeng.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "shield":
				ob=new("/d/city/npc/obj/shield.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "shoes":
				ob=new("/d/city/npc/obj/shoes.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
tell_object(who,"南瓜把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "cloth":
				ob=new("/d/city/npc/obj/cloth.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
tell_object(who,"南瓜把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "kui":
				ob=new("/d/city/npc/obj/kui.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
tell_object(who,"南瓜把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
				//兵器
			case "sword":
				ob=new("/d/city/npc/obj/sword.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
tell_object(who,"南瓜把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "whip":
				ob=new("/d/city/npc/obj/whip.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "blade":
				ob=new("/d/city/npc/obj/blade.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "stick":
				ob=new("/d/city/npc/obj/stick.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
                        case "spear":
                                ob=new("/d/city/npc/obj/spear.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "fork":
				ob=new("/d/city/npc/obj/fork.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "hammer":
				ob=new("/d/city/npc/obj/hammer.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
                          case "qin":
                                  ob=new("/d/city/npc/obj/qin.c");
                                  ob->set("no_sell", 1);
                                  ob->set("no_drop", 1);
                                  ob->set("no_give", 1);
                                  ob->move(who);
tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                  break;
			case "axe":
				ob=new("/d/city/npc/obj/axe.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "staff":
				ob=new("/d/city/npc/obj/staff.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "zhua":
				ob=new("/d/city/npc/obj/zhua.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"麦克小狼把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;           

			}
	}
return 1;

}
