//by tianlin 2001.5.1
//有一个指令我已修改过.就bigu这个指令,我已加入在xfull里面了.
#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;


void create()
{
        set_name(WHT"格斗之王全集"NOR, ({"book"}) );
        set_weight(10);
        set("no_steal", 1);
        set("no_beg", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_drop","哇？天书都想丢掉,小心遭天谴。\n\n");
        set("long",@LONG
这是八神庵留下来的一本书,其作用可大了,有意者请(kan)就行了!
LONG );
        if( clonep() )
                        set_default_object(__FILE__);
        else
       {
                set("unit", "本");
                set("material", "unknow");
        }
}

void init()
{
        add_action( "kan_book", "kan" );
        add_action( "body_recover", "xfull");
//   add_action( "cloud_goto", "flyto")
}

/* int query_autoload()
{
        return 1;
}*/

//介绍
int kan_book()
{
        object me;
        me=this_player();
        tell_object(me,
    "法诀�                    功能

一千百八式八织女(xfull)           立马恢复精神体力\n

筋斗云(flyto)         到想去的地方\n");
        return 1;
}

// 筋斗云

int cloud_goto(string arg)
{
        string home;
        object mme;
        int goto_inventory = 0;
        object obj;
        string msg;
        mme=this_player();
        if( !arg ) return notify_fail("你要去哪里？\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("你要去哪里？\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !mme->visible(obj)) {
                arg = resolve_path(mme->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return mme->move(arg);
                        return notify_fail("没有这个玩家、生物、或地方。\n");
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");
        tell_object(mme,HIM"你一个筋斗窜向空中,只见眼前红云飞过,耳边风呼呼作响 .
.\n\n"NOR);
        tell_object(mme,"哇喔,好痛快,好爽,爽歪歪!\n\n");
        mme->move(obj);

        tell_object(mme,"你驾着云缓缓下降,叭叽一声,嘿!安全着陆...\n");
        return 1;
}
// 恢复
int body_recover()
{
    object mme;
    mme=this_player();
    mme->set("sen",mme->query("max_sen"));
    mme->set("eff_sen",mme->query("max_sen"));
    mme->set("kee",mme->query("max_kee"));
    mme->set("eff_kee",mme->query("max_kee"));
    mme->set("force",mme->query("max_force"));
    mme->set("mana",mme->query("max_mana"));
    mme->set("food",mme->max_food_capacity()*2);
    mme->set("water",mme->max_water_capacity()*2);
    tell_object(mme,"哇喔,太好了,你觉得全身都是[5m[1;36m力量![2;37;0m\n");
    return 1;
}
void owner_is_killed() {

        write(HIY"只见眼前金光一闪...好象是.....\n"NOR);
        destruct(this_object());
}
