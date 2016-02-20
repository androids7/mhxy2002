// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "草地");
  set ("long", @LONG

        一片绿荫荫的草地绝对是约会（[1;36mdate[m）的好地方哦。

LONG);
  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"jw",
]));

        setup();
}

void init()
{
        add_action("do_date","date");
}

int do_date()
{
        object ob = this_player();
        int i = 100 + random(50);

        if( ob->query("hen/money") < i )
                return notify_fail("没有钱也去约会？\n");

        ob->command_function("cls");
        ob->command_function("shape");
        ob->add("hen/money",-i);
        ob->add("hen/happy",12);
        ob->add("hen/life",-5);
        ob->add("hen/satisfy",12);
        ob->add("hen/dirty",8);
        ob->add("hen/affection",-1);
        cat(DATE);
        return 1;
}
