// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "鸡窝走道");
  set ("long", @LONG

        你走在鸡窝的走道上，到处都是鸡叫的声音，东面是个[1;32m公园[m
    可以去散散步，西面是一个[1;32m运动场[m。

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"gy",
         "west": __DIR__"ydc",
          "north": __DIR__"road4",
         "south": __DIR__"road6",
]));

        setup();
}
