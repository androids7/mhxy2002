// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  string name = "��Ƥ��Ѽ";
  set_name(name, ({"cuipi kaoya", "kaoya", "ya"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�����˴��ѵ�"+name+"��\n");
    set("unit", "��");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 25);
  }
}
