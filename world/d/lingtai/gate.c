// Room: some place in ��ţ����
// gate.c
//by tianlin 2001/5/1
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "[44m[1;33m ɽ �� [2;37;0m");
  set ("long", @LONG

�ſ���һʯ����Լ�������Ÿߣ��˳�����������һ��ʮ�����֣�
���ǡ���̨����ɽ��б�����Ƕ�����ɽ������һ��ͯ���������
Ӣΰ����ò���棬��Ѱ�����Ӳ�ͬ��

    [1;35m��������[2;37;0m                  [1;35m��������[2;37;0m
    [1;35m��[1;37m ��[1;35m ��[2;37;0m������������������[1;35m�� [1;37mб[1;35m ��[2;37;0m
    [1;35m��    ��[2;37;0m��[1;33m�� �� �� �� ����[1;37m[1;35m��    ��[2;37;0m
    [1;35m��[1;37m ̨[1;35m ��[2;37;0m������������������[1;35m�� [1;37m��[1;35m ��[2;37;0m
    [1;35m��    ��[2;37;0m  [1;33m�� �� �� �� ̨��[1;37m[1;35m��    ��[2;37;0m
    [1;35m��[1;37m ��[1;35m ��[2;37;0m������������������[1;35m�� [1;37m��[1;35m ��[2;37;0m
    [1;35m��    ��[2;37;0m  [1;33m�� �� �� һ �[1;37m[1;35m��    ��[2;37;0m
    [1;35m��[1;37m ��[1;35m ��[2;37;0m������������������[1;35m�� [1;37m��[1;35m ��[2;37;0m
    [1;35m��    ��[2;37;0m  [1;33m�� �� �� �� ����[1;37m[1;35m��    ��[2;37;0m
    [1;35m��[1;37m ɽ[1;35m ��[2;37;0m������������������[1;35m�� [1;37m��[1;35m ��[2;37;0m
    [1;35m��������[2;37;0m                  [1;35m��������[2;37;0m

LONG);
 
    set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"gate1",
    "southdown": __DIR__"uphill6",
]));

set("objects", ([
                __DIR__"npc/yingke": 1 ]) );
        create_door("north", "ʯ��", "south", DOOR_CLOSED);
         set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        "obj/board/shibei_b"->foo();
   
}


