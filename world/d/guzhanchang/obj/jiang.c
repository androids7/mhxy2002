// huanyang.c 还阳丹
//By tianlin@Mhxy for 2002.1.27.加物件限制

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                set("no_drop","这么宝贵的还阳丹，哪能乱扔! \n");
        }
                                              
        add_action("do_eat", "eat");
}

void create()
{
        set_name(WHT "还阳丹" NOR, ({"huanyang dan", "dan"}));
        set_weight(20);        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", WHT"一粒还阳丹，据说有起死回生之效。\n"NOR);
                set("value", 2000000);
        }

        set("is_monitored", 1);
        setup();
}

int do_eat(string arg)
{
        object victim = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        if (this_player()->query("tianlin-hyd") >=1 )
        return notify_fail("嘿嘿嘿别做梦了！\n");

        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                victim->add("potential",
                          (int)victim->query("potential") - (int)victim->query("learned_points") );        victim->skill_death_recover();

   victim->add("daoxing",victim->query("death/dx_loss"));
        victim->save();

        if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );

       message_vision(HIG "\n$N吃下一粒还阳丹，硬是从白无常那里逃脱，捡回了一条小命。\n\n" NOR, victim);
        this_player()->add("tianlin-hyd",1);
        destruct(this_object());
        return 1;
}