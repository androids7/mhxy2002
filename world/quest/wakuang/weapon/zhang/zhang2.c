#include <weapon.h>

inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name("铁杖", ({ "tie zhang", "zhang", "staff" }) );
        set_weight(10000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是一柄黑黝黝的铁杖\n");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("material", "blacksteel");
                set("weapon_prop/dodge", 2);
                set("treasure",1);
                set("wield_msg", "$N将$n抖得笔直。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
}
        init_staff(30);
        setup();
}