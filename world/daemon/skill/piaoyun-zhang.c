// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//piaoyun-zhang.c ��Ʈ���ơ�weiqi
//menpai skill(non manpai NPCs can also use it)

#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":
"ֻ��$N�������������ֻ��أ��������ĳ����࣬����һ�ɺ���֮������$n$l",
                "dodge":                -5,
                "parry":                -5,
       "force":     80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N��������������λ��˫��һ������$n$l��ȥ���������ᣬʵ�򰵺�������",
                "dodge":                -25,
                "parry":                -25,
       "force":     70,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ��������ȴ����һ��֮������벻���ĽǶ�������$n��$l",
                "dodge":                -5,
                "parry":                -5,
       "force":     60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һЦ��˫���ڿ����л����������죡�����ݺ���ͻȻ�ɳ�һ�ƣ�������Ϣ������$n$l",
                "dodge":                5,
                "parry":                5,
       "force":     100,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�ݣ���$n����������$NͻȻ����˫�ư���$n��$l",
                "dodge":                -5,
                "parry":                -5,
       "force":     90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����������ת�����������ݰ���$n��ȥ��תһȦ��һ�ƣ����Ʋ���$n��$l",
                "dodge":                5,
                "parry":                5,
       "force":     60,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$Nһ����Х����������ˮ�����������ƣ�������ת�����಻��������$n����Ҫ��",
                "dodge":                5,
                "parry":                5,
       "force":     80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�ݣ�����ʹ��ɨ���ȣ�˫��ȴ����������ϣ�����ֱ��ػ���$n$l",
                "dodge":                -5,
                "parry":                -5,
       "force":     60,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("��Ʈ���Ʊ�����֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("sen") < 30)
     return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
   if( (int)me->query("kee") < 30 )
     return notify_fail("������������������Ϣһ�������ɡ�\n");
   if( (int)me->query("force") < 10 )
     return notify_fail("������������ˡ�\n");

   me->receive_damage("kee", 30);
   me->add("force", -10);

   return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 200 ) return 0;
        if( me->query_skill("xiaoyao-sword",1) < 180) return 0;
        if( me->query_skill("piaoyun-zhang",1) < 180) return 0;
       if( random((int)me->query_skill("xiaoyao-sword",1)) > 200 ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 4 );
                victim->apply_condition("qi_poison",random(4));
                 return HIC"$N˳����ǰһ�ƴ�����֮��������$n���Ŀڣ�$n���˼����������������Ѫ��\n"NOR;
                }
        else return HIB"$N˳����ǰһ�ƴ�����֮��������$n���Ŀڣ�$n��æ�����������к����Ƴ����⡣\n"NOR;
}


string perform_action_file(string action)
{
    return CLASS_D("tiankongjie") + "/piaoyun-zhang/" + action;
}