// By tianlin 2001.5.1
inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create ()
{
  set ("short", "神龛");
  set ("long", @LONG

这里是供奉灶神的地方灶王爷正笑眯眯的看着你，你麻起胆子
想向灶王爷要(yao)些什么。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/city/jiuguan1",
]));
   set("chat_room",1);
  set("objects", ([ /* sizeof() == 2 */
  "d/city/npc/zaoshen" : 1,
]));

   set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);
 setup();
}

void init()
{
    add_action("block_cmd", "", 1);
       add_action("do_exert", "exert");
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao") return 1;
   // if (verb == "exert") return 1;
    return 0;
}

int valid_leave(object me, string dir)
{

        if ( !me->query("wizgift/newbiegift") )
           tell_object(me, "你对灶王爷说道：“我还是下次再来领吧！\n 灶王爷点了点头。\n");

        return ::valid_leave(me, dir);
}
int do_exert(string arg)
{
    tell_object(this_player(), "安全区内禁止运动。\n");
    return 1;
}

