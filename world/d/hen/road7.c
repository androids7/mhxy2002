// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "鸡窝走道");
  set ("long", @LONG

        你走在鸡窝的走道上，到处都是鸡叫的声音，东面有一家[1;32m医院[m
    ，西面有个[1;32m媚登峰[m，千万不要错过哦。

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"yy",
         "west": __DIR__"mdf",
          "north": __DIR__"road6",
         "south": __DIR__"jw",
  ]));

        setup();
}
