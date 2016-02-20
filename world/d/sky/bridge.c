// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/qujing/wudidong/temple-qiandian.c
// created 6-20-97 pickle
inherit ROOM;

void create ()
{
  set ("short", "[37m白玉桥[m");
  set ("long", @LONG

一座用上好的滇池白玉所造的小桥,桥身如虹,上面还刻着一些
不知道描述什么的图画.桥的两旁是一条清澈的小河,河上星星点点
地生着一些彩莲,几对鸳鸯在河中悠闲的游着,偶尔也能看见一两只
仙鹤从桥上飞过,桥的北面(north)就是灵霄宝殿了。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : "一袭碧绿的门帘，触之冰凉，可以偷偷揭开(jie)看看里面的模样。
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nanmenting.c",
  "north" : __DIR__"dadian",
]));
  set("light_up", 1);

  setup();
}

void init()
{
  add_action("do_knock", "jie");
}

int do_knock()
{
  object me=this_player();
  string myrespect=(string)RANK_D->query_respect(me);

  if (me->query("obstacle/sky") != "done")
//   if (!me->query_temp("zhanyao_asked"))  
{
  
  message_vision("$N轻轻的揭开挂帘，朝里面看了看。\n", me);
  message_vision("$N见没人发现，就偷偷的溜了进去，紧张的脸上露出一丝笑容。\n", me);
  me->move(__DIR__"dianmen");
  return 1;
   }
  message_vision("$N一把扯下了挂帘，大喝一声，冲了进去。\n",me);
  me->move(__DIR__"dianmen2");
  return 1;
}






