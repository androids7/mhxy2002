// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "第一狱");
         set ("long", @LONG
             /\                  /\                  /\
            /  \                /  \                /  \
           /  x \              /  x \              /  x \
           / o  \              / o  \              / o  \
          /   o  \            /   o  \            /   o  \ 
         /  o   . \          /  o   . \          /  o   . \
        /      o  x\        /      o  x\        /      o  x\
       /  x   o   o \      /  x   o   o \      /  x   o   o \
      /     o        \    /     o        \    /     o        \
     /  %  o     x .  \  /  %  o     x .  \  /  %  o     x .  \
    / ________________ \/ ________________ \/ ________________ \   
      |_| /    \ |___|     |_| /    \ |___|   |_| /    \ |___|
      |_| /    \ |___|     | | /    \ |___|   |_| /    \ |___| 
      |_| /    \ |___|     |_| /    \ |___|   |_| /    \ |___| 
      |_| /    \ |___|     |_| /    \ |___|   |_| /    \ |___| 
      |_| /    \ |___|     |_| /    \ |___|   |_| /    \ |___| 
      |_| /    \ |___|     |_| /    \ |___|   |_| /    \ |___| 
      |_| /    \ |___|     |_| /    \ |___|   |_| /    \ |___| 
这里就是冥界第一狱----审判死者的法庭，在这里就算是说谎也会被立刻看穿
  
LONG);
                     
set("exits", ([
      "westdown": __DIR__"gu",
            
        ]));

  set("objects", ([ 
	"/d/mingjie/npc/luni":1,
        ]));

        setup();
}
