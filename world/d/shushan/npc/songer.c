// songer.c...yushu, 2000.10.24.

inherit NPC;
void create()
{
        set_name("�ɶ�", ({"song er", "er", "songer"}));
        //set("title", "");
        set("gender", "����" );
        set("age", 22);
        set("per", 30);
        set("long", "��ɽ�ɵĵ��������ӡ�\n");
        set("class", "xiake");
        set("combat_exp", 120000);
       set("daoxing", 200000);
       set("attitude", "peaceful");
        create_family("��ɽ��", 3, "����");
        set_skill("unarmed", 80);
        set_skill("dodge", 90);
        set_skill("zuixian-steps", 90);
        set_skill("parry", 90);
             set_skill("taoism", 70);
        set_skill("sword", 100);
        set_skill("fumozhang", 90);
        set_skill("yujianshu", 100);
        set_skill("force", 100);   
        set_skill("shushan-force", 90);
        set_skill("literate", 70);
        set_skill("spells", 90);
        set_skill("xianfeng-spells", 90);
        map_skill("spells", "xianfeng-spells");
        map_skill("unarmed", "fumozhang");
        map_skill("force", "shushan-force");
        map_skill("sword", "yujianshu");
        map_skill("dodge", "zuixian-steps");
       set("max_kee", 500);
        set("max_sen", 500);
        set("force", 1000);
        set("max_force", 800);
        set("mana", 1600);
        set("max_mana", 800);   
        set("force_factor", 40);
        set("mana_factor", 40);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("d/obj/weapon/sword/qinghong")->wield();
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("family/family_name")=="��ɽ��" )
        {
                if( (int)ob->query("family/generation") < 3  )
                {
                        if ( (string)ob->query("gender") == "����" ) command("say ʦ���Ц�ˡ�\n");
                        else command("say ʦ�ü�Ц�ˡ�\n");
                }
                else if( (int)ob->query("family/generation") ==3  )
                {
                        if ( (string)ob->query("gender") == "����" ) command("say ʦ��̫�����ˡ�\n");
                        else command("say ʦ��̫�����ˡ�\n");
                }
                else 
                {
                        command("snicker");
                        command("say �����ʺ�һ������!\n");
                        command("recruit " + ob->query("id") );
                }
        }

        else
        {
                command("say �ã�����ɽ��һ���˲ű�������ɵø�ʦ��������\n");
                command("recruit " + ob->query("id") );
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xiake");
}
