// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "血之大瀑布");
         set ("long", @LONG
                  $$$$$$$$$$$F 
                 4$$3$$P$$$"$$ 
                 $$F$$$F$$$F$$b 
                d$$ $$$ $$$L4$$r
               4$$P $$$ 3$$$ $$$ 
               $$$ 4$$$ 4$$$ *$$L 
              d$$$ J$$$ 4$$$.^$$$.
             4$$$F $$$$  $$$F $$$$  
             $$$$  $$$$  $$$$ 4$$$r 
            d$$$P .$$$F  $$$$  $$$$ 
           4$$$$% 4$$$F  $$$$  3$$$b 
           $$$$$  $$$$F  $$$$F ^$$$$r
          J$$$$F  $$$$%  $$$$L  $$$$$ 
         .$$$$$. .$$$$.  J$$$$  J$$$$L
这里就是血之大瀑布，是通往第七狱的路口----到现在为止，罪人在地狱里流下
的血和泪，会聚成一圈流下来
LONG);
                     
set("exits", ([
      "westdown": __DIR__"qi",
            "eastup": __DIR__"liu2",
    
        ]));

  set("objects", ([ 
        ]));

        setup();
}
