// bbsboard.c
// Last modified by jjgod@FYTX. 01/03/06.
/*��ǿ�������԰棺BBS_BOARD
 *���ӣ��ظ����ܡ������ܡ��������� */

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

// ������� 100 ������
#define MAX_PLAN		500

// �������ӳ����� MAX_PLAN��ɾ��ǰ 50 ��
#define DEL_TO		50

// �Ƿ񱣴�����ԭ�������ӣ�������Ϊ0��������Ϊ 1
#define SAVE_ALL_OLD_PLAN 0

// �����Ҫ��ʾ����������ܳ��ܳ������룺
// #define DEBUG		1
void setup()
{
	string loc;
   	seteuid(getuid());

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_post", "post");
	add_action("do_re", "re");
	add_action("do_read", "read");
	add_action("delete_post", "delete");
	add_action("delete_post", "discard");
	add_action("do_banzhu", "banzhu");
	add_action("do_wenxuan", "jinghua");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ û���κ����� ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf(HIC"%s"NOR" [ "HIW"%d"NOR" �����ӣ�"HIR"%d"NOR" ƪδ�� ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ "HIW"%d"NOR" ������ ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
	int i, j, last_time_read, new_report;
	string msg, myid;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) ) return query("long");

	write(CLR);
	if( !query("banzhu") ) msg=HBBLU+HIY+"���������У�       ";
	else
	msg=HBBLU+HIY+"������ "+HIW+"[ "BLINK+HIG+query("banzhu")+NOR+HBBLU+HIW+" ]";
	msg+="             "NOR+HBBLU+WHT+"��"+COLOR_D->replace_color(query("name"));
	msg+=HBBLU+"                                \n";
	msg+=NOR+HIW"�Ķ�����["HIG"read <n>"HIW"] �Ķ��ظ�����["HIG"read <n>.<n>"HIW"] ��������["HIG"post"HIW"] ������["HIG"wenxuan"HIW"]\n";
	msg+=HBBLU+HIW"��š� ���ߡ�������     ʱ�䡡���ظ�  ����         ���������� ��             \n"NOR;
	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=0; i<sizeof(notes); i++) {
		new_report = 0;
		if( arrayp(notes[i]["re"]) ) {
			j = sizeof(notes[i]["re"]);
			while(j--)
				if( notes[i]["re"][j]["time"] <= last_time_read ) break;
			new_report = sizeof(notes[i]["re"]);
		}
		msg += sprintf("%s["WHT"%2d"NOR"]" NOR " "+HIW+( notes[i]["time"] > last_time_read ? "N": "n")+" %-20s"HIG"  [%s] "HIM"%+3d"HIW"  ��"+COLOR_D->get_color(notes[i]["title"])+"%-29s\n"+NOR,
			( notes[i]["time"] > last_time_read ? "": ""),
			i+1,  notes[i]["author"],
			ctime(notes[i]["time"])[4..9],
			new_report,COLOR_D->replace_color(notes[i]["title"],1) );
	}
	msg+=HBBLU+HIY+"["+HIC+NATURE_D->game_time()+HIY"]                                           ["+HIC+this_player()->query("id")+HIY+"] "NOR;
	return msg;
}

void done_post(object me, mapping note, string text)
{
	mapping *notes;
	string msg="";
	int i,j;

	if (me->query("signature")) {
		note["msg"]=COLOR_D->replace_color(text+"\n---------------------------------\n"+me->query("signature"),1);
	}
	else note["msg"]=COLOR_D->replace_color(text,1);

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({note });
	else
		notes += ({ note });

	set("notes", notes);
	save();
	tell_object(me, HIW"��������ɡ�\n"NOR);

	if( query("news") )
	{
        message("news",HIG+"������Ƶ��������С�㣺"HIC"��"+MUD_NAME+HIC"��"HIG"�����µ����ţ�����"HIY"news"HIG"�鿴��\n"+NOR,users());
	tell_object(me, "���ŷ�����ϡ�\n");
	}
	if (sizeof(query("notes"))>MAX_PLAN) {
	tell_object(me, HIR"������Ŀ������������������\n"NOR);
		for (i=0;i<DEL_TO;i++) {
// ԭ������
			msg+=sprintf(
			"[ "HIW"��ţ�"NOR"%2d ] [ "HIW"���ߣ�"NOR"%s(%s) ] [ "HIW"ʱ�䣺"NOR"%-19s ]\n[ "
			HIW"���⣺"NOR"%-54s ]\n����������������������������������������������������������������\n%s\n"
			"����������������������������������������������������["HIW" �� ƪ �� "NOR"]\n",
			i+1,
			notes[i]["author"],notes[i]["owner"],
			ctime(notes[i]["time"])[0..9],
			notes[i]["title"],
			notes[i]["msg"],);
// �ظ�����
			if (sizeof(notes[i]["re"])) {
				for (j=0;j<sizeof(notes[i]["re"]);j++) {
					msg+=sprintf(
					"\n[ "HIW"�ظ���ţ�"NOR"%2d] [ "HIW"�ظ����⣺"NOR"%-34s ] \n"
					"����������������������������������������������������������������\n"
					"%s\n����������������������������������������������������������������\n[ "HIW"ʱ�䣺"NOR"%s ] [ "
					HIW"���ߣ�"NOR" %s(%s) %-7s]\n",
					j+1,
					notes[i]["re"][j]["title"],
					notes[i]["re"][j]["msg"],
					ctime(notes[i]["re"][j]["time"]),
					notes[i]["re"][j]["author"],
					notes[i]["re"][j]["owner"],"");
				}
			}
		}
#ifdef DEBUG
		me->start_more(msg);
#endif
// 50 ��ǰ�����ӽ����浽 /data/board/�����board_id �ļ���
		write_file(DATA_DIR+"board/"+query("board_id")+".old",msg,SAVE_ALL_OLD_PLAN);
// ɾ��Ŀǰ board ��� 50 ��ǰ������
		notes = notes[DEL_TO..sizeof(notes)-1];
		set("notes",notes);
		save();
		tell_object(me, HIR"����������ϣ�ɾ�� "HIW+(DEL_TO+1)+HIR" ����ǰ�����ӡ�\n"NOR);
	}
	return;
}

void done_re(object me, mapping report, int project, string text)
{
	mapping *notes, *reports;
// ֧��ǩ������ɫ
	if (me->query("signature")) {
		report["msg"]=COLOR_D->replace_color(text+"\n---------------------------------\n"+me->query("signature"),1);
	}
	else report["msg"]=COLOR_D->replace_color(text,1);

	notes = query("notes");
	reports = notes[project]["re"];
	if( !arrayp(reports) )	reports = ({ report });
	else reports += ({ report });

	notes[project]["re"] = reports;
	notes[project]["time"] = time();

	set("notes", notes);
	tell_object(me, HIW"�ظ���ϡ�\n"NOR);

	save();
	return;
}

int do_post(string arg)
{
	mapping note;

	if( (query("env/invisibility") || query("wizard")) && !wizardp(this_player())) return 0;

	if(!arg) return notify_fail("��������ָ��һ�����⡣\n");
	if( strlen(arg)>24 ) return notify_fail("�������������д���̵�ı���ɣ�\n");
	note = allocate_mapping(5);
	note["title"] = arg;
	note["owner"] = this_player()->query("id");
	note["author"] = COLOR_D->clean_color(this_player()->name(1));
	note["time"] = time();
	this_player()->edit( (: done_post, this_player(), note :) );
	return 1;
}

int do_re(string arg)
{
	int num;
	string title;
	mapping note, *notes;

	if(!arg || sscanf(arg, "%d.%s", num, title)!=2 )
		return notify_fail("ָ���ʽ��re <���ӱ��>.<�ظ�����>\n");

	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û��������ӡ�\n");

	note = allocate_mapping(5);
	note["title"] = title;
	note["owner"] = this_player()->query("id");
	note["author"] = this_player()->name(1);
	note["time"] = time();
	this_player()->edit( (: done_re, this_player(), note, num-1 :) );
	return 1;
}

int do_read(string arg)
{
	int num, rep, last_read_time,i,last;
	mapping *notes;
	string myid,msg,file;
	object me=this_player();

	last_read_time = me->query("board_last_read/" + query("board_id"));
	myid	= query("board_id");
	notes	= query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("������Ŀǰû���κ����ӡ�\n");

	if( !arg ) return notify_fail("ָ���ʽ��read <���ӱ��>[.<�ظ����>]|new|next|old\n");

// ��ʾ��ǰ���ݵľ�����
	if (arg=="old") {
		file=DATA_DIR+"board/"+query("board_id")+".old";
		if (file_size(file)<=0) return notify_fail("�Բ���Ŀǰ����û�б���ľ�����\n");
		else {
			msg=read_file(file);
			me->start_more(msg);
			return 1;
		}
	}
// ��ʾδ��������
	if( arg=="new" || arg=="next" ) {
		if( !intp(last_read_time) || undefinedp(last_read_time) )
			num = 1;
		else
		for(num = 1; num<=sizeof(notes); num++)
			if( notes[num-1]["time"]>last_read_time) break;

	} else if( sscanf(arg, "%d.%d", num, rep)==2 ) {
		if( num < 1 || num > sizeof(notes) ) return notify_fail("û��������ӡ�\n");
		else num--;
		if( rep < 1 || rep > sizeof(notes[num]["re"]) ) return notify_fail("û������ظ���\n");
		else rep --;
		me->start_more( sprintf(
		"[ "HIW"��ţ�"NOR"%2d | "HIW"�ظ���ţ�"NOR"%2d] [ "HIW"ԭ�⣺"NOR"%-27s ] \n"
		"[ "HIW"�ظ����⣺"NOR"%-50s ]\n����������������������������������������������������������������\n"
		"%s\n����������������������������������������������������������������\n[ "HIW"ʱ�䣺"NOR"%s ] [ "
		HIW"���ߣ�"NOR" %s(%s) %-7s]\n",
			num + 1, rep + 1,
			COLOR_D->replace_color(notes[num]["title"],1),
			COLOR_D->replace_color(notes[num]["re"][rep]["title"],1),
			COLOR_D->replace_color(notes[num]["re"][rep]["msg"],1),
			ctime(notes[num]["re"][rep]["time"]),
			notes[num]["re"][rep]["author"],
			notes[num]["re"][rep]["owner"],"") );

		if( notes[num]["time"] > last_read_time )
			me->set("board_last_read/" + query("board_id"),
				notes[num]["time"]);

		return 1;
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ���ڼ������ӵĻظ���\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("û��������ӡ�\n");
	num--;
	msg=sprintf(
	"[ "HIW"��ţ�"NOR"%2d ] [ "HIW"���ߣ�"NOR"%s(%s) ] [ "HIW"ʱ�䣺"NOR"%-19s ]\n[ "
	HIW"���⣺"NOR"%-54s ]\n����������������������������������������������������������������\n%s\n"
	"����������������������������������������������������["HIW" �� ƪ �� "NOR"]\n",
		num + 1,
		notes[num]["author"],notes[num]["owner"],
		ctime(notes[num]["time"])[0..9],
		COLOR_D->replace_color(notes[num]["title"],1),
		COLOR_D->replace_color(notes[num]["msg"],1));
// ��ʾ�ظ�����Ŀ
	if (sizeof(notes[num]["re"])&&me->query("env/show_reply")!="all") msg+=sprintf(HIW"�ظ���"NOR"%d �ݡ�\n",sizeof(notes[num]["re"]));
// ��ʾ����һ���ظ�
	if (me->query("env/show_reply")=="last") {
		last=sizeof(notes[num]["re"])-1;
		msg+=sprintf(
			"\n[ "HIW"�ظ���ţ�"NOR"%2d] [ "HIW"�ظ����⣺"NOR"%-34s ] \n"
			"����������������������������������������������������������������\n"
			"%s\n����������������������������������������������������������������\n[ "HIW"ʱ�䣺"NOR"%s ] [ "
			HIW"���ߣ�"NOR" %s(%s) %-7s]\n",
			last+1,
			COLOR_D->replace_color(notes[num]["re"][last]["title"],1),
			COLOR_D->replace_color(notes[num]["re"][last]["msg"],1),
			ctime(notes[num]["re"][last]["time"]),
			notes[num]["re"][last]["author"],
			notes[num]["re"][last]["owner"],"");
	}
// ��ʾ���еĻظ�
	if (me->query("env/show_reply")=="all") {
		for (i=0;i<sizeof(notes[num]["re"]);i++) {
			msg+=sprintf(
		"\n[ "HIW"�ظ���ţ�"NOR"%2d] [ "HIW"�ظ����⣺"NOR"%-34s ] \n"
		"����������������������������������������������������������������\n"
		"%s\n����������������������������������������������������������������\n[ "HIW"ʱ�䣺"NOR"%s ] [ "
		HIW"���ߣ�"NOR" %s(%s) %-7s]\n",
			i+1,
			COLOR_D->replace_color(notes[num]["re"][i]["title"],1),
			COLOR_D->replace_color(notes[num]["re"][i]["msg"],1),
			ctime(notes[num]["re"][i]["time"]),
			notes[num]["re"][i]["author"],
			notes[num]["re"][i]["owner"],"");
		}
	}
	me->start_more(msg);

	if( notes[num]["time"] > last_read_time )
		me->set("board_last_read/" + query("board_id"),
			notes[num]["time"]);

	return 1;
}

int do_banzhu(string arg)
{
	if (!arg) return notify_fail("ָ���ʽ�� banzhu <����id>\n");
	if (!stringp(arg)||strlen(arg)<3) return notify_fail("û������ˡ�\n");
	if (query("banzhu")==arg) return notify_fail("Ŀǰ�İ������� "+arg+"������Ҫ���á�\n");
	if (SECURITY_D->get_status(this_player(1)) != "(admin)") return notify_fail("�㲻�����񣬲��������ð�����\n");
	set("banzhu",arg);
	save();
	write("���� "HIW+arg+NOR" Ϊ"+name()+"�����ɹ���\n");
	return 1;
}

int delete_post(string arg)
{
	mapping *notes;
	int num,re_num;

	if(!arg ||sscanf(arg, "%d.%d",num,re_num)<1)
		return notify_fail("ָ���ʽ��delete <���ӱ��>[.<�ظ����>]\n");
	notes = query("notes");
	if( !arrayp(notes)|| num <1 || num > sizeof(notes))
		return notify_fail("û���������ӡ�\n");
	else if(re_num) {
		if (re_num<1||!arrayp(notes[num-1]["re"])||re_num > sizeof(notes[num-1]["re"]))
			return notify_fail("û�����Żظ���\n");
		else {
			num--;
			re_num--;
			if( notes[num]["re"][re_num]["owner"] != (string)this_player(1)->query("id")
			&&query("banzhu")!=this_player(1)->query("id")
			&&	(string)SECURITY_D->get_status(this_player(1)) != "(admin)")
				return notify_fail("����ظ�������д�ģ����ֲ��ǰ�����\n");
			else {
				notes[num]["re"]=notes[num]["re"][0..re_num-1] + notes[num]["re"][re_num+1..sizeof(notes[num]["re"])-1];
				set("notes", notes);
				save();
				write("ɾ���� " + (num+1) + " �����ӵĵ� "+ (re_num+1)+" �Żظ�....Ok��\n");
				return 1;
			}
		}
	}
	else {
		num--;
		if( notes[num]["owner"] != (string)this_player(1)->query("id")
		&&query("banzhu")!=this_player(1)->query("id")
		&&	(string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
			return notify_fail("������Ӳ�����д�ģ����ֲ��ǰ�����\n");

		notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
		set("notes", notes);
		save();
		write("ɾ���� " + (num+1) + " ������....Ok��\n");
		return 1;
	}
}

int do_wenxuan(string arg)
{
	object me=this_player();
	int num,i;
	mapping *notes= query("notes");
	string msg,file_name;

	if (!wizardp(me)&&query("banzhu")!=getuid(me)) return notify_fail("��û�����Ȩ����\n");
	if (!arg) return notify_fail("�������ƪ���·��뾫������\n");
	if (sscanf(arg,"%d",num)!=1) return notify_fail("��ʽ��jinghua <���±��>\n");
	seteuid(getuid());
	if (num>sizeof(query("notes"))||!arrayp(notes)|| num <1) return notify_fail("û����ƪ���£�\n");
		else {
		num--;
		msg=sprintf(
		"%s \n\t   ������ "HIW"%s(%s)"NOR" �� "HIW"%-10s"NOR" ������ "HIW"%s"NOR" \n"
		"����������������������������������������������������������������\n%s\n"
		"����������������������������������������������������["HIW" �� ƪ �� "NOR"]",
		notes[num]["title"],
		notes[num]["author"],notes[num]["owner"],
		ctime(notes[num]["time"])[0..9],
		name(),
		notes[num]["msg"],);

		if (sizeof(notes[num]["re"])) {
			for (i=0;i<sizeof(notes[num]["re"]);i++) {
				msg+=sprintf(
				"\n\n���Ļظ�["HIW"%2d"NOR"]��"NOR"%-34s\n\t   ������ "HIW"%s(%s)"NOR" ������ "HIW"%-10s"NOR"\n"
				"����������������������������������������������������������������\n"
				"%s\n����������������������������������������������������������������\n",
				i+1,
				notes[num]["re"][i]["title"],
				notes[num]["re"][i]["author"],
				notes[num]["re"][i]["owner"],
				ctime(notes[num]["re"][i]["time"]),
				notes[num]["re"][i]["msg"],);
			}
		}

		file_name="/data/wenxuan/"+localtime(time())[5]+"/"+(sizeof(get_dir(DATA_DIR+"wenxuan/"+localtime(time())[5]+"/"))+1)+".w";

		write("����д��"+file_name+"����");
		write(msg);
		if ( write_file(file_name,msg) ) write(HIG"\nд��ɹ���\n"NOR);
		else write(HIR"\nд��ʧ��,������ʦ��ϵ!\n"NOR);
		return 1;
	}
}