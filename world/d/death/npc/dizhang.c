
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
#include <ansi.h>
//puti.c
inherit NPC;
inherit F_MASTER;
string avenge();
string ask_chuxian();
string ask_cancel();
string shanzijing_me();
// string master_me();
void create()
{
  set_name("�ز�������", ({"dizang pusa", "pusa"}));
  set("long", "�������񣬴�����磬һ���ྲ��
�������������ܵظ������¹���ĵز���������\n");
  set("gender", "����");
  set("class", "youling");
  set("age", 70);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("str", 30);
  set("int", 30+random(5));
  set("nkgain",790);
  set("max_kee", 3000);
  set("max_gin", 2500);
  set("max_sen", 2000);

  set("force", 3500);
  set("max_force", 2000);
  set("force_factor", 200);
  set("max_mana", 2500);
  set("mana", 2000);
  set("mana_factor", 200);

  set("combat_exp", 2000000);
  set("daoxing", 4000000);

  set_skill("stick", 180);
  set_skill("kusang-bang", 180);
  set_skill("unarmed", 180);
  set_skill("whip", 180);
  set_skill("hellfire-whip", 200);
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("literate", 150);
  set_skill("spells", 200);
  set_skill("force", 180);
  set_skill("tonsillit", 150);
  set_skill("ghost-steps", 180);
  set_skill("gouhunshu", 180);
  set_skill("jinghun-zhang", 180);
  set_skill("zhuihun-sword", 180);
  set_skill("sword", 180);

  map_skill("force", "tonsillit");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("spells", "gouhunshu");
  map_skill("parry", "hellfire-whip");
  map_skill("whip", "hellfire-whip");
   map_skill("sword", "zhuihun-sword");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "whip.three" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :),
        }) );
  set("nk_gain", 600);
set("inquiry",([
  "�л�": (: ask_chuxian :),
  "cancel": (: ask_cancel :),
  "ɽ�־�": (: shanzijing_me :),
  "shanzijing": (: shanzijing_me :),
  "������": "����Ҳ�����ң�\n",
  "renrushengong": "����Ҳ�����ң�\n",
 // "��ʦ": (: master_me :),
 //"master": (: master_me :),
//  "����": (: avenge :) 
 ]));
   
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  
  create_family("���޵ظ�", 1, "���");
  setup();
  
  carry_object("/d/obj/cloth/baipao")->wear();
  carry_object("/d/obj/weapon/whip/longsuo")->wield();
}

string avenge()
{
    object who=this_player(),killer,where;
    string killid;
    if((string)who->query("family/family_name")!="���޵ظ�")
        return ("�㲻�Ǳ��ɵ��ӣ������뱾���θɣ�");
    if(who->query("faith")<1000)
        return ("���ڱ���������������������Ŭ�����С�");
    if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
        return ("����δ����Ѷ");
    killid=who->query("kill/last_killer");
    killer=find_living(killid);
    if(!killer||!userp(killer))
        return ("��������������һ��");
    command("say �������ȥΪ�㱧��");
    who->set("avenge/mud_age",who->query("mud_age"));
    where=environment(who);
    tell_room(where,"ֻ���ز������������һָ��\n");
    tell_room(where,"����С�����ڣ���ȥ��"+killer->query("name")+"ץ����\n")
;
    tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")
+"ץ��������");
    killer->move(where);
    tell_room(where,killer->query("name")+"���ӿ�������������\n");
    command("say ������������ɱ�������޵ظ�����");
    this_object()->kill_ob(killer);
    return("��������");
}  
void attempt_apprentice(object ob, object me)
{
  if ( (string)ob->query("family/family_name")=="���޵ظ�") {
    if (((int)ob->query("combat_exp") < 350000 )) {
      command("say " + RANK_D->query_rude(ob) + "�������è�İ�ʽҲ�ҵ������ﶪ�����ۣ�");
      return;
    }
    command("grin");
    command("say �ܺã�" + RANK_D->query_respect(ob) +
       "���Ŭ�������ձض��гɡ�\n");
    command("recruit " + ob->query("id") );
    return;
  }
  command("shake");
  command("say " + RANK_D->query_respect(ob) +
     "������ȥѧЩ��������ɣ�\n");
  return;
}

string ask_chuxian()
{
  object me=this_player();
  if(me->query("family/family_name")!="���޵ظ�")
     return ("�㲻�Ǳ������ˣ�");
  
  command("smile "+me->query("id"));
  return "/d/obj/mieyao"->query_yao(me);
}
 
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}
string shanzijing_me()
{
        object me;
        me=this_player();
        if(me->query("family/family_name") != "���޵ظ�" )
        return ("��ѧ�ҵĹ���Ϊʲô����ظ��أ�");
        if (me->query("renru")!=1)
        return ("�㻹����ѧѧ�����񹦰ɣ�");
        if (me->query("shanzijing")==1)
        return ("���Ѿ����˰����в���");
        message_vision(CYN"$N�Ҹ�������..........��\n"NOR,this_object(),me);
        command("gongxi "+me->query("id"));
        me->set("shanzijing",1);
        return ("����С�����Ǿ�ѧ����Ҫ�޹����˰���");

}
