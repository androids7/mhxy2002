//[4;53m[1;31mBy tianlin@mhxy for 2001.10.1[2;37;0m
//八月十五制作
#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE; 

inherit WHIP;

void create()
{
        set_name(HBRED+HIW"白骨鞭"NOR, ({"baigu whip", "whip", "bian", "baigu"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {

        set("long","这是一条用白骨织起来的一个鞭子。\n");
        set("unit", "条");
        set("replace_file", "/d/obj/weapon/whip/pibian");
        set("value", 120000);
        set("no_sell", 1);
	 set("no_break", 1);
        set("armor_prop/spells", 25);
        set("armor_prop/armor", 20);
        set("armor_prop/intelligence", 10);
	 set("wield_msg", HIW"$N左手轻扬，一条白色的白骨鞭突然眉飞色舞.\n"NOR);
	 set("unwield_msg", HIY"$N把手中$n[1;33m缠回腰间．\n"NOR);
	 set("weapon_prop/courage", 5);
        }
        init_whip(140);
        set("is_monitored",1);
        set("rumor_msg",1);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = (int) victim->query_temp("apply/armor_vs_fire");
        dam = (int) me->query("force");
        if(dam > pro)
        {
        victim->receive_wound("kee",100);
        victim->receive_wound("sen",100);
        return HBRED+HIW"白骨鞭"NOR+HBBLU+HIY"突然发出一道刺眼的光芒,直刺"NOR+BLINK+HIW"『$n[1;37m』"NOR+HBBLU+HIY"的双眼。\n" NOR;
        }
}
