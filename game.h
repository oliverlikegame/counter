#include<string.h>
#include<iostream>
using namespace std;
struct god{
	char username[20];  //玩家名称
	char pwd[20];      //密码
	int level;    //等级
	int EXP;     //经验
	int ATK;    //攻击力
	int DEF;   //防御力
	int blood;// 血量
	struct stu * next;
};
struct gamemaster{
	char username[20];  //玩家名称
	char pwd[20];      //密码
	int level;    //等级
	int EXP;     //经验
	int ATK;    //攻击力
	int DEF;   //防御力
	int blood;// 血量
	struct stu * next;
};
struct gamer{
	char username[20];  //玩家名称
	char pwd[20];      //密码
	int level;    //等级
	int EXP;     //经验
	int ATK;    //攻击力
	int DEF;   //防御力
	int blood;// 血量
};
struct  gamer signUp(   ){
	char pwd1[20],pwd2[20];//注册密码需要输入两次
	gamer gamer1;
	cout<<"what is your name?"<<endl;
	cin>>gamer1.username;
	while(1){
	cout<<"password"<<endl;
	cin>>pwd1;
	cout<<"confirm password:"<<endl;
	cin>>pwd2;
		if(strcmp(pwd1,pwd2)==0){
			strcpy(gamer1.pwd,pwd2);
			break;
		}else cout<<"wrong password try again"<<endl;
	}                         //初始化玩家属性
	gamer1.ATK=1;            //初始攻击
	gamer1.blood=100;       //初始血量
	gamer1.DEF=10;         //初始防御
	gamer1.EXP=0;         //初始经验
	gamer1.level=1;      //初始等级
	FILE *fp;    //将玩家数据存储在 “characterData.txt” 中  

          
    struct gamer *p1;  
	fprintf(fp,"%d %d %d %d %d %s %s\n",gamer1.ATK,gamer1.blood,gamer1.DEF,gamer1.EXP,gamer1.level,gamer1.pwd,gamer1.username);//写入文件      
        fclose(fp);  //释放指针 关闭文件    

	

	return gamer1;
};
int judgeid(char account[20]){
	gamer gamer1;    
    char password[20];      
    FILE *fp;    //文件指针   
    fp=fopen("d:\\characterData.txt", "r");//打开d盘根目录下的student.txt文件      
    if(fp==NULL){      
        cout<<"no account please sign up!"<<endl;
		cout<<"click Enter to continue..."<<endl;
		cin.get();cin.get();
		signUp();      
    }      
            fscanf(fp,"%d%d%d%d%d%s%s",&gamer1.ATK,&gamer1.blood,&gamer1.DEF,&gamer1.EXP,&gamer1.level,gamer1.pwd,gamer1.username);              
    fclose(fp);
	if(strcmp(gamer1.username,account)==0){
		cout<<"password:"<<endl;
		cin>>password;
		if(strcmp(gamer1.pwd,password)==0)
			return 2;
		else
			return 0;
		
	
	}
	else    //账户不存在
		return 1;

}
