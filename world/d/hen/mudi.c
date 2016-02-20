// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "墓地");
  set ("long", @LONG

        这里你可以输入 [1;32m shou_mu [m 到墓地锻炼勇气：-（。

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"syroad6",
]));
        setup();
}

void init()
{
                add_action("do_work","shou_mu");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-8);
        ob->add("hen/happy",-6);
        ob->add("hen/satisfy",-6);
        ob->add("hen/dirty",12);

        cat(BURY);

        if( time() - ob->query("hen/last_mudi") < 180 )
        {
        write("看来小鸡很讨厌重复做同一件事情。\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",300+random(20));
        ob->set("hen/last_mudi",time());
        ob->add("hen/brave",2);
        ob->add("hen/anticmagic",1);
        return 1;
}
