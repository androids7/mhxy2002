//Cracked by Roath

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
                set_name(HIC"��ڴ�"NOR, ({"feng kou dai" , "koudai" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                        set("long", "������װ���õĴ�ڴ���\n");
                      set("unit", "��");
                       set("owner_name","����");
                     set("owner_id","feng po");
        }
}