// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "[33m藏宝库[m");
  set ("long", @LONG

藏宝库里有一汉白玉案台，上有各类名式兵器,护甲。
看来现在你可以自由的拿取了！
台子上放有：
  金刚罩：          zhao
  伏魔刀：          dao
  菩提子：          zi
  倚天剑:           jian
  匕首:             bishou
  金丝宝甲:         jia          

LONG);

  set("exits", ([
        "south"   : __DIR__"neidian.c",
      ]));

  setup();
}

void init ()
{
  add_action ("do_take","take");
  add_action ("do_take","na");
}

int do_take (string arg)
{
  object who = this_player();
  object ob;


  if (! arg)
    return notify_fail ("您要拿什么？\n");
  if (arg == "zhao")
    ob = new ("/d/suburb/xkx/shaolin/obj/jingang-zhao");    
  else if (arg == "zi")
  ob = new ("/d/suburb/xkx/shaolin/obj/puti-zi");
  else if (arg == "dao")
    ob = new ("/d/suburb/xkx/shaolin/obj/fumo-dao");    
else if (arg == "jia")
ob = new ("/obj/baojia");
else if (arg == "jian")
ob = new("/d/suburb/xkx/working/obj/yitian-jian");
else if (arg == "bishou")
 ob = new ("/obj/bishou");
else
    return notify_fail ("您要拿什么？\n");


  message_vision ("$N从台上拿起$n。\n",who,ob);
  ob->move(who);


  return 1;
}



