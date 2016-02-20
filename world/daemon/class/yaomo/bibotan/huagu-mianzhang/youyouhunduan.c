// By tianlin 2001.5.1
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("huagu-mianzhang",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「幽幽魂断」只能在战斗中使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「幽幽魂断」只能空手使用。\n");		
       
	 if( (int)me->query("force") < 700 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("force",1) < 110 )
                return notify_fail("你的内功修为不够，无法使用「幽幽魂断」！\n");
	
	weapon = me->query_temp("weapon");

        msg = HIW "$N身形回转，怒吼一声，同时使出化骨绵掌中的精髓，一招"NOR+BLINK"[1;30m『幽幽魂断』"NOR+HIW"连续攻向$n！" NOR;
        	         message_vision(msg, me, target);                
	 msg =  HIW  "藏离诀！" NOR;
        message_vision(msg, me, target);
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "摧肠诀！" NOR;
        message_vision(msg, me, target);
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "精失诀！" NOR;
        message_vision(msg, me, target);
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "三焦诀！" NOR;
        message_vision(msg, me, target);
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "伤肺诀！" NOR;
        message_vision(msg, me, target);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "损心诀！" NOR;
        message_vision(msg, me, target);
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "意恍惚诀！" NOR;
        message_vision(msg, me, target);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("force", -700);
        me->start_busy(3);

        return 1;
}

