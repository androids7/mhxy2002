//By tianlin@mhxy for 2001.9.28
//请不要修改制作者的名字谢谢.

#include <ansi.h>
inherit F_DBASE;
void create() 
{
        seteuid(getuid());
        set("channel_id", HIW"复制"NOR+HIC"精灵"NOR+HIR"("NOR+HIY"clone"NOR+HIR")"NOR+HIG);
}

int main(object me, string arg)
{
   object obj;
   string err,msg,str,file,afile,flag;
   string filegold,filesilver,filecoin;
     int times;
    filegold="/clone/money/gold.c";
    filesilver="/clone/money/silver.c";
    filecoin="/clone/money/coin.c";

    if ( !arg )
        return notify_fail("[1;30m指令格式:[2;37;0m [36mclone [1;33m<事物> \n"NOR);
    if (sscanf(arg, "%s %d", file, times) != 2)
    {
        file = arg;
        times = 1;
    }
        seteuid( geteuid(me) );
        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail(HIY"你要复制什麽物件？\n"NOR);
        flag = "";
        if( sscanf( file, "%s %s", flag, afile ) == 2 && flag == "-f" )
        file = afile;
        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail(YEL"没有这个档案(" + file + ")。\n"NOR);

              if(this_player()->query("id")=="yinbin")
                return notify_fail(HIC"除田林以外其他人不得使用此命令。\n"NOR);//这是限制id使用此指令
        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("载入失败：" + err + "\n");
                        return 1;
                }
        }
        if( file->query_unique() )  {
           write("目前在Ｍｕｄ中有"+file->query_number()+
                        "个复制，应最多有"+
                        file->query_compare_number()+"个。\n");
        if( file->in_mud() && flag != "-f" )  {
        write("该物品为" + HIR + "Unique Item" + NOR + "，请用 clone -f 来强行复制。\n");
        return 1;
        }
        }

        err = catch(obj = new(file));
        if (err) {
                write("复制失败：" + err + "\n");
                return 1;
        }
        
         if ((!(file==filegold) && !(file==filesilver) &&
                 !(file==filecoin)) && (times>10))
        {
                return notify_fail(BLINK+HIR"STOP"NOR+HIR"！"NOR+BLINK+HIR"STOP"NOR+HIR"！"NOR+HIW"最多只能复制"NOR+HIC"10"NOR+HIW"个单位！\n"NOR);
        }
        else
                if (times>100)
                {
                return notify_fail(HIM"你真是财迷心窍，金钱最多只能复制"NOR+HIY"100"NOR+HIM"个单位!\n"NOR);
                }          
        
        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "只见$N伸手凌空一指，变出了$n。\n";
        str = me->query("name") + "(" + me->query("id") + ")复制了" + 
                times + "个" + obj->query("name")
                + "(" + obj->query("id") + ")    " + ctime(time())+ "  。\n";
        write_file("/log/cmds/clone", str);  
        CHANNEL_D->do_channel(this_object(),"sys",me->query("name")+
                "("+me->query("id")+")复制了" + 
                  times + "个" + obj->query("name")
                  + "(" + base_name(obj) + ")  。\n");


       if (!obj->is_character()){
       for (int i = times;i>0;i--) {
         obj = new(file);
         obj->move(me);
       }
                write(times + "个" +obj->query("name") + "复制成功，放在你的物品栏。\n");
        message_vision(msg + "\n", me, obj);
                return 1;
        }
       for(int j = times; j>0; j--) {
          obj=new(file);
          obj->move(environment(me));
       }
                write(times + "个" + obj->query("name") + "复制成功，放在这个房间。\n");
        message_vision(msg + "\n", me, obj);
                return 1;

        destruct(obj);
        return notify_fail(CYN"无法复制不能移动的物件(" + file + ")。\n"NOR);
       }

int help(object me)
{
  write(@HELP
指令格式 : clone [1;33m<档名>[2;37;0m

利用此指令可复制任何能移动之物件(含怪物),
物品,武器,也就是npc,obj类型的东西。
[4;53m[1;31mBy tianlin@mhxy for 2001.9.28制作[2;37;0m
HELP
    );
    return 1;
}
