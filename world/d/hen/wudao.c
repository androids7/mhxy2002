// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "舞蹈教室");
  set ("long", @LONG

        这里你可以输入 [1;32mxue_wudao [m 来学习舞蹈课程。

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"xxroad5",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_wudao");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/charm") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m〔初级〕[m";
        }

        if( ob->query("hen/charm") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m〔中级〕[m";
        }

        if( ob->query("hen/charm") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m〔高级〕[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("你的钱不够学习舞蹈课程。\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
	ob->add("hen/dirty",5);
	write("图片暂缺\n");
        write("你花了 "+fee+" 元学习舞蹈"+lv+"课程。\n");
        ob->query("hen/charm")<50000?ob->add("hen/charm",2):
        ob->set("hen/charm",50000);
	ob->add("hen/max_life",1);
	ob->add("hen/art",1);
        return 1;
}
