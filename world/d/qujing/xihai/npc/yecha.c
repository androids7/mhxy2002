//copy from /d/sea/npc/yecha.c

inherit NPC;

void create()
{
        set_name("巡海夜叉", ({"ye cha", "yecha", "cha"}));
        set("long","西海巡海的夜叉，长的青面獠牙，丑陋不堪。\n");
        set("gender", "男性");
        set("per", 10);
        set("str", 20);
        set("max_kee",700);
        set("max_sen", 600);
        set("attitude", "heroism");
        set("combat_exp", 120000+random(30000));
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("unarmed", 80);
        set_skill("fork", 80);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 10);
        set("max_mana", 200);
        set("mana", 200);
        set("mana_factor", 10);
        setup();
        carry_object("/d/obj/armor/shoupi")->wear();
        carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

