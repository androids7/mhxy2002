// Room: /u/tianlin/workroom.c
#include <ansi.h>
inherit ROOM;
void create ()
{
    set ("short", HIC"街机游戏室"NOR);
  set ("long", @LONG

这里是一个最大的街机游戏室了,在这里你可以玩到拳皇一类的街机游戏,
在这屋子中间端坐一位美女，哇，是萧亚轩啊，快让她签名！
你还能看见有个巫师正在和他聊天呢!
猜猜是谁,呀!是tianlin正在和他说话呢!
LONG);

     set("exits", ([
             "west" : __DIR__"bedroom",
                 "down" : "/u/valen/workroom",
               "east" : __DIR__"guestroom",
             "out" : __DIR__"guardroom",
          "kz" : "/d/city/kezhan",
          "linger" : "/u/linger/workroom",
           "up" : "/d/wiz/wizroom",
             "guest" : "/d/wiz/guest",
     ]));    
  set("outdoors", 0);
// set("no_fight",1);
set("no_magic",1);
set("no_time",1);
  set("valid_startroom", 1);
      set("objects", ([
//            "/u/yudian/npc/zhinu" : 1,
//            "/u/vikee/table" : 1,
//              "/d/wiz/npc/welcome" : 1,
      ]));     
//            __DIR__"/npc/zhangbz" : 1,
//                __DIR__"/npc/jing" : 1,
//                 __DIR__"/npc/banxian" : 1,
//      ]));           
  setup();
      call_other("/obj/board/tianlin_b", "???");
}
