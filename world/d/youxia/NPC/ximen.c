
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 //created 23-06-2001 ����Ʈ(piao)

//yegucheng.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string give_map(object me);
// string expell_me(object me);
int do_yes(string arg);


void create()
{
       set_name("���Ŵ�ѩ", ({ "ximen chuixue", "ximen", "chuixue" }) );

       set("long", "���Ŵ�ѩ���ǵ�����������֮һ�������Ѿ������ˣ��޽����ľ��磮��\n");
      set("faith",4000);
       set("gender", "����");
     set("title", HIR "��÷ׯ��"NOR);
   set("class", "youxia");
       set("age", 34);
       set("attitude", "friendly");
        create_family("��������", 1, "��");
       set("per", 30);
   set("int", 30);
   set("str", 30);
   set("cps", 30);
       set("max_kee", 2000);
       set("max_gin", 1100);
       set("max_sen", 2000);
       set("force", 8000);
       set("max_force", 3000);
       set("force_factor", 160);
       set("max_mana", 3000);
       set("mana", 8000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
       set("daoxing", 2000000);
        set("eff_dx", 250000);
        set("nkgain", 400);
            set("chat_chance", 1);
        set("chat_msg", ({
            "���Ŵ�ѩ��ϥ�������������޼��ķ���\n",
   }) );

           set_skill("sword", 250);
       set_skill("force", 250);
   set_skill("wuji-force", 250);
       map_skill("force", "wuji-force");
        

        set("inquiry", ([
//     "�뿪": (: expell_me :),
//      "leave": (: expell_me :),
        "�仨��ѩ" : (: give_map :),

]) );

setup();
        carry_object("/d/youxia/obj/gsjian")->wield();
        carry_object("/d/youxia/obj/xuecloth")->wear();
}


void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="��������") {
   if (((int)ob->query("combat_exp") < 1000000 )) {
   command("say ��λ"+ RANK_D->query_respect(ob) + "���书��΢�����������Ǽ�����������Ұɡ�\n");
   return;
   }
        command("smile");
   command("say �ܺã�ԭ����λ"  + RANK_D->query_respect(ob) +"����������ͽ�ܣ��ðɣ�������������Ϊͽ��\n");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
       command("recruit " + ob->query("id") );
  ob->set("title", HIR"���Ŵ�ѩ���ڵ���"NOR);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "��Ȼ�Ѿ���������,������Ѱ���˰ɣ�\n");
        return;
}
/*
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="��������") {
                command("say ����ǲ�������������Ϊʦȴ�м��仰˵��");
                me->set_temp("betray", 1);
     command("say �����䲻����ʽ�����ɣ������й������������棡");
                return ("����Ҫ��ȥ��ȴ���ܱ������ĳͷ������Ը��(agree)?");
        }
        return ("��ׯ����֪��");
}
*/
void init()
{
      ::init();
//      re_rank(this_player())
//       add_action("do_agree", "agree");
      add_action("do_fuming","fuming");
      add_action("do_yes", "yes");
}


/*
int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
     this_player()->add("betray/count", 1);
     this_player()->add("betray/youxia", 1);
                command("say ����������֮���ݲ����㣬��������ȥ�ɣ�");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
this_player()->set("combat_exp", this_player()->query("daoxing")*80/100);
                this_player()->delete_skill("piaoxiang");
                this_player()->delete_skill("wuji-force");
                this_player()->delete_skill("tianjijue");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
             this_player()->set("faith",0);
     this_player()->save();
                command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
                return 1;
                }
        return 0;
}

*/
string give_map(object me)
{
        me=this_player();
        me->set_temp("need_map", 1);
        return "����������ڴˣ�"HIW"���仨��ѩ��"HIC"���ұ����书�ľ���,����Ҫ��(yes)��"NOR"\n";
}


int do_yes(string arg)
{
        object me;

        me=this_player();
        
        if(me->query_temp("need_map")) 
        {
                message_vision("$N�������Ҫ��\n\n", me);

               if(me->query("family/family_name") != "��������" )
                return notify_fail("���Ŵ�ѩ˵������ƭ�����ɵ��ؼ���û�ţ�\n");

                if( query("no_map") == 0 )
                {
                        message_vision("���Ŵ�ѩ˵�����ã����Ҹ����Ȿ�ؼ��ɣ�\n", me);
                        me->set_temp("need_map", 0);

                        carry_object("/d/youxia/obj/xinfa");
                        command("give book to " + me->query("id"));
                        set("no_map", 1);
                        call_out("regenerate", 480);
                }
                else
                {
                        message_vision("���Ŵ�ѩ˵�����ұ��������һ���ģ����Ǹղű���Ҫ���ˡ�\n", me);
                }

                return 1;
        }
        return 0;
}

int regenerate()
{
        set("no_map", 0);
        return 1;
}


