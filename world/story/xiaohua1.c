//By tianlin@mhxy for 2002.1.14
//自大话西游论坛上摘抄,改写.

#include <ansi.h>

string give_gift();

private mixed *story = ({
        ""HIR"梦"HIC"幻"NOR+CYN"西"HIY"游"HIW"之"HIG"悟空入狱"NOR,
        "",
        "庄严的天庭公安局。",
        "",
        ""HIC"观音："NOR+WHT"孙悟空，你这个畜生，你本答应党和人民要带领群众奔小康，",
        "谁知道你竟然和黑社会头子牛魔王勾结贪污受贿大肆走私，",
        "严重扰乱社会的安定团结，你知不知道已经犯下了弥天大罪？",
        "",
        ""HIW"孙悟空："NOR+WHT"少罗嗦,你追了我3年多,因为白晶晶那个贱人出卖我,才给你抓到,不要以为你厉害。",
        "",
        ""HIG"唐僧："NOR+WHT"悟空，你怎么可以这样跟观音姐姐说话呢。。。",
        "",
        ""HIC"观音："NOR+WHT"唐三藏，你不要多嘴，为了让你监督这个死猴子，我让你做纪委书记，",
        "谁知道你竟然和他同流合污，还有脸来见我？",
        "",
        ""HIG"唐僧："NOR+WHT"姐姐有所不知啊，悟空是党委书记，权倾一方，我一个小小的纪委书记能奈他何？",
        "所以还是实惠一点好,大家互相帮助，何乐而不为呢？",
        "啊，说到贪污腐败，我觉得现在已经蔚然成风，靠我们一二人之力不可扭转，",
        "就说姐姐你吧，上次不是收了我一套家庭影院。。。。",
        "",
        ""HIC"观音："NOR+WHT"住口！",
        "",
        "悟空：这家伙没事就长篇大论，叽叽歪歪，连送礼这样的事都说出来。",
        "观音大士，你都收人家东西，还怎么来说我呢，你们慢聊，我走先。",
        "",
        "悟空说完欲走，左右士兵将他拦住，捆绑，送到大牢。",
        "",
        "…………",
        "",
        "潮湿昏暗的牢房，悟空坐在草堆里，形容憔悴。 ",
        "",
        "狱卒：孙悟空，有人找！",
        "",
        "悟空：WHO？",
        "",
        "狱卒：叫白晶晶的。",
        "",        
        "难道她良心发现，悟空兴冲冲的向接见室走去。真的是她，还是那么美丽娇艳，楚楚动人。",
        "",
        "悟空：晶晶！",
        "",
        "白晶晶：悟空！",
        "",
        "悟空：我入狱这么久，只有你来看我，真让我感动啊！",
        "",
        "白晶晶：我是来…………",
        "",
        "悟空：你知道什么是当当当当当吗？",
        "",
        "白晶晶：我是来问你。。。",
        "",
        "悟空：当当当当当 就是，ONLY YOU 能伴我去跳舞，ONLY YOU 身段苗条美丽，",
        "ONLY YOU迷住我，让我贪污和受贿，你最迷人就是ONLY YOU ！",
        "",
        "白晶晶：哎，其实我是来。。",
        "",
        "悟空：ON````ONLY YOU，坐牢我来，享福你去，拼全力为了你，牺牲也值得。。。。。",
        "",
        "白晶晶：你别ON 了，我是来。。。",
        "",
        "悟空：ON``````ON",
        "",
        "白晶晶挥起钱包向悟空劈面砸下。",
        "",
        "白晶晶：ON你个头啊，你以为我是来看望你啊？你现在不过是死囚啊大哥，",
        "别学人家唱情歌，难道你准备做风流才子啊？",
        "",
        "悟空：我有想过",
        "",
        "白晶晶：省省吧你，还是好好准备怎么挨那一刀吧，死猴子！",
        "",
        "悟空：我明白了。"HIM"（说完奔向牢房）"NOR"",
        "",
        "白晶晶：哎，我还没有说完呢，我是来问你上次给我的存折，密码几号啊？",
        "",
        "悟空猛然停下来,中全是泪水,经以为她是爱我的,现在才明白她爱的是钱,小秘就是不可靠啊.",
        "",
        "…………",
        "",
        "悟空作早草堆里，夜幕已然降临，黑暗的牢房里飘出一阵苍凉的歌声，是"HIC"《领悟》："NOR"",
        "",
        "　　　　"MAG"我以为我会上诉,可是我没有,我只是看着手上的铐子,往事依然历历在目,我却才开始"NOR,
        ""MAG"有一种领悟,让我把自己看清楚,贪污是罪恶的兄弟,一上手就是死路。。。。"NOR,
        "",
        "　　　　"CYN"我以为她会痛哭,可是她没有,当我看着深爱过的小秘,竟然变的如同陌路,这何尝不是"NOR,
        ""CYN"一种领悟,让我把她看清楚,小秘是危险的游戏,如果没钱就不给幸福。。。。"NOR,
        "",
        "　　　　"HIC"啊！"NOR+YEL"一场官途就此结束,一颗人头眼看要落地,我的一生都是错误,杀头是该受的痛苦,"NOR,
        ""YEL"只愿我下辈子能看清楚,不在为钱去死。。。。。"NOR,
        "",
        "行刑的日子终于到了,悟空被带到大堂。",
        "",
        ""HIY"如来："NOR+WHT"孙悟空，你还有什么话要说？",
        "",
        "悟空：曾经有一个妖艳的女子摆在我面前,我没有把握住自己,而让她作了小秘,做官最危险",
        "的事莫过于此,从此我就被她摆布,贪污受贿几个亿。如果上天可以给我一次重新来过的机会,",
        "我一定会说：我不要！如果要给这三个字加个期限，我希望是："BLINK+HBRED+HIW"一万年！"NOR,
        "",
        ""HIY"如来："NOR+WHT"好，你终于有所悔悟，来世好好做人吧。现在在行刑文书上画押。",
        "",
        "悟空手握毛笔，非常吃力而虔诚的在那纸上画了一个圈，尽管他已经非常努力，可是仍不够",
        "圆，不免有点遗憾，可是转念一想“孙子才画的圆”呢，于是释然，进而觉得自己的不圆有后现代主",
        "义的风格。",
        "",
        ""HIM"奶奶的，过几年之后恐怕是价值连城的艺术品，值好多好多钱吧，悟空痴痴的想。"NOR,
        ""HIR"观众吐血狂笑........"NOR,
          (: give_gift :),

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
        STORY_D->give_gift("/clone/gift/qianbao", 1,
                           HIM "\n突然天空中飞出来个钱包掉在了你的面前.\n\n" NOR);//我的形容词不错吧.(snicker)
        return HIM "听说"HIC"白晶晶"HIM"的"HIY"钱包"HIM"流落人间了！\n" NOR;

}
