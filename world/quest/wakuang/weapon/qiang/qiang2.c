#include <weapon.h>

inherit SPEAR;
inherit F_UNIQUE;
void create()
{
        set_name("铁枪", ({ "tie qiang", "qiang", "spear" }) );
        set_weight(10000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是把又长又轻的铁枪，剑身上隐隐的透出白光，当真锋利无比。\n");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("material", "blacksteel");
                set("weapon_prop/dodge", 2);
                set("treasure",1);
                set("wield_msg", "只听见「嗡」地一声，白光顿现，$N将腰间解下的$n抖得笔直。\n");
                set("unequip_msg", "$N将手中的$n插入腰间。\n");
}
        init_spear(30);
        setup();
}