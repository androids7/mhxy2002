// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "科学教室");
  set ("long", @LONG

        这里你可以输入 [1;32mxue_kexue [m 来学习科学。
LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"xxroad1",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_kexue");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/might") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m〔初级〕[m";
        }

        if( ob->query("hen/might") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m〔中级〕[m";
        }

        if( ob->query("hen/might") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m〔高级〕[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("你的钱不够学习科学。\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/dirty",5);
        ob->add("hen/satisfy",-4);

        switch(random(2))
        {
                case 0:
                cat(STUDY1);
                write("我是聪明的鸡。\n");
                break;
                case 1:
                cat(STUDY2);
                write("用功读书中.....\n");
                break;
        }
        write("你花了 "+fee+" 元学习科学"+lv+"课程。\n");
        ob->query("hen/might")<50000?ob->add("hen/might",5+random(2)):
        ob->set("hen/might",50000);
        return 1;
}
