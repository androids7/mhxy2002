//By tianlin@mhxy 2001.8.16.制作
//希望大家不要改作者的名字,谢谢!
//我还做了点,小小的介绍,比如说函数的意思类.....(说的可能不大明白)
//因为我的文化水平也不高,请见量By tianlin@mhxy
//我的E-Mail: tianlin-mhxy@163.com

#include <ansi.h>
inherit SSERVER;
#include "/u/tianlin/eff_msg.h";

int perform(object me, object target)
{               
        string str;//谣言的变量
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )//这句话的意思是防止在地府连续死亡!
                return notify_fail(""HIR"「"NOR+HIR"摧心"NOR+HIC"夺命"NOR+HIR"」"NOR"只能在战斗中使用。\n");
        if( (int)me->query_skill("cuixin-zhang", 1) < 100 ||
           (int)me->query_skill("unarmed", 1) < 100 )
                return notify_fail("你有的功夫还不够娴熟，不会使用"HIR"「"NOR+HIR"摧心"NOR+HIC"夺命"NOR+HIR"」"NOR"。\n");

        if((int)me->query_skill("ningxie-force", 1) <130)
return notify_fail("以你现在的内功修为还使不出"HIR"「"NOR+HIR"摧心"NOR+HIC"夺命"NOR+HIR"」"NOR"。\n");

        if((int)me->query_skill("force", 1) <130)
return notify_fail("以你现在的内功修为还使不出"HIR"「"NOR+HIR"摧心"NOR+HIC"夺命"NOR+HIR"」"NOR"。\n");
        if (me->query_skill_mapped("unarmed") != "cuixin-zhang")
return notify_fail("以你现在的内功修为还使不出"HIR"「"NOR+HIR"摧心"NOR+HIC"夺命"NOR+HIR"」"NOR"。\n");
        if( (int)me->query("max_force") < 1200 )
return notify_fail("以你现在的内功修为还使不出"HIR"「"NOR+HIR"摧心"NOR+HIC"夺命"NOR+HIR"」"NOR"。\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("你的真气不够！\n");
       msg = HIR "\n\n$N两掌发完之后,只听见"BLINK+HIW"“碰”"NOR+HIR"的一声，又是一掌击向$n的胸口！！\n" NOR;
message_vision(HIW"\n$N突然面无表情，一个侧身就向$n攻了几掌,好像是几个字！\n"NOR,me,target);
message_vision(HIC"\n¤"NOR+BLINK+HIW"摧"NOR+HIC"¤\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"\n¤"NOR+BLINK+HIR"心"NOR+HIC"¤\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"\n¤"NOR+BLINK+HIW"夺"NOR+HIC"¤\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"\n¤"NOR+BLINK+HIR"命"NOR+HIC"¤\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"被"+me->name()+"用大雪山绝招[1;37m「摧心夺命」[2;37;0m[1;35m左一掌.右一掌.给活活的培烂了. 可真是惨啊！";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
if (me->query("combat_exp") > target->query("combat_exp")/4)
        {
                me->start_busy(1);
                target->start_busy(3);//我给对手加大了一下busy时间
                damage = (int)me->query_skill("cuixin-zhang", 1);
                damage = damage + random(damage/2);
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("cuixin-zhang", 1) > 119)//摧心掌大于119级才能使出第二套掌法
               target->set_temp("last_damage_from", me);
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
        } else //或者砸不上的话,执行下面的文件
        {       me->start_busy(3);
                me->add("force", 600);//特意设成加内力                
                msg += HIY"可是$p伏地一滚，躲开了对手的攻击。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}


int perform2(object me, object target)
{
        int damage, p,skill;
        string msg,weapon;
        weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("你休息一会,待要再出第二击，却发现自己的内力不够了！\n");     
        msg = HIB "\n三招后$N来了一个空翻,绕道$n的背后，接着 :"BLINK+HIC"地嘞破隆"NOR+HIB",就是一顿!!\n" NOR;
message_vision(HIY"\n$N发现了$n的破绽，紧跟着，连续向$n攻出了三招！\n"NOR,me,target);
message_vision(HIR"\n第"NOR+BLINK+HIW"一"NOR+HIR"招\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
message_vision(HIR"\n第"NOR+BLINK+HIW"二"NOR+HIR"招\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
message_vision(HIR"\n第"NOR+BLINK+HIW"三"NOR+HIR"招\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        message_vision(msg, me, target); 
if (me->query("combat_exp") > target->query("combat_exp")/4)
        {
       msg = HIR "$N左手一收一放,反手之间,就是一掌,哎呀真是要命!!!\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("cuixin-zhang", 1);
                damage = damage+(int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage*3/2);
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("cuixin-zhang", 1) > 180)
             remove_call_out("perform3");
                call_out("perform3", 1, me, target);    
        } else 
        {       me->start_busy(2);
                me->add("force", -200);                
                msg += HIY"可是$p突然袭击，料敌之先,非但躲开对手攻击,$N反而搞了个手忙脚乱。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform3(object me, object target)
{
        int damage, p,skill;
        string msg,weapon;
        weapon = me->query_temp("weapon");  
        if(!living(target)) 
                return notify_fail("对手已经不能再战斗了。\n");
        if( (int)me->query("force", 1) < 1300 )
                return notify_fail("你待要再出第三击，却发现自己的内力不够了！\n");     
        msg = HBBLU+HIY "\n没有想到$N气韵丹田,$N双手一并，用尽全身的内力和真气发出了一掌!\n" NOR;
message_vision(MAG"\n只听见"NOR+BLINK+CYN"咚"NOR+MAG"的一声,$n挨了$N一巴! 惨\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/2))
        {
       msg = CYN "$n慌乱中已经躲闪不及,$N得理不侥人,抢前就是一拳\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("cuixin-zhang", 1);
                damage = damage+(int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage*3/2);
                target->receive_damage("kee", damage*2,me);
                target->receive_wound("kee", damage,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        } else 
        {       me->start_busy(2);
                me->add("force", -50);                
                msg += HIY"可是$p突然袭击，料敌之先,非但躲开对手攻击,$N反而搞了个手忙脚乱。\n"NOR;
        message_vision(msg, me, target);
        }
        return 1;
}
