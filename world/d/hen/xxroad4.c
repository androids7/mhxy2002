// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "大学路");
  set ("long", @LONG

        这里全是学习的地方，有学文，也有学武的，不过这都不是
    义务教育，全部要收费的哦，南面是学习[1;44m礼仪[m的，北面是学习[1;44m魔法[m的。

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"xxroad5",
         "west": __DIR__"xxroad3",
          "north": __DIR__"magic",
         "south": __DIR__"liyi",
]));

        setup();
}
