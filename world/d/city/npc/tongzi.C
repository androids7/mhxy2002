// jieyinshi.c �ӿ�ͯ��

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIY"��·ͯ��"NOR, ({ "tong zi", "tong" }));
	set("long", "����һΪר�ŽӴ�����ҵ�ͯ��\n");
	set("gender", "����");
	set("age", 18);

	set("shen_type", 1);
	setup();

	carry_object("/u/tianlin/clone/hejin")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		say(HIW"ͯ��˵������λ"+ RANK_D->query_respect(ob)
				+ ",��ӭ����H.O.T . . .��\n"NOR+
                  HIG "0.ͨ����ɽ��\n" NOR+
                  HIR "1.ͨ��ظ���\n" NOR+
	    WHT "2.ͨ���޵׶���\n" NOR+
	    MAG "3.ͨ�򽫾�����\n" NOR+
	     HIG "4.ͨ��������\n" NOR+
                 HIY "5.ͨ�򷽴硣\n" NOR+
                 HIM "6.ͨ���¹���\n" NOR+
           HIB "7.ͨ����׳�ۡ�\n" NOR+
           HIY "8.ͨ�����ӡ�\n" NOR+
	     HIW "9.ͨ���ѩɽ��\n" NOR+
	     HIC "10.ͨ���䵱�ɡ�\n" NOR+
    BLINK HIC "����ѡ����Ҫȥ�ĵط�\n" NOR);
		
}
