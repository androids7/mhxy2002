//长拳 changquan.c
//menpai skill(can also be used by non-menpai NPCs)

inherit SKILL;

mapping *action = ({
        ([      "action":
"只见$N身形一矮，大喝声中一个[37m「冲天炮」[2;37;0m对准$n的鼻子呼！地砸了过去",
                "dodge":                5,
                "parry":                5,
	    "force":		90,
                "damage_type":  "砸伤"
        ]),
        ([      "action":
"$N左手一分，右拳运气，一招[36m「拔草寻蛇」[2;37;0m便往$n的$l招呼过去",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N右拳在$n面门一晃，左掌使了个[33m「叶底偷桃」[2;37;0m往$n的$l狠命一抓",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "抓伤"
        ]),
        ([      "action":
"$N步履一沉，左拳拉开，右拳带风，一招[31m「黑虎掏心」[2;37;0m势不可挡地击向$n$l",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"只见$N拉开架式，一招[1;36m「双风贯耳」[2;37;0m使得虎虎有风。底下却飞起一脚踢向$n$l",
                "dodge":                5,
                "parry":                5,
	    "force":		70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N打得兴起，大喝一声：看我这招[1;32m「龙虎相交」[2;37;0m！\n左手往$n身后一抄，右拳便往$n面门砸了过去",
                "dodge":                5,
                "parry":                5,
	    "force":		120,
                "damage_type":  "砸伤"
        ]),
        ([      "action":
"$N拉开后弓步，双掌使了个[35m「如封似闭」[2;37;0m往$n的$l一推",
                "dodge":                5,
                "parry":                5,
	    "force":		50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"只见$N运足气力，一连三拳击向$n$l，力道一拳高过一拳！\n这一招的名字还相当高雅，叫作[1;33m「阳关三叠」[2;37;0m",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N往后一纵，就势使了个[1;32m「老树盘根」[2;37;0m，右腿扫向$n的$l",
                "dodge":                5,
                "parry":                5,
	    "force":		50,
                "damage_type":  "砸伤"
        ]),
        ([      "action":
"$N一个转身，左掌护胸，右掌反手使了个[1;32m「独劈华山」[2;37;0m往$n当头一劈",
                "dodge":                5,
                "parry":                5,
	    "force":		90,
                "damage_type":  "砸伤"
        ]),
        ([      "action":
"$N飞身跃起，半空中一脚踢向$n面门，却是个虚招。\n说时迟那时快，只见$N一个倒翻，双掌已到了$n的$l",
                "dodge":                5,
                "parry":                5,
	    "force":		100,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("练长拳必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
 return CLASS_D("fighter") + "/changquan/"+func;
}
