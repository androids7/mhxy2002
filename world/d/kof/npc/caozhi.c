//by tianlin 2001.5.1
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("草雉京", ({"caozhi jing", "jing"}));
        set("gender", "男性" );
        set("age", 30);
        set("long", "他是八神庵的死敌.\n");
        set("combat_exp", 320000);
  set("daoxing", 3200000);

        set("attitude", "friendly");
        create_family("格斗之王", 2, "首徒");
	set("int", 25+random(5));
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 200);  
        set_skill("literate", 10);
        set_skill("dodge", 280);  
        set_skill("force", 280);   

       // map_skill("spells", "dao");
       // map_skill("unarmed", "puti-zhi");
       // map_skill("force", "wuxiangforce");
       // map_skill("stick", "qianjun-bang");
       // map_skill("parry", "qianjun-bang");
       // map_skill("dodge", "jindouyun");


        set("per", 30);
        set("max_kee", 2500);
        set("max_gin", 2400);
        set("max_sen", 2400);
        set("force", 2450);
        set("max_force", 2300);
        set("force_factor", 150);
        set("mana", 2450);
        set("max_mana", 2300);
        set("mana_factor", 108);
//	set("chat_chance_combat", 50);
//	set("chat_msg_combat", ({
	//	(: cast_spell, "thunder" :),
  //      }) );

        setup();
       // carry_object("/d/kof/obj/cloth")->wear();
       // carry_object("/d/kof/obj/bang")->wield();
}
void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("combat_exp") < 100000)) {
	command("say " + RANK_D->query_respect(ob) +
"sigh..sigh..你还是再练练吧");
	return;
	}
        command("say 好，" + RANK_D->query_respect(ob) +
"那好吧.我就手下你.\n");
        command("recruit " + ob->query("id") );
}
// int recruit_apprentice(object ob)
// {
       // if( ::recruit_apprentice(ob) )
               // ob->set("class", "taoist");
// }

�
