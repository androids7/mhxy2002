
//created 4-6-2000 fly

inherit NPC;
int do_drop(object, object);
#include <ansi.h>
void create()
{
        set_name("��������", ({ "new","test","someone"}) );
        set("title", "");        
        set("gender", "����" );
        set("long",HIM"
��������Կ����µ�SKILLS���µ�PERFORM
�����������ಫ,����Ը�!
�����ʲôbug �� post �ڿ�ջ
\n"NOR);
        set("age",37);
        set("str",40);
        set("int",40);
        set("per",40);        
        set("force",12000);
        set("max_kee",20000);        
        set("kee",20000);        
        set("max_sen",20000);        
        set("sen",20000);        
        set("combat_exp",10000000);
        set("max_force",6000);
        set("mana",20000);
        set("max_mana",10000);
        set("force_factor", 100);
        set("mana_factor", 250);


        set_skill("spells", 220);
        set_skill("unarmed",220);
        set_skill("parry",220);
        set_skill("dodge",220);
        set_skill("moyun-shou",220);
        set_skill("force",220);
        set_skill("sword",220);
        set_skill("NO.1_skill",220);
          map_skill("unarmed", "moyun-shou");
          map_skill("force", "NO.1_skill");
          map_skill("spells", "NO.1_skill");
          map_skill("sword", "NO.1_skill");
          map_skill("dodge", "NO.1_skill");
   set("chat_chance_combat", 900);
/*
        set("chat_msg_combat", ({
          (: perform_action, "juesha" :),
          (: perform_action, "sanmai" :),
          (: perform_action, "sword.juesha" :),
          (: perform_action, "sword.sanmai" :),
          (: perform_action, "sword.cimu" :),
          (: perform_action, "cimu" :),
        }) );
*/
   create_family("��ңɽׯ", 4, "����");
        setup();
      carry_object("/d/obj/weapon/sword/changjian")->wield();
}
void init()
{       
   object ob=this_player();
   object me=this_object();
   ::init();

   set("chat_chance", 10);
   set("inquiry", ([
                "name" : "������ǵ���ķ�ѩ.",
                "fly" : "������������ѽ",
                "��ѩ" : "������������ѽ",
                "happ" : "�������ǵ�admin ...������",
                "����" : "�������ǵ�admin ...������",
                "here" : "�����Ƿ�ѩ�������еĵط�.",
        ]) );

   set("chat_msg", ({
     "��ѩ��������Ц�˼�����\n",   
     "��ѩ������ԡѪϦ������ִ���������쳤Ц�������ķ�������������˻����ϣ�����Ӣ�ۣ�������˭��\n",   
     "��ѩһ��������������ӣ���Ц��������Ǹ��������ܣ���֪����֪����֪�㲻֪������������\n",   
     "��ѩ��Ц������������������ʹ���칦�ƣ�׳־δ���Ĳ��ݡ����շ��������֣�������Ѫд���\n",   
     "��ѩ�������ߵ��һ�һƬƬ��ˮ��ȥ����̾���������ޣ�һ���飬�˼�δ���֪����\n",   
     "��ѩ����ĳ�����������Ҳ��Ը��������ҹ����������Ը������˼�ʶ������ġ�����\n",   
     "��ѩ�������ˣ���üһ������Ȼ˵��������λ�������ϣ����ɹúξ壿����\n",   
     "��ѩ��������һ֧����������ŵ�������������������˼���������㼴ƽ�������漴�͵���������Ц�����ټ��ģ��������ڳճ�ЦЦ����\n",   
     "��ѩ������ֽŽ�Ӳ������ľȻ������ɢ���������󣬲���ҡ��ҡͷ��������, ���ǻ����ˣ���\n",   
   }) );

}
void attempt_apprentice(object ob)
{
        mapping fam; 
        ob = this_player();
        fam = ob->query("family");

   message_vision(HIY "��ѩͻȻ΢һ����������Խ����ʾ��һ����������������ˮ����������׷�¡�\n"NOR,ob);
       write(HIY"�㿴�ſ��ţ�ͻȻ�������������һ�㣬���������1��\n"NOR);
       command("pat " + ob->query("id"));
        command("recruit " + ob->query("id"));
        ob->set("name",BMAG"��ѩ"NOR);
}