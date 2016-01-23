#include<stdio.h>
#include<string.h>

struct GOODS
{
	char name[20];               // 物品名字
	char nam;                    // 符号
	int q;                       // 数量
};

struct EQUIPMENT
{
	char name[20];               // 装备名字
	char kind[20];               // 装备种类
	int grd;                     // 装备级数
	char rank;                   // 装备级别
	double axHP;                 // 增加生命量
	double axMP;                 // 增加魔法量
	double aatc;                 // 增加攻击量
	double adef;                 // 增加防御量
};

struct CHARACTER
{
	char name[20];               // 名字
	int grd;				   	 // 等级
	char prof[20];               // 职业
	double xHP;	      	         // 血上限
	double HP;
	double xMP;                  // 蓝上限
	double MP;
	double atc;				     // 攻击力
	double def;			         // 防御力
	double mny;			         // 金币
	struct EQUIPMENT equ[24];	 // 装备
	double xexp;			     // 经验上限
	double exp;		  	         // 经验值
	struct GOODS goods[17];		 // 物品
	char v[20];                  // 所在地方
	int t;						 // 物品变量
	int e;                       // 装备变量
	int n,m;                     // 临时变量
	char filename[100];          // 文件
	int p;                       // 角色号
};

void main()
{
	struct CHARACTER cha;
	double a[12];
	struct GOODS c[17];
	struct EQUIPMENT b[24];
 
	int i,k,p;
	FILE* fr;
	FILE* fp;
	//printf("%d\n",sizeof(struct GOODS));    //28
	//printf("%d\n",sizeof(struct EQUIPMENT));    //80
	
	fr = fopen("aaaaaa.ys","rb");
	fp = fopen("1.ys","wb");
	fread(&p,4,1,fr);
	fwrite(&p,4,1,fp);

	i=1;
	while(i<=p)
	{
	fread(cha.name,20,1,fr);
	fread(cha.prof,20,1,fr);
	fread(cha.v,20,1,fr);
	fread(a,8,12,fr);
	fread(c,sizeof(struct GOODS),17,fr);
	fread(b,sizeof(struct EQUIPMENT),24,fr);

	for(k=0;k<=16;k++)
	{
		strcpy(c[k].name,"\0");
		c[k].nam='\0';
		c[k].q = 0;
	}

	for(k=0;k<=23;k++)
	{
		strcpy(b[k].name,"\0");
		strcpy(b[k].kind,"\0");
		b[k].grd = 0;
		b[k].rank = ' ';
		b[k].axHP = 0;
		b[k].axHP = 0;
		b[k].aatc = 0;
		b[k].adef = 0;
	}

	fwrite(cha.name,20,1,fp);
	fwrite(cha.prof,20,1,fp);
	fwrite(cha.v,20,1,fp);
	fwrite(a,8,12,fp);
	fwrite(c,sizeof(struct GOODS),17,fp);
	fwrite(b,sizeof(struct EQUIPMENT),24,fp);
	i++;
	}

	fclose(fr);
	fclose(fp);
}