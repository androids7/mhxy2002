
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("太上老君",({"taishang laojun","laojun","dao"}));
  set("gender", "男性");
  set("age", 55);
  set("long", "    \n太上老君。\n");

  set("attitude", "peaceful");
  set("class", "taoist");
  set("combat_exp", 2000000);
  set("daoxing", 4000000);
  set("kee", 400);
  set("max_kee", 400);
  set("sen", 400);
  set("max_sen", 400);
  set("force", 400);
  set("max_force", 400);
  set("mana", 400);
  set("max_mana", 400);
  set("force_factor", 5);
  set("mana_factor", 10);



  set_skill("spells", 30);
  set_skill("dao", 30);
  set_skill("dodge", 60);
  set_skill("parry", 40);
  set_skill("unarmed", 30);


  set("inquiry", ([
  "here"   : "这里就是兜率宫，你来这里干什么？",
]));


setup();

carry_object("/d/lingtai/obj/cloth")->wear();

}


void init()
{

  object who;

  ::init();
  if( interactive(who = this_player()) && !is_fighting() ) 
    {
     remove_call_out("greeting");
     call_out("greeting", 1, who);
    }
}


void greeting(object who)
{
  object me = this_object();
  if (who->query("dntg/laojunlu")=="allow")
    {
    me->command("kick");
        who->set("dntg/laojunlu","allow");
    me->command("chat 大事不好！"HIR+who->query("name")+HIC" 从八卦炉中逃出来了～～～～");
    remove_call_out("leave_laojunlu");
    call_out("leave_laojunlu", 1, who);  
    } 
}

int leave_laojunlu(object who)
{
    who = this_player();
message("channel:rumor", HIC"【谈天说地】"HIR+who->query("name")+"一脚踢翻老君炉,怒火直冲九霄～～～～ \n"NOR, users());
    who->command("chat [1;31m玉帝老儿你等着，待我这就杀上灵霄殿，夺了你那昏君的宝座！！！[0m");
    who->move("/d/dntg/sky/tongmingdian");
}