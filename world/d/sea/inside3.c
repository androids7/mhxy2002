// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// inside3.c
#include <ansi.h>
void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_serve();
inherit ROOM;

void create ()
{
  set ("short", "[33m龙宫正殿[m");
  set ("long", @LONG

正殿之上悬一明珠，把诺大一殿照得通亮。两旁桌椅玉石打造而成，　　
当中还嵌着无数珠宝。两边墙上挂了两幅画，看起来相当的陈旧。　　　
南北是两座偏殿。如果龙王累了，你还可以给他服务一下。(serve)

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"inside2.c",
  "east" : __DIR__"inside4",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/longwang" : 1,
]));
  setup();
}

void init()
{
   object where=this_object();

  remove_call_out("check_time");
   check_time(where);
   add_action("do_serve","serve");
}

void check_time(object where)
{
   mixed *local = localtime(time()*60);
   int t = local[2] * 60 + local[1];
  int phase=((int)(t/120));
if((phase==1)&&(!query("hungry"))) feel_hungry(where);
if((phase==2)&&query("hungry")) feel_full(where);
   call_out("check_time",60,where);
}

void feel_hungry(object where)
{
message("channel:chat",CYN+"◇"HIC"东海龙宫"NOR+CYN"◇"NOR+WHT"敖广(Ao guang)："CYN"朕累了，有人来服务吗？"HIR"(Serve)\n"+NOR,users());
   set("hungry",1);
}
void feel_full(object where)
{
tell_object(where,"东海龙王笑道：很好，很好。\n");
  set("hungry",0);
}
int do_serve()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("hungry"))
      return notify_fail("东海龙王道：我现在不累！\n");
   if((string)me->query("family/family_name")!="东海龙宫")
      return notify_fail("东海龙王道：不敢劳您大驾！\n");
   if(me->query("faith")>400||me->query("combat_exp")>100000)
      return notify_fail("您是我们龙宫有身份的人，这样的事就让小辈们做吧。\n");
   tell_object(me,"你给龙王又是捶，又是掐的，把龙王服务的直叫痛快！\n");
   me->start_busy(5);
      me->add("faith",1);
   me->add("combat_exp",9);
   me->add("potential",3);
   me->improve_skill("seashentong",100);  
   me->receive_damage("kee",40);
   me->receive_damage("sen",40);
   return 1;
}
