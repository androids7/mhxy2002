
mapping longquest=([
//     type   tarid         tarname      topic/obname           ack  
//-----------------------------------------------------------------------
 0 : ({"10","高家庄的救难",
       "听说高家的小姐失踪了，你去打探清楚然后回报！",
       "ask", "laoyu",       "老余头",    "祸事",         "sigh;高家近来有妖怪出没，主人要求高才去找法师来降伏妖怪。",
       "ask", "gao cai",     "高才",      "法师",         "你既然是法师，快请去见我家主人吧！",
       "ask", "gao yuanwai", "高员外",    "妖怪",         "这是一群来无踪去无影的妖怪，他们从后园近来把我女儿抓走了。\n你若是能救出我的女儿，小老儿感激不净。",
       "kill","xia pengzhan","夏鹏展",    "    ",         "sigh;夏鹏展说道：这都是老张在幕后操纵的。\n他贪图高小姐的美色，让我们假扮妖怪将她劫来，我再也不愿替他背这个黑锅了。\n",
       "kill","lao zhang",   "老张",      "    ",         "heihei;老张道：我虽然输了，但你也没赢。你从此以后别想见到高小姐。\n说完就倒下了。\n",
       "give","gao yuanwai", "高员外",    "玉佩",         "高员外老泪纵横：我苦命的女儿啊！你生不见人死不见尸，好惨啊！;cry"
     }),
 1 : ({"12","罗成的生死之谜",
       "罗成是唐朝的开国元勋之一，他死于一场战斗。但有人说他并没死，那只是一场阴谋而已。\n据说有人还在将军府见到过他。你可否探清真相，回报于我？",
       "ask", "qin qiong",   "秦琼",      "罗成",         "sigh;罗成是我表弟，他武艺高强，但不幸死于一场战斗。\n他家只剩一个家人呆在本府。可怜表弟一生忠心为国...",
       "ask", "luo chun",    "罗春",      "罗成",         "我家主人早在十年前就已去世。看你贼头贼脑，莫非是奸王的奸细？;kill $N;小贼拿命来！",
       "ask", "luo cheng",   "罗成",      "罗成",         "kick $N;不知让我说多少遍你才明白，我不是我家主人，只是罗家的一名家将。\n  我家主人早在十年前就已去世。就因为我和罗成长的相象，大家就认为我家主人没死。\n难道我家主人还会从战场逃跑不成！",
       "give","luo cheng",   "罗成",      "〖枪法简介〗", "accept $W;thank $N;罗成愤愤说道：奸王欲得我家祖传枪谱，设计陷害，幸得表哥相救才能不死。\n我也不得不藏在将军府内院。枪谱也在混乱中失落。\n现在这位找回枪谱，真是我家大恩人也！\n", 
     })  
]);    

