inherit ROOM;

void create()
{
	set("short", "比武大会会场");
	set("long", @LONG
[33m            ※※※※※※※※※※※※※※※※※[0m
[33m                ※                              ※[0m
[33m                ※ [35m 打  遍  天  下  无  敌  手[33m  ※[0m
[33m                ※                              ※[0m
[33m                ※※※※※※※※※※※※※※※※※[0m

[33m        ※※※※※                              ※※※※※[0m
[33m        ※      ※                              ※      ※[0m
[33m        ※  [36m脚[33m  ※                              ※  [36m拳[33m  ※[0m
[33m        ※      ※                              ※      ※[0m
[33m        ※  [36m踢[33m  ※  [0m这里是风云比武大会的主会场。[33m※  [36m打[33m  ※[0m
[33m        ※      ※                              ※      ※[0m
[33m        ※  [36m北[33m  ※  [0m从这里可以看到上面的大擂台。[33m※  [36m南[33m  ※[0m
[33m        ※      ※                              ※      ※[0m
[33m        ※  [36m海[33m  ※  [0m擂台上面挂着一幅很大的对联。[33m※  [36m山[33m  ※[0m
[33m        ※      ※                              ※      ※[0m
[33m        ※  [36m蛟[33m  ※  [0m擂台旁有一块牌子(sign)。[33m    ※  [36m猛[33m  ※[0m
[33m        ※      ※                              ※      ※[0m
[33m        ※  [36m龙[33m  ※                              ※  [36m虎[33m  ※[0m
[33m        ※      ※               ------ [0;5;37m林雪[0;33m题  ※      ※[0m
[33m        ※※※※※                              ※※※※※[0m

LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "比武须知:
    jump 跳上擂台
待续
",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/referee" : 1,
]));
	set("no_beg", 1);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"leitai",
  "out" : "/d/city/center.c",
  "north" : __DIR__"ready",
//  "south" : __DIR__"guodao3",
]));
	set("no_clean_up", 0);
	set("no_death_penalty", 1);
        setup();
}

void init()
{
   add_action("do_quit", "quit");
     add_action("do_gogo", "out");
}
int do_quit()
{
  write("你在比武大会期间不能退出．．．．！\n");
  return 1;
}

int do_gogo()
{
        object me;
        me = this_player();
        me->set_temp("marks/allow_biwu",0);
        return 0;
}
