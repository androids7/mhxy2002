// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//ximenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "[33m西门厅[m");
        set("long", @LONG
现在整修中。
LONG
        );
 
        set("exits", ([
                "west" : __DIR__"xitian",
        ]));
 
        create_door("west", "西天门", "east", DOOR_CLOSED);
 
        set("objects", ([
                __DIR__"npc/tong-nan" : 2,
        ]));
 
        setup();
}
