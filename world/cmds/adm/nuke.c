// nuke.c 2-22-95
#include "/doc/help.h"

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        if( (string)this_player()->query("id") != "tianlin" )
        return notify_fail("���������������˶������ô�ָ��.\n��ο�kickoutָ�\n"); 
        if (!arg) return notify_fail("ָ���ʽ: nuke <living>\n");
        ob = find_player(arg);
        if (!ob) return notify_fail("�Ҳ��������ҡ�\n");
        message_vision("$N˫��һ�٣�һ�����׽�$n��Ϊ�ɻң���\n",me,ob);
        ob->set("kickout_time",time());
        ob -> save();
        seteuid(ROOT_UID);
        destruct(ob);
        return 1;
}


int help(object me)
{
   write(@HELP
ָ���ʽ: nuke <���>
��ĳ������߳�system������ʹ����һ��Сʱ�ڲ���������;


HELP
);
   return 1;
}