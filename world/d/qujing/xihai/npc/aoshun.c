//by tianlin 2001.7.27
inherit NPC;
#include <ansi.h>
int ask_zhong();

void create()
{
       set_name("敖顺", ({"ao shun", "ao","shun","longwang","wang","aoshun"}));
       set("gender", "男性");
       set("age", 30);
       set("long","敖顺乃西海龙王，乃东海龙王敖广之弟。\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("age", 65);
       set("title", "西海龙王");
       set("class","dragon");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 1200000);
       set("rank_info/respect", "陛下");
       set("per", 20);
       set("str", 30);
       set("max_kee", 3000);
       set("max_gin", 400);
       set("max_sen", 800);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 120);
       set("max_mana", 800);
       set("mana", 1600);
       set("mana_factor", 40);

       set("combat_exp", 1200000);
       set_skill("unarmed", 200);
       set_skill("dodge", 150);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("fork", 150);
       set_skill("spells", 150);
       set_skill("seashentong", 150);
       set_skill("dragonfight", 200);
       set_skill("dragonforce", 150);
       set_skill("fengbo-cha", 180);
       set_skill("dragonstep", 150);
       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "fengbo-cha");
       map_skill("parry", "fengbo-cha");
       map_skill("dodge", "dragonstep");
         set("inquiry", ([
     "龙冢": (: ask_zhong:),
        ]));


setup();
        carry_object("/d/obj/cloth/longpao")->wear();
}


int ask_zhong()
{
        object me;
        me=this_player(); 
            if(me->query("xinguan/heishui")!="done") { 
            command("disagree");
            command("say 你是什么人，竟敢打我龙族圣地的主意！\n");
          return 1;
            }
            else
            {
               if(!me->query_temp("龙冢")){
                 command("shake");
                 command("say 龙冢是我西海龙族安息之所,"+RANK_D->query_respect(me)+"不得入内");
                 command("say 虽然"+RANK_D->query_respect(me)+"于我西海有所恩德,小龙也不敢坏了祖宗遗命.");
                 return 1;
               }
               command("consider");
               command("say 既然……既然"+RANK_D->query_respect(me)+"要去，那……就去吧。\n");
               message_vision(HIG"敖顺大袖一招，$N昏乎乎地到了一个陌生的地方。\n"NOR,me);
               me->move("/d/qujing/xihai/zhong");
          return 1;
            }
      return 1;
}


int accept_object(object me,object ob)
{       object who;
        me=this_object();
        who=this_player();

        if (ob->query("id")=="letter" ){
        if(who->query("xinguan/heishui")=="done") { 
                command("hoho");
                command("say "+RANK_D->query_respect(who)+"又来了么？\n");
                command("say 那孽畜之事多谢"+RANK_D->query_respect(who)+"代为遮掩，小龙不胜感激。\n");
                command("say "+RANK_D->query_respect(who)+"今次光临寒舍，有何贵干？\n");
                call_out("destroy", 1, ob);
                who->set_temp("龙冢",1);
                return 1;
        }       
        if( who->query_temp("heshen")) {
                call_out("read", 2);
                return 1;
        }
        command("heng");
        command("say 无凭无据，你不是在冤枉人吧。\n");
        command("say 老夫已经知道了，"+RANK_D->query_respect(who)+ "请回吧。\n");
        call_out("destroy", 1, ob);
        return 1;
        }
}

void read()
{
        object who;
        who = this_player();
        
    message_vision ("敖顺点点头,拿起信帖,看了起来。\n",who);  

        call_out("say",2);
}

void say()
{
        object who;
        who = this_player();
        
    message_vision ("敖顺摇头叹道：“家门不幸，出此败类！”\n",who);  
        call_out("cry",2);
}
void cry()
{
        object who;
        who = this_player();
        
        command("cry");
        call_out("man",2);
}
void man()
{
        object who;
        who = this_player();
        
        command("say " +RANK_D->query_respect(who)+ "请救小神一命，切勿告知玉帝！\n");
        call_out("zuo",2);
}
void zuo(object me,object ob)
{
        object who;
        who = this_player();
        
        command("say " +RANK_D->query_respect(who)+"且令犬子摩昂，同往黑水擒此妖孽。\n");
        who->set_temp("王命",1);
                call_out("destroy", 1, ob);
}
void destroy(object ob)
{
        destruct(ob);
        return;
}


void announce_success (object who) 
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/heishui") == "done") || who->query("obstacle/shushan") != "done")
    return; 
   if(!who->query_temp("fight"))
    return;
   if(!who->query_temp("killlong"))
    return;
  i = random(1000);
  who->add("obstacle/number",1);
  who->set("obstacle/heishui","done");
  who->add("daoxing",i+4000); 
  command("chat "+who->query("name")+"黑水收孽龙，长河荡妖魔！");
message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第三十九关！\n"NOR,users());//this is by tianlin 2001.5.8
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save(); 
}


