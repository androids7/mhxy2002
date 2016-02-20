//jiz
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( (int)me->query("force") < 300 )     
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 150 )
		return notify_fail("你的气血不足。\n");
	if( (int)me->query("sen") < 150 )
		return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("zhuanlong-force",1);

	if ( skill>=250 ) skill=250;

        me->add("force", -300);
        me->receive_damage("kee", 130);
	me->receive_damage("sen", 130);

        message_vision(
HIC"$N凝神运气，大喝一声，血肉之躯竟化为一条张牙舞爪的苍龙，端地杀气逼人。\n"NOR, me);

        me->add_temp("apply/armor", skill/5);
	me->add_temp("apply/damage", skill/5);
	me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/strength", skill/5);

        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :),skill);

        if( me->is_fighting() ) me->start_busy(5);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/strength", -amount);
        me->delete_temp("powerup");
        tell_object(me, "你的转龙呼吸法运行一周天，身体复原了。\n");
	return;
}

