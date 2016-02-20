
#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name(HIY "秦琼金装锏" NOR, ({"gold mace", "mace", "goldmace", "jinjian"}));
  set_weight(14000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 0);
    set("no_give", 1);
    set("no_sell", 1);
    set("no_get", 1);
    set("no_put", 1);
    set("material", "gold");
    set("long", "秦家祖传的金装锏，在沙场上为秦琼立下了汉马功劳。\n");
    set("wield_msg", "$N抽出了$n，喃喃道：锏儿，锏儿，再请你一回！\n");
    set("unwield_msg", "$N收起了$n，长吁了一口气道：宝锏果然又显雄风！\n");
  }
  
  init_mace(50);
  setup();
}

