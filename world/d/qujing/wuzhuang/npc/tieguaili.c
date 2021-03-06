// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// tieguaili.c...weiqi, 98.02.24.

inherit NPC;
inherit F_MASTER;
string laojun_yao(object me);

void create()
{
   set_name("铁拐李", ({"tieguai li", "tieguai", "li"}));
   //set("title", "");
   set("gender", "男性" );
   set("age", 42);
   set("per", 12);
   set("long", "他脚登一双烂草鞋，身着一件早就没了本来面目的脏袍，嘴里哼着走调小曲，一副悠闲神态。\n");
   set("class", "xian");
   set("combat_exp", 120000);
   set("attitude", "peaceful");
   create_family("五庄观", 3, "弟子");
   set_skill("unarmed", 60);
   set_skill("wuxing-quan", 60);
   set_skill("dodge", 80);
   set_skill("baguazhen", 80);
   set_skill("parry", 80);
   set_skill("staff", 90);
   set_skill("fumo-zhang", 100);
   set_skill("force", 70);   
   set_skill("zhenyuan-force", 70);
   set_skill("literate", 20);
   set_skill("spells", 80);
   set_skill("taiyi", 80);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("staff", "fumo-zhang");
   map_skill("dodge", "baguazhen");

   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 1000);
   set("max_force", 800);
   set("mana", 1600);
   set("max_mana", 800);   
   set("force_factor", 40);
   set("mana_factor", 40);
   set("inquiry", ([
    "灭妖": "妖，什么妖？嘿嘿.....\n",
      "犀牛精": (: laojun_yao :),
]));

   setup();
   carry_object("/d/obj/cloth/pobuyi")->wear();
   carry_object("/d/obj/cloth/lancaoxie")->wear();
   carry_object("/d/obj/weapon/staff/tieguai")->wield();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="五庄观" )
   {
     if( (int)ob->query("family/generation") < 3  )
     {
        if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
        else command("say 师姑见笑了。\n");
     }
     else if( (int)ob->query("family/generation") ==3  )
     {
        command("kick " + ob->query("id") );
        command("say 你这个" + RANK_D->query_rude(ob) + "，敢来消遣老子！\n");
     }
     else 
     {
        command("consider");
        command("say 是你自己要拜的，你师父打上门来我可得拿你挡。\n");
        command("recruit " + ob->query("id") );
     }
   }

   else
   {
     command("say 好，我五庄观一门人才辈出，你可得给师父争气。\n");
     command("recruit " + ob->query("id") );
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "xian");
}




string laojun_yao(object me)  
{
   me=this_player();
 //  if((string)me->query("family/family_name")!="五庄观") {
 //         command("say 一定是谣言，一定是!");
 //         command("hmm");
 //        return ("别在相信这么无聊的人了 \n");
 //       }
    if(me->query("faith")<500)
        {
          command("say 一定是谣言，一定是!");
          command("hmm");
         return ("别在相信这么无聊的人了 \n");
        }
     if( me->query("laojun_jing") != 1 ) 
        {
          command("say 一定是谣言，一定是!");
          command("hmm");
         return ("别在相信这么无聊的人了 \n");
        }
          me->set("laojun_killjing", 1);
          command("?");
          message_vision("\n铁拐李道：我去查查，我去查查，难道这些谣言是真的？\n", me);
          message_vision("铁拐李细细地推算起来.......\n\n", me);
          message_vision("铁拐李吃惊地叫到，这位道友,此精已去了皇宫后院去了。。\n", me);
         return ("该死，该死\n");
}
