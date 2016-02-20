//nuwa.c
//By tianlin@Mhxy for 2002.1.24.开通和优化
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>
/*
string *skill_list=({
	"dodge",
	"parry",
	"sword",
	"whip",
	"force",
	"spells",
	"unarmed",
	"moondance",
	"moonforce",
	"moonshentong",
	"snowsword",
	"jueqingbian",
	"baihua-zhang",
	"literate",
	});
*/
void create()
{
       set_name("女娲娘娘", ({"nuwa niangniang", "nuwa", "niangniang","master"}));
       set("long", "西华至妙生伊川，穆王八骑访昆仑。\n");
       set("title", "[1;35m月宫祖师[2;37;0m");
       set("gender", "女性");
       set("age", 30);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "神仙娘娘");
       set("cor", 30);
       set("per", 30);
	set("looking", "眉头微蹙，面有忧色。");
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 15000);
       set("max_force", 7500);
       set("force_factor", 200);
       set("max_mana", 7500);
       set("mana", 15000);
       set("mana_factor", 100);
       set("combat_exp", 4000000);
  set("daoxing", 5000000);

       set_skill("literate", 180);
       set_skill("unarmed", 285);
       set_skill("dodge", 285);
       set_skill("force", 285);
       set_skill("parry", 285);
       set_skill("sword", 285);
       set_skill("spells", 285);
	set_skill("moonshentong", 285);
	set_skill("baihua-zhang", 285);
	set_skill("moonforce", 285);
	set_skill("snowsword", 285);
	set_skill("moondance", 285);
	set_skill("whip",285);
	set_skill("jueqingbian",285);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
	map_skill("whip",  "jueqingbian");
   set("inquiry",([
  ]));
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "arrow" :),
                (: cast_spell, "mihun" :),
        }) );

create_family("月宫", 1, "红");
setup();

     //   carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void attempt_apprentice(object ob)
{	
	int size = sizeof(obstacles);
  	string *names = keys(obstacles);
  	string *sname;
  	mapping skl;
  	int i;
	if (!ob->query_temp("koujian_nuwa"))
	{
		command("look "+ob->query("id"));
		command("say "+"这位"+RANK_D->query_respect(ob)+"不请自来，似乎不大好吧？还是请回吧。");
		return;
	}

  	if ( !((string)ob->query("gender")=="女性")){
	   command("shake");
    	   command("say 我们月宫只收女徒，这位" + RANK_D->query_respect(ob) + "还是另请高就吧。\n");
	   return;
	}

  	for (i = 0; i < size; i++)
      	if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
      	{
 	   command("shake");
    	   command("say 这位" + RANK_D->query_respect(ob) + "尚未历尽西行难关，恐怕难以领悟高深武学。\n");
	   return;
      	}

	if ( (string)ob->query("family/family_name")!="月宫") {
	   	command("shake");
		command("say " + RANK_D->query_respect(ob) +
			"还是先去学些基础功夫吧。\n");
        	return;
	}
    if ( ((int)ob->query("combat_exp") < 1000000) || ((int)ob->query("daoxing")<1000000)) {
	command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
	return;
	}
{        	command("pat "+ob->query("id"));
        	command("say 好，希望" + RANK_D->query_respect(ob) +
			"多加努力，把我们月宫发扬光大。\n");
		if (ob->query("title")=="广寒宫传人")
		{
		   command("say 不过即已入我门下，这掌门之位就传给别人罢。\n");
		   rm("/data/zhangmen/zhangmen_chang_e.o");
		}
       		command("recruit " + ob->query("id") );
	       	ob->set("title",HBBLU+HIY"女娲娘娘座下弟子"NOR);
       		message("system", HIM"女娲娘娘"HIB"又新收了一个弟子 "BLINK+HIR+this_player()->name()+NOR+HIW"
                     月宫的势力加强了。\n"NOR,users());
        message("channel:rumor",HIM+"【"HIW"谣言"HIM"】某人："BLINK+HIR+ob->query("name")+NOR+HIM"得到女娲娘娘的指点 ！\n"NOR,users() );
	return;
	}
}
int accept_fight(object me)
{
	return 0;
}
