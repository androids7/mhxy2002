// changjian.c 长剑

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
    set_name(HIW "仙人剑" NOR, ({"sword", "jian"}));
    set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
        set("long", "这是一柄极锋利的长剑。\n");
        set("value", 1);
                set("material", "purplegold");
                set("sheenness", 35);
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
    init_sword(88);
        setup();
}

