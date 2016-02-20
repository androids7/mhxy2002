#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"巧克力"NOR, ({ "choclate","qiao ke li","qiao" }) );
        set("long",
HIB"这是巫师为大家准备的圣诞巧克力的，颜色鲜艳，让人垂涎欲滴!\n"NOR);
        set("unit", "颗");
        set("weight", 300);
        set("value", 0);
	set("no_give",1);
	set("no_put",1);
	set("no_drop",1);
  setup();
}

int init ()  
{   
  add_action ("do_eat", "eat");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_eat (string arg)
{
  string *hows = ({
    "万般幸福地",
    "鬼鬼祟祟地",
    "红光满面地",
    "乐滋滋地",
    "极为严肃地",
    "点头哈腰地",
    "感激涕淋地",
    "板着脸",
    "激动得浑身颤抖，",
    "庄严地看着大家，然后勇敢地",
    "呲牙咧嘴地",
    "秀里秀气地",
    "满脸狐疑地",
    "翻翻白眼，",
    "摇头晃脑地",
    "抿嘴一笑，",
    "饿狼一样",
    "笨手笨脚地",
    "肥头肥脑地",
    "满脸堆笑故作正经地",
    "推开众人，摆好架式，",
    "油头粉面地",
    "兴奋得满头大汗，",
    "面黄肌瘦地",
    "抹去眼角的泪花，",
    "撮撮手，一跺脚，",
    "张牙舞爪地",
    "十分谦虚地",
    "羞得满脸通红，",
  });

  string *manners = ({
    "把$n在手心里反复撮了几下，",
    "把$n在地上疯狂地跺扁，",
    "把$n在墙上嘭地一声砸开，",
    "把$n在心口仔细暖了一下，",
    "把$n往油锅里迅速一炸，然后",
    "亲了亲$n，",
    "使劲撕开$n，一点一点地",
    "在$n的外面抹上一层红红的蕃茄酱，",
    "拿起$n蘸着厚厚的红糖，",
    "在$n上撒了一大把盐，",
    "把$n拿起就着两片酸黄瓜，",
    "把$n在酱油里一蘸，品着味",
    "把$n在辣酱里点了一点，咝咝地",
    "把$n在开水里一泡，趁热",
    "把$n在火上一燎，赶紧",
    "用一副刀叉切开$n，",
    "用竹筷夹起$n",
    "含一口绍兴酒喷在$n上，",
    "把$n用自来水洗得干干净净，",
    "在$n上舔了半天，",
    "在$n上撒一层榨菜丝，",
    "在$n上裹一层火腿奶酪，",
    "把$n和葱姜蒜末拌在一起，",
    "把$n捣碎，拌上生菜，",
    "把$n切成小块，加上鸡丁花生热热地在油锅里炒成宫保$n，",
    "把$n放进锅里，加上酱油红糖小火炖成红烧$n，",
    "把$n放在在锅里倒醋撒糖芡成一盘糖醋$n，",
  });

  string *actions = ({
    "张开樱桃小口吞了下去",
    "用两片大嘴唇咬住只一吸就咽了下去",
    "一歪嘴巴吞了下去",
    "再往嘴里乒乒乓乓一扔",
    "皱着眉头痛心疾首地吃了下去",
    "望天上一扔，伸出脖子叭地一声接住",
    "往嘴巴用力使劲里一塞",
    "硬着头皮贼喊捉贼地吃了下去",
    "吧嗒吧嗒贼眉鼠眼地吃了下去",
    "含在嘴里如火如荼热气腾腾地吞了下去",
    "有滋有味连手指都吃了下去",
    "嚼都没嚼就伸脖踮脚地咽了下去",
    "肥肥地往下一吞",
    "唏唏溜溜就岔着气吃下了肚子",
    "一点点咬着吃了岔了气",
    "张开血盆大口，倒拎着往嘴里一扔",
    "吃得神经错乱眼冒金星",
    "吃得如痴如狂东倒西歪",
    "吃得神采奕奕情窦大开",
    "吃得神魂颠倒四面楚歌",
    "吃得翻肠倒肚天昏地暗",
    "狼吞虎咽地反反复复左嚼右嚼咽了下去",
    "咔嚓咔嚓地大嚼了起来，只一会儿就整个连假牙都咽了下去",
    "痛苦不堪地吃了下去",
  });

   int bonus;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

  message_vision ("$N"+rdm(hows)+rdm(manners)+rdm(actions)+"。\n",
                  this_player(),this_object());
	  bonus=random(this_player()->query("combat_exp")/800);
	if (!this_player()->query_temp("xmas"))
	this_player()->set_temp("xmas",1);
	bonus=bonus/this_player()->query_temp("xmas");
	bonus=bonus*(this_player()->query("kar")/30);
  this_player()->add("potential",bonus);
write(HIR+"你得到了"+chinese_number(bonus)+"点潜能!\n"NOR,
               environment(this_player()), this_player());
   this_player()->add_temp("xmas",1);
  destruct(this_object());
  return 1;
}
