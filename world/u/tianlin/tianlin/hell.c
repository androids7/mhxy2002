// hell.c 功夫丸

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "功夫丸" NOR, ({ "wan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗神奇的药丸，传说可以增加skills。\n");
                set("value", 0);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
       
                tell_object(me, HIG "你的skills已经提升了，"
                            "请先jifa上你的skills，然后再问巫师要dan。祝你西行快乐！\n" NOR);
                            me->set_skill("dodge",100);
                            me->set_skill("force",100);
                            me->set_skill("ghost-steps",100);
                            me->set_skill("gouhunshu",100);
                            me->set_skill("hellfire-whip",100);
                            me->set_skill("jinghun-zhang",100);
                            me->set_skill("kusang-bang",100);
                            me->set_skill("spells",100);
                            me->set_skill("unarmed",100);
                            me->set_skill("literate",100);                            
                            me->set_skill("parry",100); 
                            me->set_skill("tonsillit",100);
                             me->set_skill("zhuihun-sword",100);
                            me->set_skill("stick",100);
                            me->set_skill("zhuihun-sword",100);
                            me->set_skill("whip",120);
                                                 me->set_skill("sword",100);

       destruct(this_object());
	return 1;
}

