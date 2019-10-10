#include<iostream>
#include<string.h>
#include<windows.h>
#include <conio.h>
using namespace std;
HANDLE handle1; 
extern void Red(){
	handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle1,
							        FOREGROUND_RED|
						            FOREGROUND_INTENSITY);  //  设为红色
}
extern void White(){
	handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle1, FOREGROUND_RED |//三原色相加白色  恢复白色 
                                    FOREGROUND_GREEN |  
                                    FOREGROUND_BLUE|
									FOREGROUND_INTENSITY);
}
extern void Cyan(){//系统提示色
	handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle1,              //青（蓝+绿）
							        FOREGROUND_GREEN|
							        FOREGROUND_BLUE|
						      	    FOREGROUND_INTENSITY);
}
extern void Blue(){//玩家输入色
	handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle1, FOREGROUND_BLUE|//蓝色
									FOREGROUND_INTENSITY);
}
extern void Green(){
	handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle1,FOREGROUND_GREEN | //绿色
									FOREGROUND_INTENSITY);
}
extern void Yellow(){
	handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle1, FOREGROUND_RED |//三原色相加白色  恢复白色 
                                    FOREGROUND_GREEN |  
									FOREGROUND_INTENSITY);
}
void pause(){//收集Enter 装饰用的
	cin.get();
}
void slowWd(string word){


	for(int i=0;i<word.length();i++){
		cout<<word[i];
		if(kbhit()==0)
			Sleep(50);
		

	}
}
extern void chapterOne(){
	int chooseNum=0;
	string title="第一章"; 
	Red();
	for(int i=0;i<title.length();i++){
		cout<<title[i];
		Sleep(500);
	}White();
	Sleep(3000);
	system("cls");
	slowWd("穿越了宇宙洪荒，凝练了天地玄黄……纵使摆脱了六道轮回，也难逃那天地动荡…… ");pause();
	slowWd(" 神魔陵园位于天元大陆中部地带，整片陵园除了安葬着人类历代的最强者、异类中的顶级修炼者外，其余每一座坟墓都埋葬着一位远古的神或魔，这是一片属于神魔的安息之地。");pause();
	slowWd("陵园内绿草如茵，鲜花芬芳，如果没有那成片的碑林，称之为花园也不为过。陵园外围是高大的雪枫树，惟神魔陵园特有，相传为已逝神魔灵气所化 ");pause();
	slowWd("雪枫树碧绿的枝叶郁郁葱葱，随着微风轻轻摇曳，仿佛在追忆那昔日的辉煌，雪白的花瓣洁白无暇，如雪花一般在空中漫漫飘洒，这是神灵的眼泪，似在诉说那曾经的悲伤。");pause();
	slowWd("墓园的白天和黑夜有着截然相反的景象。");pause();
	slowWd("白天这里仙气氤氲，圣洁的光辉洒遍了陵园的每一寸土地，可以看到由远古神魔那不灭的强大神念幻化成的各种神祗，甚至能看到西方天使起舞，能听到东方仙子歌唱，整片陵园处在一种神圣的氛围之内。");pause();
	slowWd("如果白天这里是神的乐园，那么夜晚这里便是魔的净土。每当夕阳西下，夜幕降临之际，暗黑魔气便开始自墓地中汹涌澎湃而出，另星月为之失色，另天地为之惨淡。此时，可以看到传说中的凶神幻象、恶魔虚影在陵园内肆虐，可以听到远古恶灵那另人头皮发麻的凄厉长嚎。");pause();
	slowWd("神圣而又恐怖的神魔陵园是天元大陆东、西方修炼者共同祭拜的圣园，白天经常可以看到人们前来祭奠，即使到了夜里也能够看到一些特殊的修炼者前来悼念，如：东方的赶尸人、西方的亡灵魔法师……");pause();
	slowWd("陵园惟有日落时最为安宁，整片墓地静悄悄，没有一丝声响。");pause();
	slowWd("又是一个日落时分，又到了神魔异相交替的时间，落日的余辉将神魔陵园渲染的肃穆而又有些诡异。");pause();
	slowWd("每一座神魔墓都被人经心打理过，每座墓前都摆满了鲜花。 ");pause();
	slowWd("在高大的神魔墓群旁有一座低矮的小坟，小坟毫不引人注目，没有墓碑，没有鲜花，一个简简单单的小土包几乎与地齐平。随着岁月的流逝，风雨的侵蚀，这座无名坟墓已被人遗忘在角落里。");pause();
	slowWd("在晚霞中神魔墓群显得更加高大，而无名坟墓则显得更加不起眼。");pause();
	char chooseA1[20]="苏醒",chooseA2[20]="沉睡";
	int egg[100];//彩蛋  某种情形下 重复选择可以触发彩蛋
	for(int i=0;i<100;i++)
		egg[i]=0;
mainChoose1:
	char chooseB1[20];
	do{
		Cyan();cout<<"所以，你想要";Red();cout<<"苏醒";White();cout<<"或者继续";Red();cout<<"沉睡"<<endl;White();
		Blue();cin>>chooseB1;White();
	if(strcmp(chooseA2,chooseB1)==0){
		chooseNum=2;
		break;	
	}
	if(strcmp(chooseA1,chooseB1)==0){
		chooseNum=1;
		break;
	}
	if(strcmp(chooseA1,chooseB1)==1&&strcmp(chooseA2,chooseB1)==1)
		Cyan();cout<<"你想做什么?(来自世界树的提醒，使用红色指令)"<<endl;White();
	}while(strcmp(chooseA1,chooseB1)==1&&strcmp(chooseA2,chooseB1)==1);
	if(chooseNum==2){                                                               //选择1 ”沉睡“
		if(egg[0]!=3&&egg[0]!=5)
			slowWd("白天经常可以看到人们前来祭奠，即使到了夜里也能够看到一些特殊的修炼者前来悼念,守墓老人的目光又一次随意扫过，看到小坟，若有所思。。。就这样，又过去一天");cout<<endl;
		if(egg[0]==3)
			slowWd("老人扫过小坟，有意或是无意的向天空看了一眼，天空中，一男子注视着这小坟，虚无的身形仿佛不存在这个时空中");cout<<endl;
		if(egg[0]==5)
			slowWd("男子注视着坟墓，沉默不语，仿佛在等待着什么，");cout<<endl;
		egg[0]++;
		goto mainChoose1;
	}
	if(chooseNum==1){
												               //选择2 “苏醒”	
		slowWd("突然这座低矮的小墓发生了异变，小墓慢慢龟裂，坟顶的土块开始向下滚落。");pause();
		if(egg[0]==5){
			slowWd("男子突然出现，看了一眼裂开的小墓，黝黑的双眸不起任何波澜，只是男子不解，为何与自己的化演差了几天，随后男子消失的无影无踪，仿佛不属于这个时空");cout<<endl;
			Cyan();cout<<"你正在尝试让该世界中的人发现系统的存在！";White();
		}
		
		char chooseA3[20]="爬出来",chooseA4[20]="不动";
mainChoose2:
		char chooseB2[20];
		do{
			Cyan();cout<<endl<<"指令";White();Red();cout<<"爬出来";Cyan();cout<<"或者";Red();cout<<"不动"<<endl;White;
			Blue();cin>>chooseB2;White();chooseNum=0;
			if(strcmp(chooseA3,chooseB2)==0){//苏醒
				chooseNum=1;
				break;	
			}
			if(strcmp(chooseA4,chooseB2)==0){//不动
				chooseNum=2;
				break;
			}
			if(strcmp(chooseA3,chooseB2)==1&&strcmp(chooseA3,chooseB2)==1)
				Cyan();cout<<"你想做什么?(来自世界树的提醒，使用红色指令)"<<endl;White();
			}while(strcmp(chooseA3,chooseB2)==1&&strcmp(chooseA3,chooseB2)==1);
			if(chooseNum==2){                                                               //选择1 ”沉睡“
				if(egg[1]==0)
					slowWd("我是谁，我在哪，发生了什么，我在土里！！外面传出巨大的声响，吼叫");cout<<endl;
				if(egg[1]==1)
					slowWd("让我闷死在这吧");cout<<endl;
				if(egg[1]==1)
					slowWd(".....");cout<<endl;
				if(egg[1]==3){
					slowWd("我要爬出去");cout<<endl;
					goto compelA1;
				}
				egg[1]++;
				goto mainChoose2;
			}
			if(chooseNum==1){
			compelA1:
				slowWd("一只苍白的手掌从坟中伸了出来，紧接着是另一只，两只手掌用力扒住坟沿，一个一脸茫然之色的青年男子自坟中慢慢爬了上来，蓬乱的长发沾满了泥土，破碎的衣衫紧紧粘在身上。青年除了脸色异常苍白外，整个人看起来非常普通，是那种放在人群中绝对无法让人注意到的角色。");pause();
				slowWd("「这是什么地方？我怎么会在这里？」青年男子喃喃自语，看着眼前成片的坟墓，他神色更加迷茫。");pause();
				Cyan();cout<<"小提示:  可以";Red();cout<<"观察四周";White();
				char chooseA5[20]="观察四周";
				do{
					char chooseB3[20];
					Blue();cin>>chooseB3;White();
					if(strcmp(chooseB3,chooseA5)==0)
						break;
				}while(1);
				slowWd("到处都是坟墓，墓碑，写着一些奇怪的的东西，远处雪枫树碧绿，飘渺的白烟，远处似乎有一个屋子");pause();
				char chooseA7[20]="查看墓碑",chooseA8[20]="像小屋走";
mainChoose3:
				char chooseB4[20];chooseNum=0;
				do{
					cout<<endl;Red();cout<<"查看墓碑";White();cout<<"还是";Red();cout<<"向小屋走"<<endl;White();
					Blue();cin>>chooseB4;White();
				if(strcmp(chooseA8,chooseB4)==0){//小屋
					chooseNum=2;
					break;	
				}
				if(strcmp(chooseA7,chooseB4)==0){//查看墓碑
					chooseNum=1;
					break;
				}
				if(strcmp(chooseA7,chooseB4)==1&&strcmp(chooseA8,chooseB4)==1)
					Cyan();cout<<"你想做什么?(来自世界树的提醒，使用红色指令)"<<endl;White();
				}while(strcmp(chooseA7,chooseB4)==1&&strcmp(chooseA8,chooseB4)==1);
				if(chooseNum==2){                                                               //
					if(egg[2]==0)
						slowWd("那边好像有一个小屋，我想去看看");cout<<endl;
					if(egg[2]!=0&&egg[2]!=3&&egg[2]!=2)
						Cyan();slowWd("正在向小屋移动。。。");White();cout<<endl;
					if(egg[2]==2)
						slowWd("路上的墓碑好生眼熟！");cout<<endl;
					if(egg[2]==3)
						slowWd("这小屋怎么越走越远？");
					egg[2]++;
				goto mainChoose3;
				}
				if(chooseNum==1){
					slowWd(" 他贴近坟碑突然被坟墓的碑文深深吸引住了，此时如果有人看到青年正在聚精会神的看那块墓碑上的古老文字，一定会大吃一惊，因为这种远古的文字连古文化研究联盟的老学者都只能对之摇头苦叹。");pause();
					slowWd("在看完碑文的一刹那，青年神色剧变，惊呼道：「东方武神战无极之墓，这……这是真的吗？这真的是当年那位纵横三界六道，叱咤风云的传奇人物战无极？难道……神也难逃一死？」");pause();
					slowWd(" 旁边另一座高大的神墓再次让他感到了震撼，「西方战神凯撒之墓，凯撒？难道是那位身披黄金战甲，手持黄金圣剑的西方主神？」");pause();
					slowWd("他似乎想到了什么，转头向四外望去，一座座高大的神魔墓矗立在夕阳之中显得格外醒目。");pause();
					slowWd("「东方修仙者牡丹仙子之墓、西方智慧女神娜丝之墓、东方武仙李长风之墓、东方修魔者傲苍天之墓、西方大魔王路西法之墓……」");pause();
					slowWd("「天啊！这个世界怎么了？难道……昔日的神灵都已死去，都……都埋葬在了这里？」青年神色惨变，脸上露出不可思议的神色。");pause();
					slowWd("「但是……东方仙幻大陆和西方魔幻大陆的神灵……怎么葬在了一起呢？」");pause();
					slowWd("蓦然，青年注意到了脚下的小坟，他一下子呆住了，冷汗浸透了他破碎的衣衫，他如坠冰窖一般浑身发凉。");pause();
					slowWd("「我……我是从坟中……爬出来的……」他两眼无神，呆呆发愣，灵魂仿佛被抽离了躯体，他无力的软倒在地。");pause();
					slowWd("「我是辰南，我已……死去，可是……我又复活了……」");pause();
					slowWd("过了好久辰南空洞的双眼才渐渐有了一丝生气，最后露出震惊的神色：「天啊！到底怎么了！既然我已死去，为何又让我从坟墓中爬出？！」");pause();
					slowWd("「难道上苍让我这个无用之人继续那庸碌的一生？！」震惊过后，辰南脸上除了茫然，更多的是痛苦之色，他闭上双眼，双手用力抱住了头。");pause();
					slowWd("他清楚的记得，他在一次决斗中已落败身亡，然而此刻却……");pause();
					slowWd("往事一幕幕浮上心头，那曾经的、那消逝的、那永恒的……在他心中留下了太多的遗憾！");pause();
					slowWd("天地依然广阔，花草依然芬芳，然而他心中却空荡荡，没有一丝着落。");pause();
					slowWd("过了好久辰南才慢慢从地上爬起，他的目光开始在陵园内游离，最后他终于确定这是一片属于神魔的墓群，震撼过后，他渐渐平静下来。");pause();
					slowWd("「最为坚硬的金钢岩墓碑都已明显雕刻上岁月的沧桑，这大概需要万载岁月吧，沧海桑田，万载岁月悠悠而过，嘿嘿……千古一梦啊！」辰南感叹道。");pause();
					slowWd(" 看着那如林的墓碑，他心中充满了疑惑。");pause();
					slowWd("「啸天神虎萧震之墓、三头魔龙该瑞之墓、武圣梁风之墓、神骑士奥托力之幕……看来除了神魔之外，这里还葬有一些人类中的强者和为数不多的异类修炼者。」");pause();
					slowWd("「一万年前到底发生了什么？号称永生不灭的神魔为何死去？仙幻大陆和魔幻大陆的神灵为何葬在了一起？我为什么会被安葬在这里？」");pause();
					slowWd("微风轻轻拂过，吹乱了他脏兮兮的长发，也吹乱了他那颗孤寂的心。");pause();
					slowWd("辰南仰天大喊：「谁能够告诉我，到底发生了什么？」");pause();
					slowWd("没有人回答他。");pause();
					slowWd("远处高大的雪枫树飘落下漫天的花瓣，纷纷扬扬在空中飘洒，落花如泪雨，已逝的神灵在哭泣！");pause();
				}
			}

	}






}





/*mainChoose:
	char chooseB1[20];
	do{
		Cyan();cout<<"所以，你想要";Red();cout<<"苏醒";White();cout<<"或者继续";Red();cout<<"沉睡"<<endl;White();
		Blue();cin>>chooseB1;White();
	if(strcmp(chooseA2,chooseB1)==0){
		chooseNum=2;
		break;	
	}
	if(strcmp(chooseA1,chooseB1)==0){
		chooseNum=1;
		break;
	}
	if(strcmp(chooseA1,chooseB1)==1&&strcmp(chooseA2,chooseB1)==1)
		Cyan();cout<<"你想做什么?(来自世界树的提醒，使用红色指令)"<<endl;White();
	}while(strcmp(chooseA1,chooseB1)==1&&strcmp(chooseA2,chooseB1)==1);
	if(chooseNum==2){                                                               //选择1 ”沉睡“
		if(egg[]!=3&&egg[]!=5)
			slowWd("白天经常可以看到人们前来祭奠，即使到了夜里也能够看到一些特殊的修炼者前来悼念,守墓老人的目光又一次随意扫过，看到小坟，若有所思。。。就这样，又过去一天");cout<<endl;
		if(egg[]==3)
			slowWd("老人扫过小坟，有意或是无意的向天空看了一眼，天空中，一男子注视着这小坟，虚无的身形仿佛不存在这个时空中");cout<<endl;
		if(egg[]==5)
			slowWd("男子注视着坟墓，沉默不语，仿佛在等待着什么，");cout<<endl;
		egg[]++;
		goto mainChoose;
	}*/
