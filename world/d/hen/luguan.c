// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "旅馆");
  set ("long", @LONG

        这里你可以输入 [1;32m serve [m 在旅馆当服务生拉。

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"syroad2",
]));

        setup();
}

void init()
{
                add_action("do_work","serve");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-2);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",5);

        cat(HOTEL);

        if( time() - ob->query("hen/last_hotel") < 180 )
        {
        write("看起来老板的脸色不太好看。\n");
        write("看来小鸡很讨厌重复做同一件事情。\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",100+random(20));
        ob->add("hen/evaluation/homework",1);
        ob->set("hen/last_hotel",time());

        return 1;
}
