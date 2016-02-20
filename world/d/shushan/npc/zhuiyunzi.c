//zhui yunzi-yushu 2001.2.
inherit NPC;
void create()
{
       set_name("追云子", ({"zhui yunzi", "yunzi", "zi"}));
       set("title", "蜀山派第三代弟子");   
       set("gender", "男性");
       set("age", 32);
       set("attitude", "friendly");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 30);
       set("con", 30);
       set("combat_exp", 500000);
       set("daoxing", 500000);
       set("max_kee", 1000);
       set("max_sen", 1000);
       set("force", 3600);
       set("max_force", 1800);
       set("force_factor", 90);
       set("max_mana", 1800);
       set("mana", 3600);
       set("mana_factor", 90);
	set_skill("shushan-force", 150);
	set_skill("yujianshu", 150);
       set_skill("dodge", 150);
       set_skill("literate", 90);
       set_skill("sword", 140);
       set_skill("force", 150);
       set_skill("parry", 160);
       set_skill("spells", 150);
       set_skill("xianfeng-spells", 150);
       set_skill("zuixian-steps", 150);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "shushan-force");
       map_skill("spells", "xianfeng-spells");
       create_family("蜀山派", 3, "弟子");
       setup();
       carry_object("/d/lingtai/obj/pao")->wear();
       carry_object("d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="蜀山派" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
			else command("say 师姑见笑了。\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
			else command("say 师妹太客气了。\n");
		}
		else 
		{
			command("consider");
			command("say 是你自己要拜的，可别怪我啊!。\n");
			command("recruit " + ob->query("id") );
		}
	}
            else
	{
		command("say 好，我蜀山派一门人才辈出，你可得给师父争气。\n");
		command("recruit " + ob->query("id") );
	}

	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山派第四代弟子");
                            }
              return 0;
}

�
