// ��������   Beeby 7/17/2000

#include <ansi.h>

inherit ROOM;

string *work_msg = ({
        HIC "����" NOR,
        HIC "˽��" NOR,
        HIC "����" NOR,
        HIC "ľ��" NOR,
        HIC "�Ҿ�" NOR,
        HIC "��" NOR,
        HIC "����" NOR,
        HIC "Ƥ��" NOR,
        HIC "��ƥ" NOR,
        HIC "����" NOR,
        HIC "ҩ��" NOR,
        HIC "����" NOR,
        HIC "����" NOR,
        HIC "ˮ��" NOR,
});

void create ()
{
        set ("short", "��������");
        set ("long", @LONG
    �����ǳ����Ǽ��С����ֵĵ��̶�����һ���š�һ�شص���Ƿ�ơ� 
һ����һ���Ľ������ڸ����ֿڡ�С����˺���Ӧ�����಻������
�е� ��ڴ�������һ������(sign)�� 
LONG);
        set("item_desc", (["sign" : "���������������������顣 
join        ��ʼ������ 
", ]));
        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"ximen",
        ]));
//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_join", "join");
}

int do_join(string arg)
{
	int workid;
	object me=this_player(),ob;
	string msg;
	int i;
	if (me->is_busy())
	 return notify_fail("����æ����!\n");	
	if (me->query_temp("heishi/selling") 
	    && (me->query_temp("heishi/selltime")+60>time()))
	 return notify_fail("�㻹���Ȱ���ͷ�����������!\n");
	if (me->query("sen")<30)
	 return notify_fail("���Ѿ�̫ƣ���ˣ�������Ϣһ�°�!\n");
	me->add("sen",-30);
	workid=random(sizeof(work_msg));
	msg="$N��ʼ����"+work_msg[workid]+"��\n";
        switch (workid)
	{
	 case 0:
	 {
	     if (random(2)==0)
	       {
                msg+="ͻȻ�����һ�ӹٱ�,��$N�����ȵ�:���󵨷�����"+
                     "���ҷ�������! ���췴���ɣ������ͷ�!��\n";
		message_vision(msg,me);
		ob=new(__DIR__"npc/xunluobing");
	        ob->kill_ob(me);
        	ob->set_leader(me);
        	me->fight_ob(ob);
		ob->move(environment(me));
		return 1;
	       }
	     break;	
	 }	
	 case 1:
	 { 
		if (random(2)==0)
		{ 
		   if (!me->query_temp("heishi/sale_salt"))
		   {
		     msg+="ͻȻ�����һ�ӹٱ�,һ�Ѿ�ס$N,�����ȵ�:���󵨵���"+
		        "���ҷ���˽��! ���ﻹ��û������!��\n";
		     msg+="$N�Ͻ�����һ����Ʊ��\n"+
		        "�ٱ�һ�����£�һ��˵��:�����������"+
		        "��ξ�����,�´���������׽ס�Ͳ����ٿ����ˡ���\n";
	  	     message_vision(msg,me);
		     me->set_temp("heishi/sale_salt",1);
		     return 1;
		   }
		   else
		   {
                     msg+="ͻȻ�����һ�ӹٱ�,һ�Ѿ�ס$N,�����ȵ�:���󵨵���"+
                        "���ҷ���˽��! ���ﻹ��û������!��\n";
                     msg+="$N�Ͻ�����һ����Ʊ��\n"+
                        "�ٱ�������һ��$N ͻȻһ����:��������!"+
                        "��ο��Ĳ�����!��\n";
		     msg+="�ٱ���$N�����ڵأ����������������ˡ�\n";
                     message_vision(msg,me);
                     me->delete_temp("heishi/sale_salt");
		     me->move(__DIR__"silao");
		     if (me->query("startroom"))
			me->set("mystartroom",me->query("startroom"));
		     me->set("startroom","/d/city/silao");
		     msg="���һ�������Ŵ���, $N�����˽�����ˤ�ڵ��ϣ�"+
			"���������һ�������ˡ�\n";
		     message_vision(msg,me);
                     return 1;
		   }
		 }
	 }
	}
	message_vision(msg,me); 
	me->set_temp("heishi/workid",workid);
	call_out("do_sale",3,me);
	me->set_temp("heishi/selling",1);
	me->set_temp("heishi/selltime",time());
	me->start_busy(3);
 	return 1; 
}

int do_sale(object me)
{
	string msg;
	int exp,pot_reward,exp_reward,workid,amount;
	object ob;
	exp=(me->query("combat_exp")+
                me->query("daoxing"))/2;
        if(exp<30000) {
            exp_reward=5+random(2+exp/600);
            pot_reward=1+random(2+exp/3000);
        } else if(exp<500000) {
            exp_reward=10+random(4+exp/6000);
            pot_reward=3+random(2+exp/60000);
        } else if(exp<3000000) {
            exp_reward=15+random(8+exp/60000);
            pot_reward=5+random(4+exp/600000);
        } else {
            exp_reward=200;
            pot_reward=40;
        }
	workid=me->query_temp("heishi/workid");
	switch (workid)
	{
	  case 0:
	  {
		msg="�㲻����ɫ�ĸ��������ѵ����������в�����Щ���⡣\n";
		exp_reward*=4;
		pot_reward*=4;
		break;
	  }
	  case 1:
	  {
		msg="�����ĵ��������������ϵĻ����������һ������\n";
                exp_reward*=2;
                pot_reward*=2;
		break;
	  }
	  default:
		msg="һ�������������������Щ�ۣ������ﻹ�Ǻ���졣\n";
	  }
	amount=(int)(pot_reward/2);
	amount=amount?amount:1;
	if (exp>500000)
	{
	  msg+="������������Щ��Ȼ�������ƺ����������о��л�һ���ӡ�\n"+
               "��õ���"+chinese_number(amount)+"�����ӡ�\n";
	} else 
	{  	
	  msg+="��ĵ���������"+COMBAT_D->chinese_daoxing(exp_reward)+
	   ",Ǳ��������"+chinese_number(pot_reward)+"��!\n"+
	   "��õ���"+chinese_number(amount)+"�����ӡ�\n";
	  me->add("potential",pot_reward);
	  me->add("daoxing",exp_reward);
	}
	ob=present("silver_money",me);
	if (!ob)
         {
	   ob=new("/obj/money/silver");
	   ob->set_amount(amount);
	   ob->move(me);
         }
	else
	   ob->add_amount(amount);
	write(msg);
	me->delete_temp("heishi/selling");
	me->start_busy(2);
	me->save();
	
	
}