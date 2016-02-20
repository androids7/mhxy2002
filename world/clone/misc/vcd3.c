#include <ansi.h>

inherit ITEM;
void create()
 {
    set_name("家庭影院", ({"vcd"}) );
    set_weight(1000);
    if( clonep() )
           set_default_object(__FILE__);
    else {
        set("unit", "台");
        set("long", "一台高级家庭影院,上面有play,shut,kala,stop一些字样.\n");
         set("no_get",1);
         set("value",10000);
    }
    setup();
}

void init()
{
       add_action("do_play", "play");
}
int do_play()
{
                if (this_object()->query_temp("play")==1)
         return notify_fail("现在正在放着ＶＣＤ呢。\n");
                if (this_object()->query_temp("kala")!=0)
         return notify_fail("现在正有人唱卡啦ＯＫ呢。\n");
                this_object()->set_temp("play",1);
                call_out("start_play",2);
                return 1;
}

int start_play()
{
message("channel:chat",HIR+"〖"HIG"魔幻电台"HIR"〗："NOR+HIY"一个古怪的盒子在作怪了。\n"+NOR,users());
        call_out("continue_play",1,-1);
        return 1;
}

int continue_play(int release)
{

string *str1=({
                         "\n\n大闹天空前奏\n\n",

"话说孙悟空回到了花果山……\n",
"猴子甲：大王！\n",
"悟空  ：猴子甲！\n",
"猴子甲：大王，能不能给我起个有深度点的名字？\n",
"悟空  ：谁让你是跑龙套的，猴子乙，你说呢？\n",
"猴子乙：是啊！不过请问这几年您都干什么去了呢？\n",
"悟空  ：学艺嘛，好辛苦的！\n",
"猴子乙：哦？可是最近有传闻说您到另一个山头当了兼职老大。\n",
"悟空  ：其实作为一个名人呢，媒体的各种炒作一定会很多的，\n",
"        但我不会在意别人的传闻的。\n",
"猴子乙：那您能不能谈一谈您现在的想法呢？\n",
"悟空  ：想不到我走了这几年，这里还是这么山清水秀，感谢大\n",
"        家对这里环境的保护。\n",
"猴子乙：您今后有什么打算呢？\n",
"悟空  ：我想……\n",
"猴子甲：蛮有抻头的！\n",
"悟空  ：我想……\n",
"猴子乙：您到底想干什么呢？\n",
"悟空  ：我想……大一个便先！\n",
"悟空  ：然后就改名为“齐——天——大——圣——”！\n",
"众猴子：啊！……\n",
"悟空  ：啊什么啊？\n",
"众猴子：啊！……\n",
"悟空  ：啊什么啊？\n",
"众猴子：啊！……啊……啊嚏！\n",
"悟空  ：靠！还以为是吃惊呢！原来是着凉！\n",
"猴子甲：对不起。不过大王，您都学会了什么手艺？\n",
"悟空  ：手艺？靠！太多了，我现在很能打的！\n",
"猴子乙：那您善用什么兵器呢？\n",
"悟空  ：只要很重就可以的，没有别的条件。\n",
"猴子甲：大王，给！\n",
"悟空  ：我虽然说要重一点的，你也不用抱这么大一块岩石给我啊？\n",
"猴子乙：大王，我听说东海龙宫有各样兵器可供选择，价钱合理量又\n",
"        足，我们一直都用它！\n",
"悟空  ：真的？量足就好了，价钱嘛，花果组还用得着付钱？\n",
"猴子甲：老大就是老大，不用交钱的！\n",
"悟空  ：我早就申请了“一卡通”了，可以异地支付，爽呆了！\n",
"众猴子：@#$%^&*\n",
"               \n（水晶宫）\n",
"龙王  ：大圣！\n",
"悟空  ：哦？你认得我？\n",
"龙王  ：当然了，我有看电视节目啊！花果组开张大型文艺晚会很好看的！\n",
"悟空  ：呵呵，过奖！我今天其实是希望能来挑一件兵器回去！\n",
"龙王  ：好说，我现在正在“庆五一”八折大酬宾！来呀，抬峨嵋针上来！\n",
"悟空  ：靠！峨嵋针？小李飞刀啊！有没有大一些的？\n",
"龙王  ：有有有，抬大号峨嵋针上来！\n",
"悟空  ：拜托！我的强项不是投掷，我要一件能耍的兵器！\n",
"龙王  ：好，请看！来人啊！抬加长峨嵋针上来！\n",
"悟空  ：very good，你要再敢抬峨嵋针上来，我就强奸了你的坐骑母海马！\n",
"龙女甲：（低声对龙王）老爸！他摆明是来踢馆的，我看就让他去试试“镇\n",
"        海神针”算了！\n",
"龙王  ：算你老母！我早就说我和你妈是近亲，不然怎么会生出你这么个怪\n",
"        物。镇海神针是宝物，怎么能让他拿去？以后你再多嘴我就割吊你\n",
"        的舌头！\n",
"龙女  ：他拿不去才会死心嘛！\n",
"龙王  ：说的也是。（转过头）大圣，小神还有一件兵器，不过要请大圣亲\n",
"        自来取。\n",
"悟空  ：你带路先！\n",
"               \n……\n",
"龙王  ：各位观众，请看！\n",
"悟空  ：哇！好大的棒槌！龙王，你吃了“我爱一根柴”？\n",
"龙王  ：错！这就是“镇海神针”！它是当年解放军抗洪抢险时留在这里保\n",
"        平安的！黑铁锻造，两头金箍，可折叠存放，任意大小，一棒多用\n",
"        ，上面还有总书记的题词！棒重十万八千斤！……？大圣！大圣！\n",
"        ！他人呢？“镇海神针”呢？\n",
"龙女  ：他早就拿着“镇海神针”走了！\n",
"龙王  ：你为什么不早说？\n",
"龙女  ：你刚才不让人家乱插嘴的嘛！我怕你割人家的舌头！\n",
"龙王  ：来人！把它给我拉下去，除了舌头全都割掉！\n",
"\n（翌日，花果山竖起了“齐天大圣”的大旗）\n",
"猴子甲：大王，旗杆太高了。\n",
"悟空  ：什么？我出去瞧瞧先！\n",
"猴子甲：follow me！\n",
"悟空  ：这是什么！\n",
"猴子乙：大王，为了显示您的威力，小的把整个后山的树都砍光了，一截一\n",
"        截的接起来的，有三百多丈高呢……\n",
"悟空  ：那旗呢？\n",
"猴子乙：旗子是要用布做的，咱们还不太会织布，所以我就用了一片最大的\n",
"        芭蕉叶写上“齐天大圣”，已经升上去了。\n",
"悟空  ：你脑子里塞棉花了？这么高的杆子顶一片叶子！放风筝啊！不如你\n",
"        到巴黎维修唉非儿铁塔算了！\n",
"                       \n（天上）\n",
"千里眼 ：报~~~~~~！\n",
"玉皇   ：报你个头啊！你是不是又看见石头里蹦出猴子来了？\n",
"千里眼 ：错！绝对错！是下面有人用杆子捅咱们灵霄宝殿！\n",
"玉皇   ：什么？你再去看来！\n",
"千里眼 ：还看？我刚刚看过啦！\n",
"玉皇    ：哦，那到底是什么东西？\n",
"千里眼  ：就是上一次从石头里蹦出来的那只猴子！\n",
"玉皇    ：果然被我猜着了！你们看这该如何是好！\n",
"托塔天王：好！让俺带领十万天兵……\n",
"玉皇    ：又带？十万！天宫早就养不起这些人啦！昨天我已经下了裁军令，\n",
"          就剩一万了！\n",
"托塔天王：一万？\n",
"玉皇    ：怎么？嫌多？再裁掉一半好了！\n",
"托塔天王：不不不！就一万吧……\n",
"太白金星：陛下，老臣以为此计不妙！\n",
"玉皇    ：什么意思？\n",
"太白金星：这猴子已经在菩提老祖那里学了一身本领，硬打只会两败俱伤！\n",
"托塔天王：看你一大把胡子，竟然这么不懂形势。什么两败俱伤，当然是全\n",
"          军覆没！\n",
"太白金星：哦？你竟然有如此把握获胜？\n",
"托塔天王：胜你个头啊！一万天兵如何功德下花果山？是我们全军覆没啊！\n",
"玉皇    ：谁说一万天兵了？\n",
"托塔天王：您刚才不是说……\n",
"玉皇    ：我是说裁军了，可是剩下的那一万全是文艺兵！\n",
"托塔天王：文……艺……兵……\n",
"玉皇    ：你心里高兴就好了，不要吐那么多血嘛！好好好！金星，下面你\n",
"          继续发言。\n",
"太白金星：谢谢，我看应该把那猴子招安上天庭，给他个芝麻小官，既可让\n",
"          他心理安慰，又可以“一切仅在掌握”。\n",
"玉皇    ：那安排让他做什么官呢？\n",
"太白金星：无厘马场少个养马的，不如就……\n",
"玉皇    ：好！那就有劳大架亲自走一趟了。\n",
"太白金星：我？可我已经老了。\n",
"玉皇    ：那才有经验么！\n",
"太白金星：我动作太慢！\n",
"玉皇    ：慢功出细活嘛！\n",
"太白金星：我最近身体很虚呀！\n",
"玉皇    ：曹开镛男士营养液！等你一回来我就买给你吃！\n",
"太白金星：……靠！看来是非我莫属了？\n",
"玉皇    ：ok，就依你，这可是你自己说的啊！\n",
"\n\t（花果山）\n",
"猴子甲  ：大王，来了一个天外来客！\n",
"悟空    ：身为一帮之主，我怎么会相信这些无稽的事情呢？\n",
"猴子甲  ：你不信？look！\n",
"太白金星：大圣！\n",
"悟空    ：哦？先生贵姓啊？\n",
"太白金星：我复姓太白，名金星。\n",
"悟空    ：了解！怪不得他们说是天外来客，原来是太阳系九大行星之一\n",
"          前来签到！\n",
"太白金星：你说什么？\n",
"悟空    ：（小声）我是借此机会向正在阅读文章的小朋友们介绍一下科\n",
"          普知识，你继续说！太白金星：是玉皇大帝叫我来请大圣上天\n",
"          做官的！\n",
"悟空    ：啊！正所谓伴君如伴虎、官场如战场，我现在还不想从政！\n",
"太白金星：大圣哪里话来！你若成了天庭官员，也可以恩泽花果山呀！\n",
"悟空    ：对呀！想来想去，没有什么太好的拒绝你的理由，那我就试试！\n",
"猴子乙  ：大王，那我们呢？\n",
"悟空    ：等我在上面混出个名堂，就开一家夜总会，到时候就叫你们一起去！\n",
"猴子乙  ：yeah！\n",
"悟空、太白金星、猴子甲：靠！秀逗！\n",
"\n\t（无厘马场）\n",
"悟空    ：不是吧？猴子甲、猴子乙？又是你们俩？\n",
"马夫甲  ：大圣，我们两个现在扮演的是马夫，反正也是跑龙套的，导演让\n",
"          我们试试先。\n",
"悟空    ：真受不了！好吧，靠！这里的马还真他妈正点！\n",
"马夫乙  ：大圣，做了神仙就不要讲粗口了。\n",
"悟空    ：不管怎么说，我也是个老大，说话随便一点，观众不会说什么的！\n",
"          还没有问你们，这里你马都是干什么用的？\n",
"马夫甲  ：1#棚里的马是跑马，是在无厘马场驰骋的良驹！红色闪电、令狐\n",
"          冲、咸蛋超人、傲世花斑，都是一等一的宝马！每次注额1-500点，\n",
"          一赔三！赌马过程中,有4种方式可以直接改变下注马的表现和赌\n",
"          场结局：1.鞭子 用鞭子抽，可以增加下注马的速度，但是会影响\n",
"          到比赛中的耐力。如果是自己的马，会影响到驯服度。2.饲料需要\n",
"          用积分在商店购买，比赛中可以增加下注马的体力和耐力。\n",
"          3.悦耳音乐可以使马性情稳定，增加马匹的耐力和信心。\n",
"          4.在马后面扔鞭炮可以增加马的速度，但是对马的身心造成\n",
"          极坏的影响，并且降低了马的斗志和耐力。这4种方\n",
"          法在当场比赛中累计一共只能用6次，如果滥用，马可能会精神\n",
"          崩溃，当场死亡或者退出比赛。\n",
"导演    ：cut！我已经忍受了半天了，我不知道你再说些什么！\n",
"马夫甲  ：做做www.zhouxingchi.com的广告嘛！谁让有些人总公然的转帖又\n",
"          不注明出处的！\n",
"导演    ：靠！原来是这样，继续！\n",
"悟空    ：原来这么嘬！\n",
"马夫乙  ：2#棚里的马是母马，专下小马的！\n",
"悟空    ：那岂不是跑马都要做爸爸了？\n",
"马夫乙  ：错！3#棚里才是种马！是跑马退役后才可以来，他们腿上都有伤，\n",
"          但基因却十分完美！\n",
"悟空    ：啊！………\n",
"马夫甲  ：大圣，你怎么了？\n",
"悟空    ：我的腿好像伤了！\n",
"马夫    ：变态！\n",
"悟空    ：可是我总觉得这个工作不太适合我干？\n",
"马夫乙  ：弼马瘟嘛，，有什么适不适合的？说白了就是给人家养马。\n",
"悟空    ：不会吧？养马？\n",
"马夫甲  ：养马！老子辛辛苦苦来这里就是给别人养马！我不干了！\n",
"       \n\t（转身飞回花果山）\n",
"       \n\t（天宫内）\n",
"玉皇    ：什么？不干了？这里还是不是天庭！靠！啸天犬和旺财胡搞，\n",
"          七仙女到人间吊凯子，来了个养马的，说不干就不干了，我\n",
"          在这个位子上坐得很没有面子啊！拜托你们有一点专业精神好不好？\n",
"托塔天王：让俺带一万文艺兵……\n",
"玉皇    ：又来？你有没有学习过《邓小平理论》？他老人家说和平与发展\n",
"          才是当今社会的主题，少宣传一些暴力吧！我们文艺工作者有责任的！\n",
"太白金星：我看就让他上天来做“齐天大圣”好了。反正也没有这个职位，\n",
"          随便让他看个桃园什么的，也行。\n",
"玉皇    ：靠！爱抚了有！\n",
"\n\t（花果山）\n",
"猴子乙  ：大王，那个老头又来了！\n",
"悟空    ：什么？有没有搞错啊！\n",
"太白金星：大圣！小仙来此是很有诚意的！\n",
"悟空    ：诚意？我再也不去看马了！只听说有牧羊犬，我算是开了牧马猴\n",
"          的先例了！\n",
"太白金星：对不起，上一次是系统故障，这次是请您去做齐天大圣的！\n",
"猴子甲  ：系统故障？不要来骗我了，大家都是用过windows的，什么故障，\n",
"          智障还差不多！\n",
"悟空    ：靠！跑龙套的台词这么多？我看这次金星来还是很坦诚的。\n",
"太白金星：对呀！这都被你看出来了，你真不愧“大圣”这个称谓！\n",
"悟空    ：好好好，俺就再跟你去一趟，不过要是再不合我的意，\n",
"          小心我拉一坨饭给你吃！\n",
"太白金星：一言为定，此次上天界是让您来做蟠桃主！很有前途的！\n",
"\n\t（音乐声起：你挑着担，我牵着马，迎来日出送走晚霞……）\n",


});

        if (release==0) {
                this_object()->set_temp("play",0);
                return 0;
        }

      if (release==-1) {
                continue_play(sizeof(str1));
                return 1;
        }
message("channel:xjmy",HIR+"〖"HIG"魔幻电台"HIR"〗："+NOR+YEL+str1[sizeof(str1)-release]+NOR,users());
users());
      call_out("continue_play",1,release-1);
        return 1;
}
