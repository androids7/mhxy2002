// changan wusheng
// baiyu13.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "���ƶ�");
  set ("long", @LONG

���ں�����������������ڶ��ڻص���˿˿��ζ�������Ρ�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north": __DIR__"huoyun14",
  "northeast": __DIR__"huoyun"+sprintf("%d",random(20)),
  "northwest": __DIR__"huoyun"+sprintf("%d",random(20)),
]));

  set("no_clean_up", 1);
  setup();
}
int clean_up()
{
      return 0;
}
