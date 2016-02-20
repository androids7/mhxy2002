//By tianlin@mhxy for 2002.1.10

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
#include "/u/tianlin/eff_msg.h";

int calculate_damage(object me, object target, int base_damage, int damge_bonus);
int perform(object me, object target)
{
	string msg, str;
	int mydf;
       int p;
	int ap, dp, pp;
	int youcps, mycor, mystr, youstr;
	int damage_bonus, damage, wound;
	int delay;
	object ob;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(YEL"你要对谁使用这招"HIR"「"HIC"庐山升龙霸"HIR"」"NOR+YEL"?\n"NOR);

	mydf=(int)me->query_skill("dragonfight",1);
	if(mydf<180) 
		return notify_fail("你的级别不够,是不出庐山升龙霸。\n");
	mydf=(int)me->query_skill("dragonforce",1);
	if(mydf<180) 
		return notify_fail("你的级别不够,是不出庐山升龙霸。\n");
	
	if((int)me->query("force")<500) return
	    notify_fail("你的内力不够了。\n");

	mycor=me->query_cor();
	youcps=target->query_cps();
	ap=COMBAT_D->skill_power(me, "unarmed", SKILL_USAGE_ATTACK);
	dp=COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_DEFENSE);
	dp/=2;	
	pp=COMBAT_D->skill_power(target,"unarmed", SKILL_USAGE_DEFENSE);
	pp/=2;
	if(objectp(ob)) pp/=2;
	mystr=me->query_str();
	youstr=me->query_str();
	damage_bonus=mystr*(100+me->query("force_factor"))/100;

		msg  = ""HIB"$N默运碧海神通，身法一展，竟然使出"HIC"「庐山升龙霸」"NOR+HIB"舍身扑向$n\n\n"NOR;
		msg += "$N身形一长"BLINK+HIC"「无敌龙龙」"NOR"，双臂一阵横扫，直逼$n得连连倒退！\n";
		msg += ""HIB"只听见$n的前脚「喀」地一声 ...\n" NOR;
              damage = (int)me->query_skill("dragonfight", 1);
              damage = damage + random(damage/2);
              target->receive_damage("kee", damage);
              p = (int)target->query("kee")*100/(int)target->query("max_kee");
              msg += "( $n"+eff_status_msg(p)+" )\n";   
              msg+="$N身形一长，朝$n劈面就是一拳。这招"HIG"「苍龙出海」"NOR"势若奔雷，锐利无比！\n" NOR;
	       msg += HIB"$N劲力一吐，$n的头部发出「喀」地一声爆响！\n"NOR;
              damage = (int)me->query_skill("dragonfight", 1);
              damage = damage + random(damage/3);
              target->receive_damage("kee", damage);
              p = (int)target->query("kee")*100/(int)target->query("max_kee");
              msg += "( $n"+eff_status_msg(p)+" )\n";     
		msg += "$N似退反进，突然欺身向前，五指如钩，一招"HIW"「潜龙勿用」"NOR"，对准$n的头部一把抓了过去！\n";
		msg += HIB"$N劲力一吐，$n的头部发出「喀」地一声爆响！\n"NOR;
              damage = (int)me->query_skill("dragonfight", 1);
              damage = damage + random(damage/2);
              target->receive_damage("kee", damage);
              target->receive_wound("kee", damage/2);               
	       p = (int)target->query("kee")*100/(int)target->query("max_kee");
              msg += "( $n"+eff_status_msg(p)+" )\n";     	
              message_vision(msg, me, target);
              message_vision(HIC"$N大喝一声『升龙』，三条神龙自九天而起，直飞$n！\n"NOR,me,target);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=me->name()+"竟然使出了东海秘传的[1;36m「庐山升龙霸」[2;37;0m[1;35m，[1;35m看来又有人死在这种霸道的拳术之下。";
	                message("channel:rumor",HIM"\n\n【谣言】某人："+str+"\n"NOR,users());
	               }
	me->start_busy(2+random(2));
	me->add("force", -100);

	return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

	damage=base_damage+(damage_bonus+random(damage_bonus))/2;
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
		damage-=damage/3;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));

	return damage;
}


