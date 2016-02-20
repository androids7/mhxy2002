// laozhe.c

#include <ansi.h>

inherit NPC;
int rank_me();
string ask_mieyao(object me);
string ask_cancel();

void create()
{
       set_name(HIG"老者"NOR, ({"lao zhe", "laozhe"}));
       set("long", "一个悠闲的老人家，坐在树下乘凉。\n");
       set("title", HIC"武帝门"NOR);
       set("gender", "男性");
       set("age", 1000);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "护法");
       set("looking", "英俊潇洒，玉树临风，风流倜傥。");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1000);
       set("max_force", 500);
       set("force_factor", 10);
       set("max_mana", 500);
       set("mana", 1000);
       set("mana_factor", 10);
       set("combat_exp", 500000);
       set("daoxing", 1100000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("feisheng", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("wuying", 100);
        set_skill("fumobashi", 100);  
        set_skill("mizongbu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("xiantian", 100);

        map_skill("spells", "feisheng");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");
        create_family("武圣门", 2, "弟子");

   set("inquiry", ([
//          "复仇" : (: avenge :),
//		  "醉生梦死" : (: give_zui :),
           "修炼": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
		   "职位": (: rank_me :),
]));
	setup();
	carry_object("/d/obj/armor/jinjia")->wear();

}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "掌门")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
        if( (string)me->query("family/family_name") == "武圣门"){
                if( exp <= 100000 ){
                        me->set("title", WHT"武圣门"HIG"修武者"NOR);
                 } else if(exp < 1000000 ){
                        me->set("title", WHT"武圣门"HIG"神力罗汉"NOR);
                 } else if(exp < 2000000 ){
                        me->set("title", WHT"武圣门"HIG"护派金刚"NOR);
                 } else if(exp < 3000000 ){
                        me->set("title", WHT"武圣门"HIG"神武天尊"NOR);
                } else {
                        me->set("title", WHT"武圣门"HIG"傲剑天皇"NOR);
                }

                tell_object(me, "老者对你说：你可以做"+me->query("title")+"。\n");
                tell_room(environment(me),
"老者对"+me->query("name")+"说：你可以做"+me->query("title")+"。\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","现授予本门弟子"+me->query("name")+""+me->query("title")+"一职。恭请各位仙长多加捧场！");
     me->save();  
        }
        return 1;
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="武圣门") {
    tell_room(environment(me),"老者说道.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
     return ("老夫不知道你在说些什么。");
}


�
