// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "[31m瓜[32m果[33m蔬[35m菜[36m店[m");
  set ("long", @LONG

这家蔬菜店位于小村的路口之上,虽然店面不大,可买的蔬菜瓜果
的品种倒是不少,加上买菜大嫂态度和蔼,生意倒也红火.

LONG);
  set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"entrance",
]));
  set("objects",([
        __DIR__"npc/maicaide":1,
        ]));
  set("outdoors", "1");

  setup();
}
