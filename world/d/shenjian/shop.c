//By tianlin@mhxy for 2001.10.10
inherit ROOM;

void create ()
{
        set ("short", "物品店");
        set ("long", @LONG

    刚进来，你第一眼看到的就是那赫赫有名的招牌：
[36m
                □□□□□□□□□
                □[m[41m[1;30m    物品店    [2;37;0m[36m□
                □□□□□□□□□
[m
这里的物品十分齐全,各式各样的都有,有兵器,装备,道具
是样样齐全,而且价格十分便宜.
LONG);

        set("exits",
        ([ //sizeof() == 4
                "south": __DIR__"road",
      ]));
      set("objects", ([
                __DIR__"npc/wupin" :1,
                ]));

      set("outdoors", "shenjian");
      set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

