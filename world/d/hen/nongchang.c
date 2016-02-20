// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "农场");
  set ("long", @LONG

        这里你可以输入 [1;32m zuo_kuli [m 在农场当苦力拉。

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"syroad2",
]));

        setup();
}

void init()
{
                add_action("do_work","zuo_kuli");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-10);
        ob->add("hen/happy",-6);
        ob->add("hen/satisfy",-6);
        ob->add("hen/dirty",10);

        cat(FARM);

        if( time() - ob->query("hen/last_farm") < 180 )
        {
        write("看来小鸡很讨厌重复做同一件事情。\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",300+random(20));
        ob->set("hen/last_farm",time());
        ob->add("hen/max_life",1);
        ob->add("hen/mold",-1);
        return 1;
}
