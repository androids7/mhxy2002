//By tianlin@mhxy for 2002.1.9

#include <ansi.h>
int give_gift();
mixed *story = 
({
        "话说岳灵珊心血来潮想练棍法，找来找去找不到短棍，忽然想起一件东西，",
        "…………",
        "令狐冲和盈盈幽会回来，心情特别好，走进房间想找箫吹奏一曲，结果找不",
        "到，最后在练功房找到了已经身首异处的箫。",
        "令狐冲一肚子的火，仰天长啸：“谁……谁干的？站……站出来！！！",
        "岳灵珊跳过来，叉着腰说：”是我啊，你能把我怎么着？”",
        "令狐冲：你想要呀？你想要说清楚了就行了嘛，你想要我会给你的，你想要",
        "        我当然不会不给你了。不可能你说要我不给你，你说不要我却偏要",
        "        给你。大家讲道理嘛……",
        "令狐冲越说越激动，声调也越来越高……",
        "话说wuyou正在oicq上和一个ppmm聊天，正聊得起劲，被令狐冲吵得昏头涨脑，",
        "实在不胜其烦，大叫一声：”我Kao！不就是一只箫吗，我再给你一支就是了！",
        "只见wuyou伸手凌空一指，变出了"CYN"玉箫"WHT"。随手一扔，又忙着去找他的mm了",
        (: give_gift :),
        "令狐冲等了半天，还是没有：“奇怪，怎么老半天了连箫的影子都没有？”",
        "远远的传来wuyou的声音：“笨蛋，自己去找！”",
        "令狐冲“唉”的叹了一口气：“这世道，什么事都会发生……”",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/clone/gift/obj/yu_xiao", 1,
                           HIM "\n一支"NOR+CYN"玉箫"HIM"掉到你头上，砸出一个大包。\n\n" NOR);
        return 1;
}
