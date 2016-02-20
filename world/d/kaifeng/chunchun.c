//By tianlin@mhxy for 2001.9.18部分修改
inherit ROOM;

void create ()
{
  set ("short", "春醇茶栈");
  set ("long", @LONG
茶栈里摆了几张红木桌子，围着桌子放了几条长凳。此处窗明几净，
满屋飘着茶香。里墙是柜台，上面放满了大小不同的茶筒茶罐。东边
门帘通向街头。店铺前挂了一个小小的招牌[1;33m（paizi）[2;37;0m。
LONG);

  set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/chaniang" : 1,
    __DIR__"npc/xiaoer" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "本店急需工作人员，有意者请向茶娘子打听[工作]的事。
             帮助提示:[1;32m1.[1;33mask xiao er about job[2;37;0m
                      [1;32m2.[1;33mask guan shi about panzi[2;37;0m 
                      [1;32m3.[1;33mGo 厨房 xi 脏盘子[2;37;0m
                      [1;32m4.[1;33mgive panzi to xiao er[2;37;0m 
                      [1;32m5.[1;33m近期不招工[2;37;0m
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"shun5",
  "west" : __DIR__"sleeproom",
 "north" : __DIR__"chufang",
]));
  set("pingan", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("no_dazuo", 1);
  set("no_kill", 1);
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        object *inv,kicker;
        int sizeinv,n,tt;
        
        if (dir =="west")
        {
                if ( me->query("PKS") >= 3)
                return notify_fail("你杀过太多的玩家！这儿不欢迎你！\n");        
        
                inv=all_inventory(me);
                sizeinv=sizeof(inv);
        
                while (sizeinv--)
                {
                        if (inv[sizeinv]->is_character())  
                                return notify_fail("你想进去拐卖人口？\n");
                
                }
                
        }

        return ::valid_leave(me, dir);
}

