inherit ROOM;

void create()
{
          set("short", "铁匠铺");
        set("long", @LONG

  长安城最大的铁匠铺,在这里可以听到"叮,叮,当,当"
地敲打声[1;31m(ask zhang about job)[2;37;0m 。
LONG
        );
  set("no_fight", 1);
        set("freeze",1);
  set("no_magic", 1);
        set("if_bed",1);

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/work" : 1,
        ]));
        set("exits", ([
                  "north" : __DIR__"dongmen",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}

