// created by snowcat.c 5/23/1997
// room: /d/pantao/ting1.c

inherit ROOM;

void create ()
{
  set ("short", "��ϼͤ");
  set ("long", @LONG

ֻ����ϼ��ҫ������ƮƮ��ͤ���ɻ�ʢ���������ơ����з���
һ������������������֥���ݡ�ϼͤ���ĸ��������߸���
����Χ����������ơ�

LONG);

  set("exits", ([
        "south"     : __DIR__"ting2",
        "southeast" : __DIR__"pan1a",
      ]));

  set("objects", ([
         __DIR__"npc/xiannu1"  : 1,
     ]));

  setup();
}

