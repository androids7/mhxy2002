//Cracked by Roath
//by tianlin 2001/5/1
#include <ansi.h>
#define LAST_PAR "bc"
#define THIS_PAR "bcsf"
inherit ITEM;
void create()
{
    set_name(HIG"礼物台"NOR, ({ "table"}));
    set_weight(5000000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("no_get","这个台子是巫师给玩家发礼物的，你不能偷走");
        set("long","一个巨大无比的礼物台，上面放满了发给大家的礼物，趁着没去掉大家快拿礼物(take gift)啊！");
        set("value", 0);
        set("material", "stone");
    }
}
void init()
{
    add_action("do_pick", "take");
}
 
int do_pick(string arg)
{
       object me,obj;
       me = this_player();
       if( !arg || arg!="gift" ) return notify_fail("你要拿什么？\n");

 //      return notify_fail("现在没有礼物拿。\n");

       if (me->query(THIS_PAR + "_pick")) {
       tell_object(me,CYN "水中月的身影突然出现在一阵烟雾之中。\n\n");
       tell_object(me,HIR "水中月一巴掌敲在你手上：小朋友，不要太贪心哦！每人只有一份礼物！\n\n");
       tell_object(me,CYN "只见一阵烟雾过後，水中月的身影已经不见了。\n" NOR);
       return 1;
       }
      obj = new (__DIR__"gift");
      obj->move(me);
       message_vision("$N从[1;32m礼物台[2;37;0m上拿了一个[1;33m礼物包[2;37;0m。\n",me );
//每次拣礼物，都将上次的参数消除，增加本次拿的参数。 
       me->delete(LAST_PAR + "_pick");
       me->set(THIS_PAR + "_pick",1);
       return 1;
}

