// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "商业街");
  set ("long", @LONG

        这里非常热闹，有教堂，酒吧，教堂，你在这可以赚到很多的
    钱，只要你肯干活，赚钱是没有问题的拉，北面可以[1;36m做些家务活[mw，
    在南面你可以给别人[1;36m当保姆[m。

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"road4",
         "west": __DIR__"syroad2",
          "north": __DIR__"jiawu",
         "south": __DIR__"baomu",
]));

        setup();
}
