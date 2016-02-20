//by ephq

#include <ansi.h>
#include <dianxue.h>
inherit SSERVER;
int perform(object me, object target)
{
	string attack_skill,msg;
	int extra, dif, ap, dp, ap1, dp1, pp, app,dpp,t;
	object weapon;
	mapping data;

	extra = me->query_skill("dianxue",1) ;

	if ( extra < 150) return notify_fail("你的[点穴]还不够纯熟，还认不准死穴！\n");
		
        
	if( !target ) target = offensive_target(me);
	if( !target
	||!target->is_character() )
// 	|| target->is_fighting(me))
		return notify_fail("你要点谁的穴。\n");

        if( target->is_busy() ) 
		return notify_fail("对方正忙着呢，何必乘人之危呢？\n");
		        
        if((int)me->query("force") < 150 ) return notify_fail("你的内力不足！\n");
     	if(!valid_perform(me,target)) return 0;        
               me->add("force", -100);

        me->receive_damage("sen", 50);
	
//        arg=xue[random(sizeof(xue))];
        

	data=type(me);
	if( data["type"]=="none" ) 
	return notify_fail("你所用的兵器不适合点穴。\n");

	dif=data["dif"]	;

       msg=HIC+"$N屏息凝神，";
       if( dif!=110 ) msg+="内力灌注"+me->query_temp("weapon")->name()+HIC+",";
       msg+="全神贯注的盯住$n的"+HIB"死穴，\n"+NOR+MAG+"突然，";
       if( dif!=110 ) msg+="手中"+me->query_temp("weapon")->name()+"的";
       msg+=data["action"]+"$n的"+HIB+"死穴"+NOR+MAG+data["type"]+"去。\n\n"+NOR;
       
       message_vision(msg,me,target);
       
       ap=me->query("combat_exp");
       dp=target->query("combat_exp");
       ap1=me->query_skill("force");
       dp1=target->query_skill("force");
       pp=target->query_skill("dodge")+target->query_skill("parry");
       
       app=ap1*2+extra*40;
       dpp=dp1*2+pp*10;
       if( ((random(app+dpp)*dif/100 > dpp) && random(54)>50) ||( ( random(ap+dp)>dp ) && random(40)>30 ) )
       {
       	msg=WHT+"结果，$n的死穴被一下子"+data["type"]+"中了，双眼一翻，就嗝屁了。\n"+NOR;
       message_vision(msg,me,target);	
       	target->delete_temp("last_damage_from");
	target->delete_temp("my_killer");       	
	target->set_temp("death_msg","被"+me->query("name")+"点中死穴死了。\n");
	target->die();
       }
       else {
       	msg=HIY+"但是，$n似乎早就算出你会出此一招，从容的躲开了。\n"+NOR;
       message_vision(msg,me,target);       	
       	me->start_busy(2);
//        COMBAT_D->do_attack(target,me, target->query_temp("weapon"));       	
       	}
	if( target )
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->fight_ob(target);
        }
	return 1;
}