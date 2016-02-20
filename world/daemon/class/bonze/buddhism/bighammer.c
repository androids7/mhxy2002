//By tianlin@mhxy for 2002.1.17

// bighammer.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
       string str;//谣言的变量
	int success_adj, damage_adj;

	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要用大力降魔杵打谁？\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("你无法集中精力，别砸中自己了！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("好象没反应，再来一次吧！\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "$N"NOR+HIC"口中念了几句咒文，半空中现出阿傩，迦叶二尊者，各人手执\n一根巨大无比的降魔杵，呼！地一声向$n"NOR+HIC"当头砸下！\n" NOR,
			//initial message
		HIC "结果压个正着，差点没把$n"NOR+HIC"压扁！\n" NOR, 
			//success message
		HIC "但是$n"NOR+HIC"在千钧一发之际躲了开来。\n" NOR, 
			//fail message
		HIC "但是降魔杵被$n"NOR+HIC"以法力一引，反而砸到了$N"NOR+HIC"的顶门！\n" NOR, 
			//backfire initial message
		HIC "结果砸个正着，差点没把$n"NOR+HIC"砸扁！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=HIG+target->name()+HIM"被"HIR+me->name()+HIM"用"HIY"佛家"HIM"绝学"HIW"“大力降魔杵”"NOR+HIM"送去了阎罗地府！";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
	me->start_busy(1+random(2));
	return 3+random(5);
}

