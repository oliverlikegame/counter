#include<string.h>
#include<iostream>
using namespace std;

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
/**
*注册用户信息，只有第三级用户可被注册，即玩家用户，
*初始化角色属性
*管理员(二级)和创始者账号(一级)不可再本程序内注册
*/
struct  gamer signUp(   ){
	char pwd1[20],pwd2[20];//注册密码需要输入两次
	gamer gamer1;
	cout<<endl<<"what is your name?"<<endl;
	cin>>gamer1.username;
	while(1){
	cout<<endl<<"        password:";
	cin>>pwd1;
	cout<<"confirm password:";
	cin>>pwd2;
		if(strcmp(pwd1,pwd2)==0){
			strcpy(gamer1.pwd,pwd2);
			cout<<endl<<"success sign up!!"<<endl;
			break;
		}else cout<<endl<<"wrong password try again!!"<<endl;
	}                         //初始化玩家属性
	gamer1.ATK=1;            //初始攻击
	gamer1.blood=100;       //初始血量
	gamer1.DEF=10;         //初始防御
	gamer1.EXP=0;         //初始经验
	gamer1.level=1;      //初始等级
	gamer1.type=3;      //类型为玩家（注册只能注册三级账户即玩家
  	FILE *fp;    //将玩家数据存储在 “characterData.txt” 中  
	fp=fopen("d:\\characterData.txt","a");
	fprintf(fp,"%d %d %d %d %d %s %s %d\n",gamer1.ATK,gamer1.blood,gamer1.DEF,gamer1.EXP,gamer1.level,gamer1.pwd,gamer1.username,gamer1.type);//写入文件      
        fclose(fp);  //释放指针 关闭文件    
	return gamer1;
};
 /**
*将文档读取到链表中
*/   
gamer *readfile(){
 
	gamer *head,*tail,*tmp;     
    int i;      
    char c;      
    FILE *fp;    //文件指针  
    int lines=1; //lines行数  
    fp=fopen("d:\\characterData.txt", "r");//打开d盘根目录下的student.txt文件      
    if(fp)      
    {      
        while((c=fgetc(fp)) != EOF)   //获取文件中的'\n'数即行数  
            if(c=='\n') lines++;      
        fclose(fp);                   //关闭文件  
    }      
    fp=fopen("d:\\characterData.txt", "r"); //打开d盘根目录下的student.txt文件  
    if(fp==NULL)      
    {      
         cout<<"no account please sign up!"<<endl;
		cout<<"click Enter to continue..."<<endl;
		cin.get();cin.get();
		signUp(); 
    }      
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
    tail->next=NULL;      
    fclose(fp);      
    return head;      
} 

struct gamer login(){
	int result=0;//保存judgeid返回值，记录account类型 若account=0 怎说明登录未通过
	int time=5;//time为输入密码的次数 超出锁定系统
	int menu;
	char account[20];
	struct gamer gamer1;
	do{  
		do{  //防止键入其他字符
		cout<<endl<<"sign up(enter 1) or sign in(enter 2)?"<<endl;
		
		cin>>menu;
		if(menu==1){
			 gamer1=signUp();
		}
		if(menu==2){
			while(time>0){
			cout<<endl<<"Please input your account"<<endl;
			cin>>account;
			    char password[20]; 
			gamer *p,*head;     
			 head=readfile();
			 p=head;
			 while(p!=NULL){
			 if(strcmp(p->username,account)==0){//验证账户是否存在
				cout<<endl<<"password:";
				cin>>password;
				if(strcmp(p->pwd,password)==0){
					result=2;  // 密码正确   找到了数据库中对应的数据赋值给gamer1在有函数login()将账户返回
					gamer1.ATK=p->ATK;gamer1.blood=p->blood;gamer1.DEF=p->DEF;gamer1.EXP=p->EXP;gamer1.level=p->level;gamer1.next=p->next;strcpy(gamer1.pwd,p->pwd);gamer1.type=p->type;strcpy(gamer1.username,p->username);

				}
				else
					result=0;  // 密码错误
			 }
		  	 else {result=1;} //账户不存在
			 p=p->next;
			 }
			if(result==0){//0 密码错误
 				time--;cout<<endl<<"wrong password! you only have "<<time<<" times to try";
				cout<<endl<<"click Enter to continue..."<<endl;
				cin.get();cin.get();
				
			if(time==0){
				cout<<endl<<"you run out of your opportunities，the system is lock";
				exit(0);}
			}
			if(result==1){//1 账户不存在
				cout<<endl<<"account is not exist!"<<endl;
				 cout<<"click Enter to continue..."<<endl;
				 cin.get();cin.get();
				 cout<<endl<<"please try again(1) or sign up(2)！";
				 int menu1;
				 cin>>menu1;
				 if(menu1==1){
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
							else 
							{result=1;} //账户不存在
							p=p->next;
					 }
	    
				 }
				if(menu1==2){
					gamer1=signUp();
				}
			}
			if(result==2){//2 密码正确
				return gamer1;
			}
			}
		}
		if(menu!=1&&menu!=2){
			cout<<endl<<"menu is not exist！！"<<endl;
			cout<<"click Enter to continue..."<<endl;
				 cin.get();cin.get();
		}
		}while(menu!=1&&menu!=2) ;  
	}while(result==0);//result 0 登录未通过

}
 
