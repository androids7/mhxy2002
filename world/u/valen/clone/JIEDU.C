
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ�ɣ�����ܴ�ָ�们�䣡\n");
    set("no_give","��ô���Ķ��������������ˣ�\n");
    set("no_drop","��ô����Ķ��������˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
}

void create()
{
  set_name( HIW "�����" NOR , ({"jiedu dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�ݴ��ı���ܣ����滹��һ��ӣ�ң���΢���ŵ�Щ��������\n");
    set("value", 500000);
    set("drug_type", "��Ʒ");
  }
  setup();
}


int do_eat(string arg)
{
        object me=this_player();

        if(! arg || arg!="sanhua gao")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }

        if (time() - me->query_temp("last_eat/sanhua") < 100)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }



        if ( !(me->query_condition("eyeill")) )
         {
                write("��û�е÷�ɳ�ۣ��������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/sanhua", time());

        message_vision(HIW "$N" HIW "����һƬ" + name() +HIW "֮���۾�������ˡ�\n" NOR, me);

        me->apply_condition("eyeill", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}