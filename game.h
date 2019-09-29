#include<string.h>
#include<Windows.h>
#include<iostream>
#include<io.h>
#include<fstream>
using namespace std;
extern char one[10]={"1"},two[10]={"2"},three[10]={"3"},four[10]={"4"},five[10]={"5"},six[10]={"6"};
HANDLE handle;
/**
*三种账号类型
*/
struct god{
	char username[20];  //玩家名称
	char pwd[20];      //密码
	int level;    //等级
	int EXP;     //经验
	int ATK;    //攻击力
	int DEF;   //防御力
	int blood;// 血量
	int type;//账户类型
	struct gamer * next;
};
struct gamemaster{
	char username[20];  //玩家名称
	char pwd[20];      //密码
	int level;    //等级
	int EXP;     //经验
	int ATK;    //攻击力
	int DEF;   //防御力
	int blood;// 血量
	int type;//账户类型
	struct gamer * next;
};
struct gamer{
	char username[20];  //玩家名称
	char pwd[20];      //密码
	int level;    //等级
	int EXP;     //经验
	int ATK;    //攻击力
	int DEF;   //防御力
	int blood;// 血量
	int type;//账户类型
	struct gamer * next;
};
extern void setWordRed(){
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,
							        FOREGROUND_RED|
						            FOREGROUND_INTENSITY);  //  设为红色
}
extern void setWordWhite(){
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED |//三原色相加白色  恢复白色 
                                    FOREGROUND_GREEN |  
                                    FOREGROUND_BLUE|
									FOREGROUND_INTENSITY);
}
extern void setWordCyan(){
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,              //青（蓝+绿）
							        FOREGROUND_GREEN|
							        FOREGROUND_BLUE|
						      	    FOREGROUND_INTENSITY);
}
extern void setWordBlue(){
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE|//蓝色
									FOREGROUND_INTENSITY);
}
extern void setWordGreen(){
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,FOREGROUND_GREEN | //绿色
									FOREGROUND_INTENSITY);
}
extern void setWordYellow(){
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED |//三原色相加白色  恢复白色 
                                    FOREGROUND_GREEN |  
									FOREGROUND_INTENSITY);
}


 /**
*将文档读取到链表中
*/   

gamer *readfile(){
 
	gamer *head,*tail,*tmp;     
    int i;      
    char c;      
    FILE *fp=NULL;    //文件指针  
    int lines=1; //lines行数  
    fp=fopen("d:\\characterData.txt", "r");//打开d盘根目录下的characterData.txt文件      
    if(fp)      
    {      
        while((c=fgetc(fp)) != EOF)   //获取文件中的'\n'数即行数  
            if(c=='\n') lines++;      
        fclose(fp);                   //关闭文件  
    }      
    fp=fopen("d:\\characterData.txt", "r"); //打开d盘根目录下的characterData.txt文件  
    for(i=1;i<lines;i++)             //循环读取文件中的内容 并需要将其数据添加到链表中  
    {      
        if(i==1)                      //第一个链表节点      
        {      
            head=new gamer;  
            tmp=tail=head;   
            fscanf(fp,"%d%d%d%d%d%s%s%d",&tmp->ATK,&tmp->blood,&tmp->DEF,&tmp->EXP,&tmp->level,tmp->pwd,tmp->username,&tmp->type);               
        }      
        else      
        {      
            tmp=new gamer;  
            fscanf(fp,"%d%d%d%d%d%s%s%d",&tmp->ATK,&tmp->blood,&tmp->DEF,&tmp->EXP,&tmp->level,tmp->pwd,tmp->username,&tmp->type);              
        }      
            tail->next=tmp;      
            tail=tmp;      
    }
	if(lines!=1)
		tail->next=NULL;      
    fclose(fp);      
    return head;      
} 

extern void fullScreen(){
	/*
	读写文件
	//ofstream write;
	//write.open("d:\\cmdFullScreen.txt");
	ofstream write("d:\\cmdFullScreen.txt");
	write<<" ";
	write.close();
	rename("d:\\cmdFullScreen.txt","d:\\cmdFullScreen.bat");
	 */ 
	//SwitchToThisWindow(set,true);切换焦点
	string word = "Tip:";
	for(int i=0;i<word.length();i++){
		cout<<word[i];
		Sleep(100);}
	cout<<endl;
	cout<<"    For a better game experienc,Please run in full screen mod";
	Sleep(1000);
	cout<<".";
	Sleep(1000);
	cout<<".";
	Sleep(1000);
	cout<<".";
	keybd_event(18,MapVirtualKey(0x12, 0),0,0);
	keybd_event(13,MapVirtualKey(0x0D, 0),0,0);
	keybd_event(13,MapVirtualKey(0x0D, 0),2,0);
	keybd_event(18,MapVirtualKey(0x12, 0),2,0);
	system("cls");
	setWordRed();
	cout<<endl<<endl<<" Automatic full screen"<<endl;
	setWordWhite();
	cout<<"(or Alt+Enter  quit full screen)";
	Sleep(4000); 
	system("cls");

}
extern void cmdResolution(char menu[10]){
	char on[10]={"on"},off[10]={"off"};
	if(strcmp(menu,on)==0){
		system("mode con cols=270 lines=100");//270*150
		keybd_event(17,MapVirtualKey(0x11, 0),0,0); //按下Ctrl
		for(int i=0;i<40;i++)
			mouse_event(MOUSEEVENTF_WHEEL,0,0,(DWORD)-50,0);//下滚
		keybd_event(17,MapVirtualKey(0x11, 0),2,0);  //松开Ctrl
	}
	if(strcmp(menu,off)==0){
		system("mode con cols=189 lines=50");
		keybd_event(17,MapVirtualKey(0x11, 0),0,0);
		for(int i=0;i<20;i++)
			mouse_event(MOUSEEVENTF_WHEEL,0,0,(DWORD)50,0);//上滚
		keybd_event(17,MapVirtualKey(0x11, 0),2,0);



	}
}
extern void loading(char word[20]){
	system("cls");
	for(int i=1;i<4;i++){
				 cout<<word;Sleep(500);
				 cout<<".";Sleep(500);
				 cout<<".";Sleep(500);
				 cout<<".";Sleep(500);
				 system("cls");


	 }
}

extern void menu(gamer *gamer1){
	cout<<"                                              *    *                                                                                "<<endl;
	cout<<"                                          *           *                                                                             "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	cout<<"                                        *               *                                                                           "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	cout<<"                                        *               *                                                                           "<<endl;
	cout<<"                                         *             *                                                                            "<<endl;
	cout<<"                                          *           *                                                                             "<<endl;
	cout<<"                            *               *       *              *                                                                "<<endl;
	cout<<"                                  *       *    *  *   *      *                                                                      "<<endl;
	cout<<"                                  *       *           *      *                                                                      "<<endl;
	cout<<"                            *                 *    *               *                                                                "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	cout<<"                                              *    *                                                                                "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	cout<<"                                             *      *                                                                               "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	cout<<"                                          *            *                                                                            "<<endl;
	cout<<"                                                                                                                                    "<<endl;
	char menu1[10];
	cin>>menu1;
	if(strcmp(menu1,one)==0){//返回游戏

	}
	if(strcmp(menu1,two)==0){//人物属性

	}
	if(strcmp(menu1,three)==0){//装备

	}
	if(strcmp(menu1,four)==0){//技能

	}
	if(strcmp(menu1,five)==0){//保存
		
	}
	if(strcmp(menu1,six)==0){//退出游戏
		
	}




}
extern void collectEnter(){//收集Enter 装饰用的
	cout<<"click Enter to continue..."<<endl;
	cin.get();cin.get();
	
}
extern void slowWord(string word){
	for(int i=0;i<word.length();i++){
		cout<<word[i];
		Sleep(100);
	}
}

/**
*注册用户信息，只有第三级用户可被注册，即玩家用户，
*初始化角色属性
*管理员(二级)和创始者账号(一级)不可直接注册，达成某种条件(没效果好，通关怎么样)即可注册
*/
struct gamer signUp(){
	cmdResolution("on");
	char pwd1[20],pwd2[20];//注册密码需要输入两次
	gamer gamer1;
	while(1){
	cout<<endl<<"what is your name?"<<endl;
	setWordBlue();
	cin>>gamer1.username;
	setWordWhite();
	gamer * p;
	p=readfile();
	int judgenumber=1;
	while(p!=NULL){
		if(strcmp(p->username,gamer1.username)==0){
			cout<<gamer1.username<<" was exist ,please use other name"<<endl;
			judgenumber=2;
			break;
		}
		p=p->next;
	}
	if(judgenumber==1)
		break;

	}
	while(1){
	cout<<endl<<"        password:";
	setWordBlue();
	cin>>pwd1;
	setWordWhite();
	cout<<"confirm password:";
	setWordBlue();
	cin>>pwd2;
	setWordWhite();
		if(strcmp(pwd1,pwd2)==0){
			strcpy(gamer1.pwd,pwd2);
			cout<<endl<<"success sign up!!"<<endl<<"now ,you have your own account in VIRTUSL ,have a good time! "<<endl<<"enjoy!"<<endl;
			break;
		}else cout<<endl<<"wrong password try again!!"<<endl;
	}                         //初始化玩家属性
	gamer1.ATK=1;            //初始攻击
	gamer1.blood=100;       //初始血量
	gamer1.DEF=10;         //初始防御
	gamer1.EXP=0;         //初始经验
	gamer1.level=1;      //初始等级
	gamer1.type=3;      //类型为玩家（注册只能注册三级账户即玩家
  	FILE *fp=NULL;    //将玩家数据存储在 “characterData.txt” 中  
	fp=fopen("d:\\characterData.txt","a");
	fprintf(fp,"%d %d %d %d %d %s %s %d\n",gamer1.ATK,gamer1.blood,gamer1.DEF,gamer1.EXP,gamer1.level,gamer1.pwd,gamer1.username,gamer1.type);//写入文件      
        fclose(fp);  //释放指针 关闭文件    
	return gamer1;
};
struct gamer login(){
	int result=4;//保存judgeid返回值，记录account类型 若result=4 怎说明登录未通过  1 账户不存在  2 密码正确  0 密码错误
	int time=5;//time为输入密码的次数 超出锁定系统
	char menu[10];
	char account[20];
	struct gamer gamer1;
	do{  //如果
		do{  //防止键入其他字符 控制输入字符为1和2
			FILE *fp=NULL;         //用户进行操作之前检测计算机上是否存在注册信息
			 fp=fopen("d:\\characterData.txt", "r"); //打开d盘根目录下的characterData.txt文件  
				if(fp==NULL){
					cout<<"no account in system please sign up!"<<endl;
					collectEnter();
					god godRoot={"root","iamgod777",99,2147483646,2147483646,2147483646,2147483646,1,NULL};
					fp=fopen("d:\\characterData.txt", "w");
					fprintf(fp,"%d %d %d %d %d %s %s %d\n",godRoot.ATK,godRoot.blood,godRoot.DEF,godRoot.EXP,godRoot.level,godRoot.pwd,godRoot.username,godRoot.type);//写入文件      
					 fclose(fp);  //释放指针 关闭文件    
					cout<<"now is sign up:"<<endl;
					signUp();
				} 
		cout<<endl<<"sign up(enter 1) or sign in(enter 2)?"<<endl;
		setWordBlue();
		cin>>menu;
		setWordWhite();
		if(strcmp(menu,one)==0){
			 gamer1=signUp();
		}
		if(strcmp(menu,two)==0){
			while(time>0){
			cout<<endl<<"Please input your account"<<endl;
			setWordBlue();
			cin>>account;
			setWordWhite();
			    char password[20];    
			 gamer *p,*head;     
			 head=readfile();
			 p=head;
			 while(p!=NULL){
			 if(strcmp(p->username,account)==0){//循环用来验证账户是否存在
				cout<<endl<<"password:";
				setWordBlue();
				cin>>password;
				setWordWhite();
				if(strcmp(p->pwd,password)==0){
					result=2;  // 密码正确   找到了数据库中对应的数据赋值给gamer1在有函数login()将账户返回
					gamer1.ATK=p->ATK;gamer1.blood=p->blood;gamer1.DEF=p->DEF;gamer1.EXP=p->EXP;gamer1.level=p->level;gamer1.next=p->next;strcpy(gamer1.pwd,p->pwd);gamer1.type=p->type;strcpy(gamer1.username,p->username);

				}
				else
					result=0;  // 密码错误
			 }
			 p=p->next;
			 }
			 if(result==4){//循环结束result的值4没有被改变说明指定账户没有被找到
						result=1;
					}
			if(result==0){//0 密码错误
				setWordRed();
 				time--;cout<<endl<<"Wrong Password!! you only have "<<time<<" times to try";
				setWordWhite();
				collectEnter();
				
			if(time==0){
				cout<<endl<<"you run out of your opportunities，the system is lock";
				exit(0);}
			}
			if(result==1){//1 账户不存在
				cout<<endl<<"account is not exist!"<<endl;
				 collectEnter();
				 cout<<endl<<"please try again(1) or sign up(2)！";
				char menu1[10];
				 cin>>menu1;
				 if(strcmp(menu1,one)==0){
					 cout<<"account :"<<endl;
					 cin>>account;
					 
					    head=readfile();
					 p=head;
					while(p!=NULL){
						if(strcmp(p->username,account)==0){
							cout<<endl<<"password:";
							cin>>password;
								if(strcmp(p->pwd,password)==0){
									result=2;  // 密码正确   找到了数据库中对应的数据赋值给gamer1在有函数login()将账户返回
									gamer1.ATK=p->ATK;gamer1.blood=p->blood;gamer1.DEF=p->DEF;gamer1.EXP=p->EXP;gamer1.level=p->level;gamer1.next=p->next;strcpy(gamer1.pwd,p->pwd);gamer1.type=p->type;strcpy(gamer1.username,p->username);
								}	
								else
									result=0;  // 密码错误
							}
						
							p=p->next;
					 }
					if(result==4){//循环结束result的值没有被改变说明指定账户没有被找到
						result=1;
					}
				 }
				if(strcmp(menu,two)==0){
					gamer1=signUp();
				}
			}
			if(result==2){//2 密码正确
				system("cls");  //显示方面的一些优化
					cout<<"Account  Authentication";Sleep(300);
					cout<<".";Sleep(300);
					cout<<".";Sleep(300);
					cout<<".";Sleep(300);
					setWordRed();
					cout<<"      Passed  "<<endl;
					setWordWhite();
					cout<<"Password Authentication";Sleep(300);
					cout<<".";Sleep(300);
					cout<<".";Sleep(300);
					cout<<".";Sleep(300);
					SetConsoleTextAttribute(handle,
											FOREGROUND_RED|
											FOREGROUND_INTENSITY);//设为红色
					cout<<"      Passed  "<<endl;
					SetConsoleTextAttribute(handle,
									FOREGROUND_RED |  //恢复白色
                                    FOREGROUND_GREEN |  
                                    FOREGROUND_BLUE|
									FOREGROUND_INTENSITY);

				return gamer1;
			}
			}
		}
		if(strcmp(menu,one)==1&&strcmp(menu,two)==1){
			cout<<endl<<"menu is not exist！！"<<endl;
			collectEnter();
		}
		}while(strcmp(menu,one)==1&&strcmp(menu,two)==1) ;  
	}while(result==4);//result 4 登录未通过

}
extern void playGmae(gamer * gamer1){




}
/*
   HWND GetConsoleHwnd(void)
   {
       #define MY_BUFSIZE 1024 // Buffer size for console window titles.
       HWND hwndFound;         // This is what is returned to the caller.
       char pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
                                           // WindowTitle.
       char pszOldWindowTitle[MY_BUFSIZE]; // Contains original
                                           // WindowTitle.

       // Fetch current window title.

       GetConsoleTitleA(pszOldWindowTitle, MY_BUFSIZE);

       // Format a "unique" NewWindowTitle.

       wsprintfA(pszNewWindowTitle,"%d/%d",
                   GetTickCount(),
                   GetCurrentProcessId());

       // Change current window title.

       SetConsoleTitleA(pszNewWindowTitle);

       // Ensure window title has been updated.

       Sleep(40);

       // Look for NewWindowTitle.

       hwndFound=FindWindowA(NULL, pszNewWindowTitle);

       // Restore original window title.

       SetConsoleTitleA(pszOldWindowTitle);

       return(hwndFound);
   }
	

*/



