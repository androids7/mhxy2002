//血海飘香
// by redrain
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「血海飘香」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
		
	if( (int)me->query_skill("huaxue-blade", 1) < 60 )
		return notify_fail("你的刀法不够娴熟。\n");
	                        
           if (me->query_temp("piao_busy")) 
                        return notify_fail("你刚用完这招，再用会有危险!\n");

	if( (int)me->query_skill("zhuanlong-force", 1) < 60 )
		return notify_fail("你的内功修为不够高。\n");
			
	if( (int)me->query("force") < 1000 )
		return notify_fail("你现在内力太弱，不能使用「血海飘香」。\n");
			
       msg = HIC "\n$N一声清啸，气运丹田，围绕$n疾转，手中"+ weapon->name() +HIC"闪出无数血红的刀光!\n        
"HIR"$n顿觉四周眼花缭乱，仿佛置身于重重血海之中......"NOR"
"HIC"却见$N突然身形一顿，人刀合一，带着一丝淡淡的血光，穿向$n......\n"NOR;        
	if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
	damage = (int)me->query_skill("huaxue-blade", 1) + me->query("force_factor");
		target->receive_damage("kee", damage*3/2+random(100));
		target->receive_wound("kee", damage/4);
		 msg += HIM"\n$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！\n"NOR;
                message_vision(msg,me,target);
                me->add("force", -250 - me->query("force_factor"));
		COMBAT_D->report_status(target);

	} else 
	{
		msg += HIM"\n可是$n猛地向边上一跃,跳出了$N的攻击范围。\n"NOR;
                message_vision(msg,me,target);
		me->add("force", -150 - me->query("force_factor"));
                me->start_busy(2);
	}

	if(userp(target)) target->fight_ob(me);
 me->set_temp("piao_busy",1);
 call_out("remove_effect",5+random(5),me);
	return 1;
}
void remove_effect(object me) {
 string msg;
  if (!me) return;
  me->delete_temp("piao_busy");
}