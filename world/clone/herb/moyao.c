// moyao.c

#include "herb.h"

void create()
{
	set_name(WHT "没药" NOR, ({ "moyao", "herb_moyao" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "根");
		set("value", 300);
        	set("weight", 50);
set("base_unit","根");
	}
	setup();
}
