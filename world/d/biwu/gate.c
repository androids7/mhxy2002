inherit ROOM;

void create()
{
	set("short", "比武大会正门");
	set("long", @LONG
这是比武大会的正门口,各路武林人士云集此处，大家个个摩拳
擦掌，跃跃欲试。两名锦衣卫一左一右的站在大门口，维持着比武大
会的秩序。公平子也在这负责大会的正常进行。巍峨的大门上高悬着
朝廷皇帝[0;5;37m�[5m�[5m�[5m�[0m御赐的金匾。旁边有块牌子（ｓｉｇｎ），你真的很想
读一下它（ｌｏｏｋ　ｓｉｇｎ）。

[35m                      以  武  会  友[0m

[35m                      点  到  为  止[0m

LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "正在写
正在写
正在写
正在写
",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard2" : 2,
]));
	set("no_magic", 1);
	set("no_beg", 1);
	set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"guodao",
]));
	set("no_fight", 1);
	set("no_clean_up", 0);
        setup();
}

void init()
{
   add_action("do_quit", "quit");
}
int do_quit()
{
  write("你在比武大会期间不能退出．．．．！\n");
  return 1;
}

