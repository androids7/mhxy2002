//by tianlin 2001/5/1
//By tianlin@mhxy for 2001.12.29从新修改
#include <ansi.h>
inherit ITEM;
int do_open(string arg);
void create()
{
  set_name(HIR "礼物" NOR,({"gift"}));
  set("long","这是一份礼物，你可以试着打开("+HIG+"open"+NOR+")来看看。");
  set("unit","份");
  set("value", 0);
  setup();
}

void init()
{
   if (!wizardp(this_player())) {
    set("no_get","这个东西拿不起来。\n");
    set("no_give","这么珍贵的东西，哪能随便给人？\n");
    set("no_drop","这么宝贵的东西，扔了多可惜呀！\n");
    set("no_sell","这东西不能卖。\n");
   }
    if(this_player()==environment())
  add_action("do_open", "open");

}

int do_open(string arg)
{
  object yudi;
  object obj;
  object guai,bi,bonnet;
  object me=this_player();
  if (!arg && arg!="liwu") return notify_fail("你要打开什么?\n");
  if (me->query("newbie_liwu")) return notify_fail("你已经拿过礼物了，怎么还想要？\n");
  message_vision(HIG"$N把礼物盒轻轻的打开，一道光芒从天而降，$N被这光芒包住，$N觉得浑身充满了力量!\n" NOR,me);

  me->add("potential",100000); 
  me->add("combat_exp",80000); 
  me->add("daoxing",16000); 
  me->add("force",400);
  me->add("max_force",400);
  me->add("max_mana",400);
  me->add("mana",400);
  me->add("maximum_force",400);
  me->add("maximum_mana",400);
  me->add("bellicosity",100); 
  me->add("rsg_eaten",16);  
  me->add("faith",500);  
  me->add("weiwang",100);  
 // me->set_skill("force",40);
//  me->set_skill("dodge",40);
//  me->set_skill("parry",40);
 // me->set_skill("sword",60);
 // me->set_skill("staff",60);
 // me->set_skill("spells",40);
 // me->set_skill("stick",60);
//  me->set_skill("unarmed",60);
//  me->set_skill("literate",40);
 // me->set_skill("archery",60);
//  me->set_skill("rake",60);
 // me->set_skill("whip",60);
 // me->set_skill("zouxiao",60);
//  me->set_skill("axe",60);
 // me->set_skill("mace",60);
 // me->set_skill("spear",60);
 // me->set_skill("throwing",60);
//  me->set_skill("blade",60);
 // me->set_skill("fork",60);
 // me->set_skill("hammer",60);
 // me->add("mud_age",86400);//给玩家加上1天的mudage.by tianlin
  tell_object(me,HIW"你被奖励了：\n" +
  chinese_number(80000) + "点实战经验。\n"+        
  chinese_number(100000) + "点潜能。\n"+
  chinese_number(16)    + "年道行。\n"+ 
  chinese_number(100) + "点杀气。\n"+
  chinese_number(100) + "点门派威望。\n"+
  chinese_number(500) + "点门派忠诚度。\n"+
  chinese_number(400) + "点内力。\n"+
  chinese_number(400) + "点法力。\n"+
 // chinese_number(5) + "种基本技能。\n"+
  "十六个人参果,请用score2查看！\n"NOR+BLINK+HBRED+HIW"以及三种法宝!请珍惜使用.\n" NOR);
 
  me->set("newbie_liwu",1);
  yudi = new("/d/dntg/sky/npc/yuhuang.c");
  yudi->command_function("rumor 听说一个名叫[37m"+me->name()+"[2;37;0m[1;35m的人，得到了[1;33m礼物包[2;37;0m[1;35m，开始了他的生涯...[2;37;0m\n");
  guai = new ("/u/tianlin/wuqi/gift/guai");
  guai->move(this_player());
  bi = new ("/u/tianlin/wuqi/gift/bi");
  bi->move(this_player());
  bonnet = new ("/u/tianlin/wuqi/gift/bonnet");
  bonnet->move(this_player());
  destruct(yudi);
  destruct(this_object());
  return 1;
}

