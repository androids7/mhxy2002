
inherit ROOM;

void create ()
{
  set ("short", "[36m��[m");
  set ("long", @LONG
�����ǹ�Ĺ��һ��������ͨ�����ϱ�ͨ��һ�����ص������Թ���
����˵��һ��ʹ�Ĺ���أ����Գ���������̽�������ϱ���ɭɭ�ĺ�
���ˣ������������Ҳ�����������������ǾͿ���Щ�������˳伢��
���ӡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"maze1",
  "south" : __DIR__"nei2",
]));  
  set("objects", ([
  ]));
  setup();
}                                                                                                      
