//By tianlin@mhxy for 2001.12.4修改
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{      
       string str;//谣言的变量
	string msg;
	int extra;
       int urkee;
	object weapon;
       urkee=me->query("eff_kee");                 
	extra = me->query_skill("duo-sword",1);
	if ( extra < 210) return notify_fail("你的夺命剑法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIB"［夺命连环十五剑］"NOR+YEL"只能对战斗中的对手使用。\n"NOR);
	weapon = me->query_temp("weapon");
        if((int)me->query_skill("cloudforce", 1) <200)
return notify_fail("你的心法还不够纯熟！\n");
        message_vision(HIR"$N轻描淡写，挥尘如意，一瞬间就已使出夺命十三式.\n只见$N手中的"+ weapon->name()+ HIR "轻灵流动，就像是河水般的向$n刺出第"BLINK+HIC"一"NOR+HIR"剑!\n\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIW"二"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIC"三"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIB"四"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIY"五"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIG"六"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        message_vision(HIR"------>>>>>>第"HIC"七"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIY"八"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIB"九"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIC"十"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIW"十一"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIM"十二"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIC"十三"HIR"剑<<<<<<------" NOR,me,target);
        message_vision(CYN"\n$N的第十三剑刺出后，所有的变化都似已穷尽，又像是流水已到尽头，剑势也慢了，很慢。\n\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"虽然慢，却还是在变，$N忽然一剑挥出，不著边际，不成章法。"NOR,me,target);
        message_vision(HIC"\n但是这一剑却像是画龙点晴，虽然空，却是所有转变的枢纽。"NOR,me,target);
        message_vision(HIR"\n然后$N就刺出了夺命十三剑的"HIY"第"HIB"十四"HIY"剑"HIR"-------------------------------------------
\n\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   
        message_vision(CYN "$N的这一剑刺出，所有的变化已到了穷尽，本已到了尽头的流水，现在就像是已完全枯竭。
$N的力也已将竭了。可是就在这时候，$N手中的剑忽然又起了奇异的震动,天地万物忽然全都静止，
绝对静止，没有变化，没有生机!这一剑带来的，只有死!只有"NOR+BLINK+BLU"「死」"NOR+CYN"，才是所有一切的终结，才是
真正的终结!流水乾枯，变化穷尽，生命终结，万物灭亡!这才是"NOR+BLINK+RED"「夺命十三剑」"NOR+CYN"真正的精粹!这才是
真正夺命的一剑!这一剑赫然已经是"HIR"第"BLINK+HIW"\t十\t五\t"NOR+HIR"剑"NOR+CYN"！\n\n"NOR,me,target);
  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   
if( (int)me->query("bellicosity",1) < 10000 )
  {  msg = HIB "所有的生命和力量，都已被$N这一剑夺去,$n脸上忽然露出种恐惧之极的表情。";
msg +=  "\n$N的眼睛里，忽然也露出种恐惧之极的表情，甚至远比$n更恐惧。";
msg +=  "\n然后$N就做出件任何人都想不到，任何人都无法想像的事。$N忽然回转了剑锋，割断了$N自己的咽喉。\n\n"NOR;
   message_vision(msg, me, target);
	//	me->receive_wound("kee",urkee+1000);
	//	me->receive_wound("kee",50);
              target->start_busy(3);
              me->start_busy(4);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"被"+me->name()+"用神剑山庄绝招[1;37m「夺命十五剑」[2;37;0m[1;35m给杀死了. 尸体上面无数伤痕！";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
       return 1;
  }
else
  {  msg = HIB "所有的生命和力量，都已被$N这一剑夺去,$n脸上忽然露出种恐惧之极的表情。\n\n"NOR;
    message_vision(msg, me, target);
		target->die();
	//	me->receive_wound("kee",urkee+100);
              me->start_busy(1);
       return 1;
  }
        return 1;
}
