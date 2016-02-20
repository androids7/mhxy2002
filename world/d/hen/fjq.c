// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "风景区");
  set ("long", @LONG

        风景多美啊，如果不介意的话，请欣赏（[1;36menjoy[m）吧！

LONG);
  set("exits", ([ /* sizeof() == 4 */
        "west": __DIR__"road6",
]));

        setup();
}

void init()
{
        add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
        object ob = this_player();
        int i = 300 + random(100);

        if( ob->query("hen/money") < i )
                return notify_fail("你的钱不够用拉。\n");

        ob->command_function("cls");
        ob->command_function("shape");
        ob->add("hen/money",-i);
        ob->add("hen/happy",9);
        ob->add("hen/satisfy",9);
        ob->add("hen/affection",1);
        switch(random(4))
        {
                case 0:
                cat(TOUR1);
                break;
                
                case 1:
                cat(TOUR2);
                break;

                case 2:
                cat(TOUR3);
                break;
                
                case 3:
                cat(TOUR4);
                break;

        }
        return 1;
}
