//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "少林寺");
set("long", @LONG
    

　　从此以北的方圆五百余里，就都是少林寺了，共有五座山峰，
五峰拱卫连绵，从山谷吹来的习习凉风使这块小盆地的沟沟洼洼
里，到处都有美的色彩与施律。[4;53m[5m[33m(此地还没有做好,请不要进入
谢谢合作!)[2;37;0m

LONG );


set("exits", ([
  "northdown"   : "/d/southern/shaolin/shandao5",
 
]));


set("objects", ([
 "/d/city/npc/vikee": 1,

]));



set("outdoors", 1);

setup();
}
