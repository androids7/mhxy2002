// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
   set ("short", "���Ƹ�");
   set ("long", @LONG

���Ƹ�ӹ��е���ߴ������ϻ�����������麿������������˺�
��Ĺ�����Χ����������ƾ��������Զ�����¾�����ǰ��ɽ��
�巿¥�ᣬɽ����ʯ����������Ŀ��
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "down": __DIR__"yanzhen",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/qingfeng" : 1,
                __DIR__"npc/zhenyuan" : 1,
   ]));


   set("outdoors", "wuzhuang");

   setup();
}

void init()
{
   object where=this_object();

    remove_call_out("check_time");
   check_time(where);
   add_action("do_hear","hear");
}
void check_time(object where)
{

   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];

   int phase=((int)(t/120));
   if(phase==5&&(!query("jiangjing"))) jiang_jing(where);
if(phase==6&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}

void jiang_jing(object where)
{
message("channel:chat",CYN+"��"HIC"��ׯ��"NOR+CYN"��"NOR+WHT"��Ԫ����[zhenyuan daxian]��"CYN"���ڿ�ʼ˵����������ע���ˡ�"HIR"(Hear)\n"+NOR,users());
tell_object(where,"�쳤�ؾá���������ܳ��Ҿ��ߣ����䲻���������ܳ�����\n");
tell_object(where,"�������ã�Ī֮���أ�\n");
tell_object(where,"�ʹ�����Ϊ���£����ɼ����£�������Ϊ���£����������¡�\n");
tell_object(where,"��ʥ���ǣ������ٱ����������壬��Т�ȣ������������������С�\n");
tell_object(where,"........................................\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"��Ԫ����˵���������Ϣ�ɡ�\n");
   set("jiangjing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("����æ���ء�\n");
   if(!query("jiangjing"))
      return notify_fail("��Ԫ���ɻ�û��˵����\n");

 if((string)me->query("family/family_name")!="��ׯ��")
      return notify_fail("���ɵ��Ӳ�����������\n");
   if(me->query("faith")>800)
      return notify_fail("��Ԫ���ɶ���˵���������ȥ��Щ�������������ˡ�\n");
   tell_object(me,"�㲻������Ԫ���ɵĽ������������ˡ�\n");
   me->start_busy(5);
   me->add("faith",1);
   me->add("combat_exp",30);
   me->add("potential",5);
   me->improve_skill("taiyi",100);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}