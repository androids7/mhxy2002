// mihoutao.c 特大号猕猴桃
//by tianlin 2001.5.1这个桃吃了张10点force和mana我觉着这样挺好的,以前的那个桃吃了才一点,没什么大用.(xixi)
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIY"百年"+NOR+YEL"猕猴桃"NOR, ({"mihou tao","mihoutao","tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "[1;33m黄橙橙的一颗猕猴桃，真叫人垂涎欲滴。[2;37;0m\n");
    set("value", 5000);
    set("drug_type", "补品");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_force(100);
  me->add_maximum_mana(100);
  message_vision(HIG "$N一口就吃下了这颗弥猴桃，差一点撑死，不过的确是好吃！ \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
