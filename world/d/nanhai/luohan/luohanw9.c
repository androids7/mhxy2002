//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "�޺���");
  set ("long", @LONG


			��


LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luohan0" : 1,
]));

  set("exits", ([ /* sizeof() == 4 */
  "up" : __DIR__"luohanw",
  "westdown" : __DIR__"luohanw8",
]));
  setup();
}
int valid_leave(object me, string dir)
{

        if( (string)me->query("family/family_name")=="�Ϻ�����ɽ" ) return 1;
        if( wizardp(me)) return 1;


        if (dir == "up") {
        if (objectp(present("luo han", environment(me))))

        return notify_fail("�޺����ֵ�ס�����ȥ·��\n");
        }   
        return ::valid_leave(me, dir);
}

