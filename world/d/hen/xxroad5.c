// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "大学路");
  set ("long", @LONG

        这里全是学习的地方，有学文，也有学武的，不过这都不是
    义务教育，全部要收费的哦，南面是学习[33m舞蹈[m的，北面是学习[1;33m绘画[0m的。

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "west": __DIR__"xxroad4",
          "north": __DIR__"huihua",
         "south": __DIR__"wudao",
]));

        setup();
}
