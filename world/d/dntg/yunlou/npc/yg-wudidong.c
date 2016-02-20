//by tianlin@mhxy 2001.9.18
#include <ansi.h>

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title",CYN"�޵׶�С��"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("blade", j+random(15));
        me->set_skill("kugu-blade", j+random(15));
        me->set_skill("sword",j+random(15));
        me->set_skill("qixiu-jian",j+random(15));
        me->set_skill("lingfu-steps", j+random(15));
        me->set_skill("yaofa", j+random(15));
        me->set_skill("huntian-qigong", j+random(15));
        me->set_skill("yinfeng-zhua", j+random(15));

        me->map_skill("force", "huntian-qigong");
        me->map_skill("blade", "kugu-blade");
        me->map_skill("sword","qixiu-jian");
        me->map_skill("parry", "kugu-blade");
        me->map_skill("spells", "yaofa");
        me->map_skill("dodge", "lingfu-steps");
        me->map_skill("unarmed", "yinfeng-zhua");

	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: cast_spell, "huanying" :),
        (: cast_spell, "suliao" :),
    //    (: exert_function, "roar" :),
      //  (: exert_function, "shield" :),
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/sword/qingfeng");
        else
           weapon=new("/d/obj/weapon/blade/jindao");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
