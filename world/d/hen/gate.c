// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "赛场大门");
  set ("long", @LONG

         这里通向各个比武赛场，如果你养了星空战斗鸡不来一展
     你的小鸡的风彩，真是太遗憾了，当然了，如果你在比赛中获胜
     会有大奖的，比赛每[1;32m五[m小时举行一次。

LONG);

  set("outdoors", "changan");
  set("exits", ([ /* sizeof() == 4 */
         "north" : __DIR__"jw",
         "enter":__DIR__"baoming",
]));

        set("no_clean_up",1);
        setup();
}

