
inherit ITEM;

void create()
{
        set_name("药材车", ({ "cart"}) );
        set_weight(300000);
        set("no_get", 1);
        set_max_encumbrance(80000000);
	set("unit", "辆");
	set("long", "一辆黑漆漆的药材车，里面满满装着珍贵药材。\n");
	set("closed", 1);
	set("value", 2000);
    
}

int is_container() {return 1;}

void init()
{
	 add_action("do_open","open");
	 add_action("do_close","close");
}

int do_close(string arg)
{
	object		me, ob;

	me = this_player();
	ob = this_object();
        if(arg != "cart" )
                return notify_fail("你要关上什么？\n");
       	message_vision("$N把$n门关上了。\n", me, ob);
	ob->set("closed",1);
	return 1;
}

int do_open(string arg)
{
	object		me, ob;
	
    if(arg != "cart" )
    	return notify_fail("你要打开什么？\n");
	me = this_player();
    if (objectp(ob=present("drug daoshi",environment())))
    	return notify_fail(ob->name()+"瞪了你一眼，你要干什么！\n");
	this_object()->set("closed",0);
       	message_vision("$N将$n盖打开。\n", me, this_object());
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
