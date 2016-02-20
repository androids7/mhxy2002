//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//部分优化

inherit ROOM;

string* books = ({
        "laozi1",
        "daodejing-i",
        "laozi2",
        "daodejing-i",
        "laozi8",
        "daodejing-i",
        "laozi13",
        "laozi1",
        "laozi16",
        "daodejing-i",
        "laozi18"
});

void create()
{
        set("short", "藏经阁");
        set("long", @LONG
这里是藏经阁，靠墙是一排书架，摆满了道教的典籍。中央有一个长方
形的大桌子，上面也堆满了书。一个道童正在整理书籍。
LONG );
        set("exits", ([
                "southdown" : __DIR__"xilang",
        ]));
        set("objects", ([
                __DIR__"npc/daotong" : 3,
                "clone/book/"+books[random(sizeof(books))] : 1,
                "clone/book/"+books[random(sizeof(books))] : 1
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
