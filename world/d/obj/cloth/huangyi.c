// linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("��ɫС��", ({"yellow cloth", "cloth"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 100);
		set("armor_prop/armor", 5);

        }
        setup();
}

