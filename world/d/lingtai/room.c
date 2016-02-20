// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "[0;31m瑶台[m");
  set ("long", @LONG

一座瑶台高高在上，见那菩提祖师端坐在台上，两边有三十个小
仙侍立台下。周围摆设全是仙家器具，有一种说不出的祥和，又
透着庄严。
LONG);
set("exits", ([ /* sizeof() == 4 */
"out": __DIR__"houlang5",
"north":__DIR__"taiji",
]));
set("objects", ([
                __DIR__"npc/puti": 1 ]) );
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me,string dir)
{
  if(dir=="north")
     if(me->query("class")!="taoist")return notify_fail("你被一道金光逼了回来。\n");
     else if(me->query("faith")<8000)
            return notify_fail("你被一道金光逼了回来。\n");
        return ::valid_leave(me,dir);    
}
