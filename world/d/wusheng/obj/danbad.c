//by tianlin@mhxy 2001.7.4

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "[1;30m一颗坏了的无名果[2;37;0m" , ({"wuming guo", "guo"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗长霉的无名果，上面全是绿毛。\n");
    set("value", 0);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="wuming guo" && arg!="guo") 
    return 0;
  
  tell_object(me, "坏药还能吃吗？\n");
  return 1;
}

