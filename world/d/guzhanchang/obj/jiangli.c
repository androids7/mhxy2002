// lingzhi.c 千年朱果
//星星(lywin)2000/4/22
//By tianlin@Mhxy for 2002.1.27.加物件限制

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"奖励丹"NOR, ({"jiangli dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个武林人士梦寐以求的奖励丹，据说吃一棵可得5000武学。\n");
                set("value", 10000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        if (this_player()->query("tianlin-jiangli") >=1 )
        return notify_fail("嘿嘿嘿别做梦了！\n");

        this_player()->add("combat_exp", 5000);
        message_vision("$N吃下一个奖励丹，只觉得自己变利害了一些 !\n", this_player());
        this_player()->add("tianlin-jiangli",1);
        destruct(this_object());
        return 1;
}


