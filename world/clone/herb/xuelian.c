// xuelian.c

#include "herb.h"

void create()
{
	set_name(HIW "ѩ��" NOR, ({ "xuelian", "herb_xuelian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 30000);
        	set("weight", 40);
set("base_unit","��");
	}
	setup();
}
