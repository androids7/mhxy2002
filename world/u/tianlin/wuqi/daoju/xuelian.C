//By tianlin@mhxy for 2001.9.20
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIC"��ɽѩ��"NOR, ({"tianshan xuelian","tianshan","xuelian"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����ǧ�꺱����һ��ѩ����ʮ�����档\n");
    set("value", 2000000);
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_eat(string arg)
{
  int force, mana;
  object me = this_player();
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  force = (int)me->query("max_force");
  mana  = (int)me->query("max_mana");

  me->set("force",force*2);
  me->set("mana",mana*2);
  message_vision(HIY "$N����һ����ɽѩ����ֻ������ķ���ͻ���ͽ�����ǿ�����࣡ \n" NOR, me);
  
  destruct(this_object());
  return 1;
}