// fuhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIY"伏虎罗汉"NOR, ({"xianglong luohan", "luohan"}));
       set("long", "与降龙罗汉一样，是天上神兵之一。\n");
       set("title", HIC"武帝门"NOR);
       set("gender", "男性");
       set("age", 50);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "罗汉");
       set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
       set("max_kee", 3000);
       set("max_gin", 500);
       set("max_sen", 3000);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 50);
       set("max_mana", 1500);
       set("mana", 2000);
       set("mana_factor", 50);
       set("combat_exp", 1400000);
       set("daoxing", 2100000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 140);  
        set_skill("feisheng", 140);
        set_skill("literate", 100);
        set_skill("sword", 140);  
        set_skill("wuying", 100);
        set_skill("fumobashi", 100);  
        set_skill("mizongbu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("xiantian", 140);

        map_skill("spells", "feisheng");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");

create_family("武圣门", 2, "罗汉");
   setup();
   carry_object("/d/obj/weapon/sword/qinghong")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}
void attempt_apprentice(object ob, object me)
{
        command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wusheng");
}

�
