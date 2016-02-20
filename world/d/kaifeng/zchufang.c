// Room: /d/kaifeng/zchufang
// by cih 10/01/2002
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "帅府厨房");
  set ("long", @LONG

这里是天蓬元帅府门人弟子们吃饭的场所。因为元帅府的
弟子都特别的能吃，所以这里摆着各种各样的食物。方便
元帅府的笛子可以随时随地的来吃。

            [1;37m※※※※※※※※※※※※[2;37;0m
            [1;37m※                    ※[2;37;0m
            [1;37m※[2;37;0m      [1;33m美食餐馆[2;37;0m[1;37m      ※[2;37;0m
            [1;37m※                    ※[2;37;0m
            [1;37m※※※※※※※※※※※※[2;37;0m

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shuaifu",
]));
  set("objects", ([ /* sizeof() == 4 */
  "/d/obj/food/bao3" : 3,
  "/d/obj/food/baozi" : 3,
  "/d/obj/food/chahu" : 3,
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
int valid_leave()
{
        if((present("bao", this_player())))
            return notify_fail("元帅有令：为了猪弟子的健康，只能吃完了在走！\n");
    return ::valid_leave();
}
