
// create by qlwy 28/06/2001
// room: maojiao/entrance.c

inherit ROOM;

void create ()
{
        set ("short", "迷宫洞口");
        set ("long", @LONG

向北就是传说中的火迷宫了，你站在洞口都觉的热
气袭人。�

LONG);
        set("exits", 
        ([ //sizeof() == 2
//                "south" : __DIR__"xxx", 用于连接
                  "north" : __DIR__"hmg0",
        ]));
        setup();
}


