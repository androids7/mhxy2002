//puti.c
//inherit NPC;
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name("泰山王", ({"taishan wang", "wang", "taishan"}));
       set("title", HIB"阴间"HIY"十王之"NOR);
	set("class", "youling");
       set("gender", "男性");
       set("age", 100);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 30);
        set("int", 30+random(5));
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 50);
       set("max_mana", 1000);
       set("mana", 1000);
       set("mana_factor", 20);
  set("combat_exp", 1500000);
  set("daoxing", 2500000);

	set_skill("spells", 100);
       set_skill("unarmed", 150);
       set_skill("dodge", 150);
       set_skill("parry", 150);
        set_skill("spells", 150);
        set_skill("force", 150);
	set_skill("gouhunshu", 100);
	set_skill("tonsillit", 100);
	map_skill("force", "tonsillit");
	map_skill("spells", "gouhunshu");

create_family("阎罗地府", 1, "你好");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/lingtai/obj/putibang")->wield();
}

�
