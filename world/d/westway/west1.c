// create by snowcat.c 4/8/1997
// room: /d/westway/west1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","大官道");
  set ("long", @LONG

这是一条宽阔笔直的大官道，足可容得下十马并驰。往西通向
金城郡，相当于今天的兰州一带，往东则直达大唐国都长安城。

LONG);

  set("exits", ([
        "east" : "/d/city/ximen",
        "west" : __DIR__"west2",
        //"southwest" : "/d/emei/wdroad",

      ]));
  set("outdoors", __DIR__);

  set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
  setup();
}






