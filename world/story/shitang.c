//By tianlin@mhxy for 2002.1.9
#include <ansi.h>

string give_gift();

private mixed *story = ({

""MAG"面对着面坐在食堂里，看看饭缸没有欲望。"NOR"",
""YEL"你抱怨除了肥肉全是油，我希望菜价降一降。"NOR"",
""CYN"你说想给卖饭的一个巴掌，不过他比你身高体壮。"NOR"",
"看样子他在村里专职喂猪，拿勺的样子真是好象。",
""RED"我想能做的最幸福的事，就是菜里辣椒肥肉变少。"NOR"",
""BLU"要是没有沙子、钢丝和烂草，放到嘴里可以放心慢慢嚼。"NOR"",
(: give_gift :),
""GRN"我想能做的最幸福的事，就是食堂里苍蝇变少。"NOR"",
""YEL"别到我们吃后总往厕所跑，你才知道我们的身体没有想象中的好。"NOR"",

});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/misc/lancao", 1,
                           HIM "\n“啪”的一声一团烂草掉到你面前。\n\n" NOR);
        return HIM "烂草落人间~~~~。\n" NOR;
}
