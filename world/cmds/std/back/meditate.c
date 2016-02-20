//By tianlin@mhxy for 2002.1.17

#include <skill.h>

inherit F_CLEAN_UP;

int finish(object me, int sen_cost);

int main(object me, string arg)
{
        int sen_cost, busy_time;

        seteuid(getuid());
        
        if(environment(me)->query("no_fight") || 
           environment(me)->query("no_magic") )
              return notify_fail("安全区内禁止练功。\n");
                        
        if (me->is_busy() || me->query_temp("pending/meditating"))
                return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能冥思。\n");

	if( !stringp(me->query_skill_mapped("spells")) )
		return notify_fail("你必须先用 enable 选择你要用的法术。\n");

        if( !arg
        ||      !sscanf(arg, "%d", sen_cost) )
                return notify_fail("你要花多少精神冥思？\n");
        if( sen_cost < 10 ) return notify_fail("你最少要花 10点「神」才能冥思。\n");

      if( (int)me->query("sen") < sen_cost )
                return notify_fail("你现在神智不清,不能再想入非非了。\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
                return notify_fail("你现在身体状况太差了，无法集中精神！\n");

        me->set_temp("pending/respirate", 1);
        write("你盘膝而坐，静坐冥思了一会儿。\n");

        me->receive_damage("sen", sen_cost);
        if(busy_time<0) busy_time=0;
        me->start_busy(1);

        call_out("finish", 1, me, sen_cost);
        return 1;
}

int finish(object me, int sen_cost)
{
        int mana_gain;

        // This function ranged from 1 to 15 when sen_cost = 30
        mana_gain = sen_cost * ((int)me->query_skill("spells") / 15 + (int)me->query_spi() ) / 30;
        me->set_temp("pending/respirate", 0);
        if( mana_gain < 1 ) {
                tell_object(me, "但是当你睁开眼睛，只觉得脑中一片空白。\n");
            me->start_busy(1);
                return 1;
        }

        me->add("mana", mana_gain );
        tell_object(me, "你行功完毕，从冥思中回过神来。\n");

                if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
                        if( (int)me->query("max_mana") >=
              (int)me->query_max_mana() ) {
                        tell_object(me, "当你的法力增加的瞬间你忽然觉得脑中一片混乱，似乎法力的提升已经到了瓶颈。\n");
                } 
                else {
                                tell_object(me, "你的法力增强了！\n");
                                me->add("max_mana", 1);
if ( (int)me->query("max_mana") > (int)me->query("maximum_mana"))
me->set("maximum_mana", (int)me->query("max_mana"));
                        }
                        me->set("mana", me->query("max_mana"));
                }

          me->start_busy(1);
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : meditate|mingsi [<耗费「神」的量，预设值 30>]
 
静坐冥思，将游离的精神力有效地集中凝聚成能够用来施展法术的能量
，藉以增加自己的法力。

请参考 help stat 
HELP
        );
        return 1;
}

