// by cih 10/01/2002
// Room: /d/kaifeng/huayuan1
inherit ROOM;

void create()
{
  set("short", "��԰");
   set("long", @LONG



[35m����������������������������������������������������������[2;37;0m
[35m��                    [1;36m����˧��[2;37;0m[35m                          ��[2;37;0m
[35m����������������������������������������������������������[2;37;0m
[35m��[36m���ۡ��Ļ�԰�������������ʻ�����֪��Ϊʲô��������[35m��[2;37;0m
[35m��[36m�š����ָ����Ļ������涷�ޣ�����ǧ�������ζ����Ȼ����[35m��[2;37;0m
[35m��[36m÷����ĵ��һ�����£���˵��Щ���ǵ��곤��͸�С��ϲ����[35m��[2;37;0m
[35m��[36m�ɼ����ǿɰ�������Ǹ����������أ�                  [35m��[2;37;0m 
[35m����������������������������������������������������������[2;37;0m



LONG
   );
   set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"huayuan5",
  "southeast" : __DIR__"neitang",
  "northeast" : __DIR__"huayuan6",
  "northwest" : __DIR__"huayuan2",
]));
  set("objects", ([
        __DIR__"npc/laotou" :  1,
      ]));

   set("outdoors", "kaifeng");
   setup();
   replace_program(ROOM);
}
