// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "鸡窝总部");
  set ("long", @LONG

        如果你日常生活中不想把小鸡带在身上，可以把小鸡（[1;32mfang[m）在这，
    要是你想念你的小鸡，就到这呼唤（[1;33mhuhuan[m）你的宝贝吧！

LONG);
  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"room",
]));

        setup();
}

void init()
{
        add_action("do_fang","fang");
        add_action("do_huhuan","huhuan");

}
int do_fang()
{
        object ob = this_player();
        object where = this_object();
        object hen = present("zhandou ji",ob);

      if(!hen) return notify_fail("你身上没鸡,放什么放! \n");

        ob->command_function("kiss_hen");
        tell_room(where,ob->name()+"和他的小鸡吻别拉*^_^*\n");
        destruct(hen);
        return 1;
}

int do_huhuan()
{
        object ob = this_player();
        object where = this_object();
        object hen = present("zhandou ji",ob);
        object newhen=new(__DIR__"npc/hen");

        if(  hen ) 
                return notify_fail("小鸡不在你身上吗？\n");

        if(! ob->query("hen") )
                return 0;

        newhen->move(ob);
        tell_room(where,"小鸡见到"+ob->name()+"，一下就跳到"+ob->name()+"的怀里。\n");
        return 1;
}
        
