//sgzl

#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "[33m������[m");
set("long", @LONG
    
��ʤ���޺���һС�������������ٴ󺣣���������ɽ��ֻ��
�����һ����խ��ƽԭ�ش��Ͻ���һ���ǳء�һ����·ֱͨ
�Ϸ���·������Ҳ�ǴҴҶ�����
LONG );


set("exits", ([
  "west"   : "/d/changan/aolaiws",
  "east"   : __DIR__"flowerfruit",
  "south"   : __DIR__"northgate",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
