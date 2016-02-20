//By tianlin@mhxy for 2001.9.18
//在制作此商店时,我想要是和他们一样都设在npc身上去买东西,有点不大好,
//(1)是npc容易被杀害,要是你给npc设上no_die也行,不过也不怎么地,还没有新
//鲜感,(2)是设在ROOM里面的话,以上的问题就解决了,而且ROOM还很华丽,我自任
//为不错,大家可以模仿的作一下,请不要改作者的名字..谢谢!!!(xixi)
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", NOR"兵器"HIC"★"NOR"商店");
  set ("long", @LONG

[37m         [32;47m     ▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂      [1;37;40m▎
[37m         [1;31;47m     [37;42m            [1;35m五[5m[1;36m★[0m[37;42m[1;35m级兵器专卖店[0m[37;42m            [31;47m      [37;40m▎
[37m         [32;47m     [37;42m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄[1;47m      [40m▎
[37m      [1m   ▕[47m■■■[33;46m[37;47m■■■▕[m
[37m      [1m   ▕[47m■■■[33;46m[37;47m■■■▕[m
[37m      [1m   ▕[47m■■■[33;44m│      │      │      │      │[37;47m■■■▕[m
[37m      [1m   ▕[47m■■■[33;44m├───┼──────┼───┤[37;47m■■■▕[m
[37m      [1m   ▕[47m■■■[33;44m│﹏﹏﹏│﹏﹏﹏│﹏﹏﹏│﹏﹏﹏│[37;47m■■■▕[m
[37m      [1m   ▕[47m■■■[32;43m│※※※│※※※│※※※│※※※│[37;47m■■■▕[m
[1;33m      ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[m
[37m  [1;41m [NO]  [兵器名]   [加法力]  [重量]  [攻击力]   [加轻功]  [售  价][m
   [1;35m( [1;32m1[1;35m)[0m   [1;31m恶魔[1;36m＊[1;31m战斧[0m    0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m2[1;35m)[0m   [1;36m璇 [1;37m天 [1;32m棒[0m      0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m3[1;35m)[0m   [1;32m寒[1;37m 雪[1;36m 寶[1;31m 刀[0m   0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m4[1;35m)[0m   [1;31m孽[1;36m龙[1;37m寒[1;32m匕[0m      0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m5[1;35m)[0m   [1;31m火焰[1;33m翎[0m        0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m6[1;35m)[0m   [1;34m九天[1;33m轩骨[1;32m叉[0m    0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m7[1;35m)[0m   [1;37m九骨开山锤[0m    0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m8[1;35m)[0m   [1;34m惊魂[1;31m夺魄[1;33m锏[0m    0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m9[1;35m)[0m   [1;35m斗转[1;33m金星[1;36m耙[0m    0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m10[1;35m)[0m  [37m雷霆[33m霸王枪[0m    0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m11[1;35m)[0m  [1;37m阿弥陀[1;33m禅杖[0m    0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m12[1;35m)[0m  [37m冰魄寒光剑[0m    0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m13[1;35m)[0m  [1;31m血玉龙筋鞭[0m    0       0          0        随机      [36m200[33m两[1;33m黄金
   [1;35m( [1;32m14[1;35m)[0m  [1;35m漫[1;36m天[1;33m飞[1;37m羽[0m      0       0          0        随机      [36m200[33m两[1;33m黄金
[1;41m                                                                           [m
LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"daojudian",
]));

        setup();
}

void init()
{
        add_action("do_buy","buy");
}

int do_buy(string arg)
{
        object obj;
        object me=this_player();
        int afford;
        if(me->is_busy())
                return notify_fail(CYN"你现在正忙着呢。\n"NOR);
        switch(arg)
        {
                case "1":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/axe");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIR"恶魔"HIC"＊"HIR"战斧"NOR"。\n");
                break;
                }
                
                case "2":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/bang");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIC"璇 "HIW"天"HIG" 棒"NOR"。\n");
                break;
                }

                case "3":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/blade");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIG"寒 "HIW"雪 "HIC"寶 "HIR"刀"NOR"。\n");
                break;
                }
                case "4":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/dagger");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIR"孽"HIC"龙"HIW"寒"HIG"匕"NOR"。\n");
                break;
                }
                case "5":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/feiyu");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIR"火焰"HIY"翎"NOR"。\n");
                break;
                }
                case "6":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/fork");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIB"九天"HIY"轩骨"HIG"叉"NOR"。\n");
                break;
                }
                case "7":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/hammer");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIW"九骨开山锤"NOR"。\n");
                break;
                }
                case "8":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/mace");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIB "惊魂"HIR"夺魄"HIY"锏" NOR"。\n");
                break;
                }
                case "9":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/rake");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIM"斗转"HIY"金星"HIC"耙"NOR"。\n");
                break;
                }
                case "10":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/spear");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"WHT "雷霆"YEL"霸王枪" NOR"。\n");
                break;
                }
                case "11":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/staff");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIW "阿弥陀"HIY"禅杖" NOR"。\n");
                break;
                }
                case "12":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/sword");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"WHT "冰魄寒光剑" NOR"。\n");
                break;
                }
                case "13":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/whip");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIR "血玉龙筋鞭" NOR"。\n");
                break;
                }
                case "14":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("你带的钱不够。\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/yumao");
                obj->move(me);
                me->start_busy(4); 
                write("你向兵器铺买下一个"HIM"漫"HIC"天"HIY"飞"HIW"羽"NOR"。\n");
                break;
                }
        }
return 1;
}

