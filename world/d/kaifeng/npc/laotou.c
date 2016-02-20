// By tianlin 2001.5.1
inherit NPC;
#include <ansi.h>
inherit F_MASTER;

void create()
{
       set_name("于老头", ({"yu laotou","laotou"}));

        set("long","于老头是天蓬帅府里的看门老大爷。\n");
       set("gender", "男性");
       set("age", 20);
 	set("title", "[1;32m天蓬帅府总管[2;37;0m");
        set("int", 25);
       set("attitude", "peaceful");
        set("combat_exp", 1200000);
  set("daoxing", 1500000);


        set("eff_dx", -500000);
        set("nkgain", 500);

       set("class","tianpeng");
       set("per", 10);
	set("str", 30);
  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 2600);
  set("max_mana", 2000);
  set("mana", 4000);
  set("force", 4000);
  set("force_factor", 100);
  set("mana_factor", 120);
  set_skill("unarmed", 200);
  set_skill("dodge", 190);
  set_skill("parry", 160);
  set_skill("rake", 150);
  set_skill("force", 190);
  set_skill("spells", 180);
  set_skill("fofa", 180);
  set_skill("literate", 120);
  set_skill("tianpeng-zhang", 200);
  set_skill("bajie-force", 170);
  set_skill("chaos-steps", 190);
  set_skill("skyriver-rake", 160);
  map_skill("force", "bajie-force");
  map_skill("spells", "fofa");
  map_skill("rake", "skyriver-rake");
  map_skill("unarmed", "tianpeng-zhang");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "chaos-steps");
	create_family("天蓬帅府", 2, "弟子");

        setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  command("pat "+me->query("id"));
  command("say 很好，时下正是用人之际"+myname+"多加努力，他日必定有成。");
  command("recruit " + me->query("id") );
message("system", HIY"天蓬帅府又多了一个弟子  "+this_player()->name()+HIW"
           天蓬帅府的势力加强了。\n"NOR,users());
  return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
ob->set("class", "tianpeng");
               // ob->set("title", "乱石山碧波潭小妖");
        }
}

�
