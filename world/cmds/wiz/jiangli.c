// jiangli.c
// 奖励发现bug的玩家
// By tianlin 2001.5.1

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me,string arg)
{
	string id,reason,present;
	object player,gold;
	int i;
	
	if( !arg || arg=="" || sscanf(arg, "%s for %s", id, reason)!=2)
		return notify_fail("指令格式：jiangli <玩家id> for <简要介绍bug>\n");

	player = find_player(id);
	if (!player) return notify_fail("没有这个人\n");
	if (wizardp(player)) return notify_fail("不能奖励巫师\n");
	i=random(3);
	switch (i)
	{
		case 0:
			player->add("combat_exp", 40000);
			present="实战经验 四万";
			break;
		case 1:
			player->add("potential",20000);
			present="潜能 两万";
			break;
		case 2:
			player->add("daoxing",30000);
			present="道行 三十年";
			break;
	}
	tell_object(player,HBRED""+me->query("name")+"奖励给你"+present+"！\n"NOR);
	write(HBRED"你奖励"+player->query("name")+present+"！\n"NOR);
		message("channel:rumor",HIM"【谣言】某人："+"据说[2;37;0m[37m<某人>[1;35m发现了游戏中的BUG,得到了拥有的奖励。\n"NOR,users());//this is by tianlin

	log_file("jiangli",
		sprintf("%s(%s) 奖励 %s(%s) %s 因为 %s  on %s\n",
		me->name(1),
		geteuid(me),
		player->name(1),
		geteuid(player),
		present,
		reason,
		ctime(time()) ));
		
	
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : jiangli <玩家id> for <简要介绍bug>

本命令给与发现小bug(程序错误--程序失误,且没造成巨大损失的)
的player以奖励.注意请慎用本命令,如果bug问题不明确,经请示讨
论再决定
例子	jiangli tryid for 发现tree错误
HELP	);
	return 1;
}