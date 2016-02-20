// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "家教服务中心");
  set ("long", @LONG

        这里你可以输入 [1;32m  teach [m 就可以教小朋友学习拉。

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"syroad6",
]));

        setup();
}

void init()
{
                add_action("do_work","teach");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-6);
        ob->add("hen/dirty",4);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        
        cat(TEACH);

        if( time() - ob->query("hen/last_teach") < 180 )
        {
        write("看来小鸡很讨厌重复做同一件事情。\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",100+random(20));
        ob->add("hen/mold",1);
        ob->add("hen/might",1);
        ob->set("hen/last_teach",time());
        
        return 1;
}
