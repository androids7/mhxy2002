// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// worker.c

inherit NPC;
#include <ansi.h>

string *msg = ({
        "新手多多help拉，如help news,help task,help joball！\n",
        "我们的主页地址是 http://yszz.myrice.com,欢迎访问！\n",
        "help chat里面有本MUD最cool的聊天室！\n",
        "help MHXY里面有关于MUD的最新变化！\n",
        "help zichuang有梦幻西游的自创武功系统\n",
        "help mieyao当然就是杀怪系统了。\n",
        "真正的门派争斗与此开始， help shili ！\n"
        });

void create()
{
        set_name("梦幻西游", ({"mhxy"}));
        set("gender", "男性" );
        set("age", 13);
        set("title", "[1;32m梦幻西游迎客小童[m");
        set("long", "一个可爱的小童，每天负责在这里迎接远道而来的客人．\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 1500000);
        set("kee",1500000);
        set("sen",1500000);
        set("max_sen", 1500000);
        setup();
        remove_call_out("msg");
        call_out("msg",300);
}

void msg()
{
        command_function("es "+NOR+HBRED+msg[random(sizeof(msg))]+NOR);
        
        remove_call_out("msg");
        call_out("msg",300);

}
