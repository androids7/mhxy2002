// Room: /4world/houshan1
inherit ROOM;

void create ()
{
  set ("short", "[0;32m��ɽС·[m");
  set ("long", @LONG

����ͨ����ɽ��һ��С·��ֻ��С�������������������У�
һ����ע��ͻ�����ͷ��Ѫ������ֻ����Χ����������ȥ��
һ��֨֨�ҽУ�һ�߳�����Ұ����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/monkey1" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"entrance",
  "northup" : __DIR__"houshan2",
]));

  setup();
}
