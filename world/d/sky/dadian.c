// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[33m灵霄宝殿[m");
  set ("long", @LONG
这里就是玉帝所在的灵霄宝殿了.殿上当真是霞光万道,瑞气千条.
仙官仙将们列在一旁,北上处正是玉帝老儿的宝座.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dianmen2.c",
"northup" : __DIR__"neidian.c",
]));


  set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/julingshen" : 1,
  __DIR__"npc/erlang" : 1,
  __DIR__"npc/lijing" : 1,
  __DIR__"npc/guard"  : 5, 
]));

  setup();
}
int valid_leave(object me, string dir)
{
        object a;
        if( wizardp(me)) return 1;

        if (dir == "northup") {
                if(objectp(a=present("erlang zhenjun", environment(me))) && living(a))
                return notify_fail("二郎神身行一闪,挡在了你的面前。\n");
                if(objectp(a=present("li jing", environment(me))) && living(a))
                return notify_fail("李靖身行一闪,挡在了你的面前。\n");
return ::valid_leave(me, dir);
        }

        return 1;
}
