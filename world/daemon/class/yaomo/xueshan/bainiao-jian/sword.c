// 百鸟朝凤
//大雪山嘲讽我觉着应该分为两种,一种是男性使用,而另一种则是女性使用,这样一来,对以前老玩家来说比较好,
//有的老玩家非常喜欢掉上限的那一种嘲讽,有的也喜欢不掉上限的那一种,我现在给改成,男性的掉上限,女性
//的嘲讽朝上以后busy大,我觉着这样公平点.我给把颜色做了一下修改,改的还行,还请高手做一下修改就行了.
//by tianlin 2001.5.1
/*
requirement: sword+bainiao_jian+throwing >80 藏了暗器的剑中可发暗器
                                         >150 剑气伤人
damage : 发出暗器/剑气   1. random 发出1--10股
         命中几率      (me->a)/(target->d)*0.3
         伤害:         银针: 20+me->query_temp("apply/damage") 
	               毒针: <崭缺>	
                       孔雀翎: 50+me->query_temp("apply/damage") 
                       剑气: me->query("force_factor")
		       剑气+暗器 : 伤害累加
          自己内力 - me->query("force_factor")
(haven't done :P)
只见你手中风雪剑急颤，幻出满天剑芒，无数0加着剑气有如百鸟投林般向小萝卜扑来！
*/
//by tianlin 2001.6.6
//我给修改了一下，还加上chaofeng出rumor,这是在我玩KOF时突发其想(snicker)!
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;

        string msg;
        string str;//加上rumor的变量
        int ii,req,num_anqi,num_hit,max_hit,hitt,damage,op,opfa,remain;
        string anqi_type,b_unit;
//added by beeby 2000.6.20
        int t;
//end add

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("你要对谁施展这一招"HIY"「百鸟朝凤」"NOR"?\n");
   /*     if( (string)me->query("gender") != "女性" )//本来想设成一个是男的使用的一个是女的使用的。可是。。。
  return notify_fail("这一招百鸟朝凤是女子使用的,请用男子的朝凤。\n"); */
        if(!me->is_fighting())
                return notify_fail(""HIY"「百鸟朝凤」"NOR"只能在战斗中使用！\n");

      weapon = me->query_temp("weapon");
      req=(int)me->query_skill("sword", 1)+(int)me->query_skill("bainiao-jian", 1)+(int)me->query_skill("throwing", 1); 


      if (weapon)  
        {
        if (weapon->query("anqi/allow") != 1) num_anqi=0;
        else num_anqi=weapon->query("anqi/now");
        }

      if (me->query_skill_mapped("force")!="ningxie-force")
                return notify_fail("百鸟朝凤必须配合冰谷凝血功才能使用。\n");
      if(req < 80)
            return notify_fail("你剑中打暗器的功夫还不到火候！\n");
      if(req < 150 && weapon->query("anqi/now") ==0)
            return notify_fail("你剑中没有暗器可打！\n");
       if (me->query("force")<200)
           return notify_fail("你内力不继，难以御剑飞针。\n");
//Added by Beeby 2000.6.20
// 给百鸟剑加上busy,不能连发了
 	if ( ((t=(int)me->query_temp("chaofeng_time")) <= time() )
	    && (time()<t+5) )
         {  
            return notify_fail(""HIY"百鸟朝风"NOR"多使就不灵了。\n");
         }
        else me->delete_temp("chaofeng_time") ;
        me->add("force", -60);

        if(num_anqi <=0) 
           { anqi_type="剑气"; damage=me->query("force_factor")+10; }
        else if (req < 150)
           { anqi_type=weapon->query("anqi/type"); damage=me->query_temp("apply/damage");}
        else 
           { anqi_type=weapon->query("anqi/type")+"加着剑气";
             damage=me->query_temp("apply/damage")+me->query("force_factor")+10;}
         
        msg = MAG"只见$N手中[1;33m"+weapon->query("name")+MAG"[2;37;0m[35m急颤，幻出满天剑芒，无数[2;37;0m[37m"
                 +anqi_type+MAG"有如百鸟投林般向$n扑来！\n" NOR;

        if (num_anqi > 10 || num_anqi == 0) max_hit=10;
        else max_hit=weapon->query("anqi/now");
        num_hit=random(max_hit)+1;
        if (!target->is_fighting(me)) opfa=30;
        else opfa=15;
        if (target->query("combat_exp")  !=0 ) 
               op= me->query("combat_exp")*opfa/target->query("combat_exp");
        else op=10;
        hitt=0;	
        for (ii=1;ii<=num_hit;ii++)  
          {if (op > random(100)) hitt++;}


        if (weapon->query("anqi/type")=="孔雀翎") b_unit="支";
        else b_unit="根";
        if (weapon->query("anqi/now") != 0) remain=weapon->query("anqi/now")-num_hit;
        else remain=0;
        weapon->set("anqi/now",remain);
        if (weapon->query("anqi/now") == 0) 
          {weapon->delete("anqi/type");  weapon->set("long",weapon->query("orilong"));}
        else weapon->set("long",weapon->query("orilong")+"里面已经装了"
           +chinese_number(weapon->query("anqi/now"))+b_unit+weapon->query("anqi/type")+"，想拆掉用uninstall。\n"); 

        if (hitt==0)
	  {
           msg += HIW "$n连忙身行一转，连退数步，闪过了这满天花雨般的一击。\n"NOR;
           message_vision(msg, me, target);
              me->start_busy(1+random(0));
	  }
        else 
          {
	   damage=damage*hitt;
           target->receive_damage("kee",damage,me);
           msg += HIG "$n躲闪不及，身上"+chinese_number(hitt)+HIG "处中了[2;37;0m[37m"+anqi_type+"！\n"NOR;
           message_vision(msg, me, target);
           COMBAT_D->report_status(target); 
           if(!target->is_busy())
	       target->start_busy(8+random(8));//加大busy
           me->set_temp("chaofeng_time",time());
           }
        msg = HIB "$n对着$N高声骂道：好啊，敢放暗器，看我怎么收拾你！\n" NOR;     
        message_vision(msg, me, target);
        target->kill_ob(me);//去掉这个使得这个朝凤更加好用,fight中使用不等于下kill指令,以前等于.(xixi)
//By tianlin@mhxy 2001.6.6
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"被"+me->name()+"用"HIW"大雪山"NOR HIM"绝招[1;37m「百鸟朝凤」[2;37;0m[1;35m杀死了。身上"BLINK HIC""+chinese_number(hitt)+""NOR HIM"处中了"HIY""+anqi_type+""NOR HIM",尸体好像个马蜂窝！";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
        return 1;
}

