// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[37m白玉桥[m");
  set ("long", @LONG

一座用上好的滇池白玉所造的小桥,桥身如虹,上面还刻着一些
不知道描述什么的图画.桥的两旁是一条清澈的小河,河上星星点点
地生着一些彩莲,几对鸳鸯在河中悠闲的游着,偶尔也能看见一两只
仙鹤从桥上飞过,桥的北面就是灵霄宝殿了.
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"nanmenting.c",
      "north" : __DIR__"dianmen.c",
]));


  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-nan" : 2,
]));

  setup();
}
