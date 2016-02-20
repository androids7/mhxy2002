// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "绘画教室");
  set ("long", @LONG

        这里你可以输入 [1;32mxue_huihua [m 来学习绘画课程。

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"xxroad5",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_huihua");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/art") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m〔初级〕[m";
        }

        if( ob->query("hen/art") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m〔中级〕[m";
        }

        if( ob->query("hen/art") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m〔高级〕[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("你的钱不够学习绘画课程。\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
	        ob->add("hen/dirty",5);


                cat(DRAW);

        write("你花了 "+fee+" 元学习绘画"+lv+"课程。\n");
        ob->query("hen/art")<50000?ob->add("hen/art",2):
        ob->set("hen/art",50000);
        ob->add("hen/feel",1);
        return 1;
}
