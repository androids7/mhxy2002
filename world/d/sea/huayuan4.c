// Room: /u/rainy/sea/huayuan4.c
inherit ROOM;

void create ()
{
  set ("short", "御花园");
  set ("long", @LONG

花园之中的草木并不繁盛，但细瞧去都是些在凡间难得一见的珍品　　　
异种，花间有些奇异的小鱼游动，为花园添了几分情趣。后宫中来　　　
往人较少，远没有前殿的那种喧嚣。
LONG);
          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beinu" : 1,
]));

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"huayuan5.c",
  "west" : __DIR__"huayuan3",
]));
//      
        set("water", 1);
//  
  setup();
}
