// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("木牌", ({ "木牌","大木牌", "mupai", "tablet" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", "你掀开木牌上的黑布，露出一块匾，和五个金光灿燎的字:
                          
                          [37;41m*[33m   天 下 第 一 剑[37;41m   *[0m
                         
谢王孙说道：“这是自古以来，江湖中从来没有人得到过的荣誉，谢家的子孙，一直都对它很珍惜，也很惭愧。
因为现在谢家的子孙就没有一个能配得上这五个字。”\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		
	}
}
