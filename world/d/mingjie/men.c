//Cracked by Roath
// Room: /d/nanhai/gate
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "地狱门");
  set ("long", @LONG

  
              .--.
              _|__  
             /    \ 
          __|  []  |__
          |__________|                            
          |   ____   |        
          |  |\  /|  |        
          |  | \/ |  |       
          |  | /\ |  |        
          |__|/__\|__|
[1;37m这里是冥界的大门，门上写着：“凡入此门者，必先舍弃希望……”[2;37;0m

LONG);
    set("exits", ([ /* sizeof() == 1 */                              
               "southup"    :       __DIR__"jin",
               "southdown"    :       __DIR__"river",

]));                                                                                                                          
  set("objects", ([ 
        ]));

  setup();                                                           
}



