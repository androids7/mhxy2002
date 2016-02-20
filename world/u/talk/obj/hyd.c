// huanyang.c 还阳丹

#include <ansi.h>

inherit ITEM;

int do_eat(string);
create();
/*
create()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                set("no_drop","这么宝贵的还阳丹，哪能乱扔! \n");
        }
                                              
        add_action("do_eat", "eat");
}
*/
void create()
{
        set_name(HIG "还阳丹" NOR, ({"huanyang dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "一粒还阳丹，据说有起死回生之效。\n");
                set("value", 100000);
        }

        set("is_monitored", 1);
  
     setup();
}
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
            "落在地上，不见了。\n");
    destruct(me);
}
void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
            who->query("name")+"在"HIW+
                        MISC_D->find_place(environment(this_player()))+HIM"得到了传说中的"+name()+HIM"！\n");
}

void init()
{        add_action("do_eat", "eat");
    call_out("self_dest",1+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}


int do_eat(string arg)
{
        object victim = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");
if(this_player()->query("huanyang") < 0 )
{
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                victim->add("potential",
                        (int)victim->query("potential") - (int)victim->query("learned_points") );
        victim->skill_death_recover();

   victim->add("daoxing",victim->query("death/dx_loss"));
        victim->add("huanyang",1);
             victim->save();

        if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );

       message_vision(HIG "\n$N吃下一粒还阳丹，硬是从白无常那里逃脱，捡回了一条小命。\n\n" NOR, victim);

 //       destruct(this_object());
//        return 0;
}else{      message_vision(HIG "\n$N吃下一粒还阳丹，硬是从白无常那里逃脱，捡回了一条小命，可惜是假的。\n\n" NOR, victim);
}
        destruct(this_object());
        return 1;

}

