//ningshenforce.c
//【蜀山剑派】by yushu 2001.2
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return
notify_fail("蜀山心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("shushan") + "/shushan-force/" + func;
}

