//by tianlin 2001.7.28
#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + "坐下来运功疗伤，浑身笼起一团"HIY"金光"NOR HIW"，不久，吐出一口"HIR"瘀血"NOR HIW"，脸色看起来好多了。\n" NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/10 );
        me->add("force", -50);

        return 1;
}

