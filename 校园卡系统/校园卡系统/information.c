#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include "information.h"

//计算所有学生本日,及本月以前的日期的上机总时长(hour),及费用，并存入adm中
void uDay(Admini* adm, Student* stu, Date date, int Sn) {
	// 先将每天的总时长和费用清零
	for (int k = 0; k < date.day; k++) {
		adm->daySum[k].Time = 0;
		adm->daySum[k].Fee = 0;
	}

	// 遍历学生数组
	for (int i = 0; i < Sn; i++) {
		// 遍历该学生记录数组
		for (int j = 0; j < stu[i].rNum; j++) {
			if (date.year == stu[i].totalRecord[j].starttime.year &&
				date.month == stu[i].totalRecord[j].starttime.month &&
				date.day >= stu[i].totalRecord[j].starttime.day) {
				// 确保日期不超过当前日期
				if (stu[i].totalRecord[j].starttime.day <= date.day) {
					adm->daySum[stu[i].totalRecord[j].starttime.day - 1].Time += (stu[i].totalRecord[j].duration / 60.0);
				}
			}
		}
	}

	// 所有记录时长累加完成后，统一计算每天的费用
	for (int k = 0; k < date.day; k++) {
		adm->daySum[k].Fee = adm->daySum[k].Time * 0.6;
	}
}


void uMon(Admini* adm, Student* stu, Date date, int Sn) 
{
	// 先将本月的总时长和费用清零
	adm->monSum[date.month - 1].Time = 0;
	adm->monSum[date.month - 1].Fee = 0;

	for (int i = 0; i < Sn; i++) // 遍历学生数组
	{ 
		for (int j = 0; j < stu[i].rNum; j++)// 遍历该学生记录数组
		{ 
			if (date.year == stu[i].totalRecord[j].starttime.year &&
				date.month == stu[i].totalRecord[j].starttime.month) // 累加本月的总时长
				adm->monSum[date.month - 1].Time += (stu[i].totalRecord[j].duration / 60.0);
		}
	}
	adm->monSum[date.month - 1].Fee = adm->monSum[date.month - 1].Time * 0.6;// 计算本月的费用
}

// 计算近五年的上机时长与费用
void uYear(Admini* adm, Student* stu, Date curDate, int Sn) 
{
	for (int i = 0; i < 5; i++) // 先初始化近五年的统计数据
	{
		adm->yearSum[i].Time = 0;
		adm->yearSum[i].Fee = 0;
	}
	// 遍历每个学生
	for (int i = 0; i < Sn; i++) {
		// 遍历该学生的每条记录
		for (int j = 0; j < stu[i].rNum; j++) {
			int recordYear = stu[i].totalRecord[j].starttime.year;
			if ((recordYear >= (curDate.year -4)) && recordYear <= curDate.year) // 累加该年份的上机时长
				adm->yearSum[curDate.year - recordYear].Time += stu[i].totalRecord[j].duration / 60.0;
		}
	}
	for (int i = 0; i < 5; i++) // 计算近五年每年的总费用
		adm->yearSum[i].Fee = adm->yearSum[i].Time * 0.6;
}


//学号匹配函数,匹配成功返回i(学生所在位置），失败返回-1
int IDCompare(Student* stu, int id, int Sn) {
	for (int i = 0; i < Sn; i++) {
		if (stu[i].ID == id&&id!=0) 
		{
			return i; // 返回学生位置
		}
	}
	return -1; // 未找到
}

//密码匹配函数，成功返回1，失败返回0
int PWCompare(char password[], char* pw)
{
	return (0 == strcmp(password, pw));
}

//卡状态显示函数
const char* getCS(int cardSate)
{
	switch (cardSate)
	{
	case 1:
		return "正常";
	case 2:
		return "挂失";
	case 3:
		return "冻结";
	default:
		return "出错";
    }
}

//表头函数，打印表头,学生信息
void stuHead()
{
	printf("%-8s%-10s%-10s%-10s%-15s", "ID", "姓名", "余额", "状态","密码");
	printf("\n");
}

//打印全部学生信息
void printTStu(Student *stu,int Sn)
{
	for (int i=0; i < Sn; i++)
	{
		printf("%-8d%-10s%-10.2lf", stu[i].ID , stu[i].name,stu[i].remain);
		printf("%-10s%-15s", getCS(stu[i].cardState ), stu[i].password);
		printf("\n");
	}
}

//上机记录信息的表头
void recHead()
{
	printf(" %-15s   %-15s %-15s   %-15s    %-15s", "开始时间", "结束时间", "上机时间（分钟）", 
		   
		"地点", "费用（元）");
}

//把学号排序函数,选择交换法,n为储存学生人数
void sortID(Student* stu, int n)
{
	int i, j, m;//m保存本趟最小元素下标
	Student temp;
	for (i = 0; i < n - 1; i++)//循环n-1趟
	{
		m = i;
		for (j = i + 1; j < n; j++)
			if (stu[m].ID > stu[j].ID)
				m = j;
		if (m != i)
		{
			temp = stu[i];
			stu[i] = stu[m];
			stu[m] = temp;
		}
	}
}

//通过ID来查找学生校园卡基本信息函数
void  searchStu(Student* stu)
{
	int i,  findID;
	printf("                                  请输入所需查找ID\n");
	scanf_s("%d", &findID);
	i = IDCompare(stu, findID,Stunum);
	if ( i != -1)  //判断校园卡是否存在
	{
		stuHead();//打印表头
		printf("%-8d%-10s%-10.2f", stu[i].ID, stu[i].name, stu[i].remain);
		printf("%-10s%-15s",getCS(stu[i].cardState), stu[i].password);
	}//存在则打印
	else
	{
		printf("                                  该学生卡不存在!\n");
	}//不存在给出提示
}

//打印时间函数,不会自动转行
void printTime(Date date)
{
	printf("%d/%d/%d %02d:%02d  ",date.day,date.month ,date.year ,date.hour ,date.minute );
}

//打印某个学生基本信息
void printStu(Student stu)
{
	printf("%-8s%-10s%-8s%-8s\n", "ID", "姓名", "余额", "状态");
	printf("%-8d%-10s%-8.2lf", stu.ID ,stu.name ,stu.remain );
	printf("%-8s", getCS(stu.cardState));
	printf("\n\n");
	recHead();
	printf("\n");
	if (stu.rNum == 0)
	{
		printf("暂无上机记录。\n");
	}
	else
	{
		for (int i = 0; i < stu.rNum; i++)
		{
			printTime(stu.totalRecord[i].starttime);
			printTime(stu.totalRecord[i].endtime);
			printf("     %04d       %-20s   %-04.2lf", stu.totalRecord[i].duration
				, stu.totalRecord[i].address
				, stu.totalRecord[i].fee);
			printf("\n");
		}
	}
}

//删除学生校园卡信息函数,返回现有学生人数,n为学生人数
int deleteCard(Student* stu, int *Sn)  
{
	int  findID=0,choice=0;
	Student s = { 0 };
	do
	{
		printf("                                  请输入所需删除ID: ");
		scanf_s("%d", &findID);
		int position = IDCompare(stu, findID, *Sn);
		if (-1 == position)
		{
			printf("                                  该校园卡不存在!\n");
		}
		else
		{
			for (int i = position; i < ((*Sn) - 1); i++)
				stu[i] = stu[i + 1];    //将定位后数据依次往前覆盖
			stu[(*Sn) - 1] = s;
			--(*Sn);   //记录学生人数的减少
			printf("                                  卡片删除成功!\n");
		}
		printf("                                  是否继续删除?\n(YES--1 NO--0)\n");
		do 
		{
			if (scanf("%d", &choice) != 1)
			{
				printf("                                  无效输入，请输入整数！\n");
				while (getchar() != '\n'); // 清除输入缓冲区
			}
		} while (choice<0||choice>1);
	} while (choice);
	return *Sn;    //返回现有学生人数
}




//将卡挂函数，参数为需要挂失的学生结构体
void lossCard(Student *stu)
{
	if (stu->cardState == 2)//检验卡片状态是否已挂失
	{
		printf("                                  卡片%d已挂失!\n", stu->ID);//卡已挂失无需二次操作
		printf("                                  无需二次操作!\n");
	}
	else//卡未挂失
	{
		stu->cardState = 2;//将卡挂失
		printf("                                  卡片%d挂失成功！", stu->ID);
	}
	
}

//解挂函数
void cancelLost(Student *stu)
{
	if (stu->cardState == 1)//正常
	{
		printf("                                  卡片%d状态正常\n", stu->ID);//卡正常
	}
	else if (stu->cardState == 2)//挂失
	{
		stu->cardState = 1;
		printf("                                  卡片%d解挂成功！\n", stu->ID);
	}
	else//冻结
		printf("                                  卡片%d已冻结！\n", stu->ID);
}

// 从键盘获得学生初始数据(管理员权限,传学生人数地址
int readStu(Student* stu, int* Sn)
{
	int n;
	int id = 0;
	printf("                                  请输入学生人数:(1-%d) ", Stunum-*Sn);
	while (scanf("%d", &n) != 1 || n < 1 || (*Sn + n) > Stunum)
	{
		printf("                                  无效输入或者输入人数过大！\n");
		printf("                                  请再次输入: ");
		while (getchar() != '\n'); // 清除输入缓冲区
	}
	for (int i = *Sn; i < *Sn + n; i++)
	{
		printf("                                  输入学生信息\n");
		printf("                                  ID: ");
		while (scanf("%d", &id) != 1 || id < 0|| id ==0)
		{
			printf("                                  ID输入无效，请输入整数\n");
			while (getchar() != '\n'); // 清除输入缓冲区
			printf("                                  ID: "); // 重新提示输入 ID
		}
		if (IDCompare(stu, id, *Sn+i) != -1)
		{
			printf("                                  此ID已存在!\n");
			i--; // 重新输入
			while (getchar() != '\n'); // 清除输入缓冲区
			continue;
		}
		stu[i].ID = id;
		printf("                                  姓名: ");
		scanf_s("%s", stu[i].name,20);
		strcpy(stu[i].password, "@123456"); // 初始密码
		stu[i].remain = 0;
		stu[i].cardState = 1; // 正常
		stu[i].count = 3; // 密码错误机会三次
		stu[i].rNum = 0;//上机记录为0
		Record rec = { 0 };
		for (int j = 0; j < Recnum; j++)
			stu[i].totalRecord[j] = rec;
	}
	*Sn += n; // 更新学生人数
	sortID(stu, *Sn);//排序
	return *Sn; // 返回学生人数
}

//读管理员信息
void readAdm(Admini *adm)
{
	sumRecord sr = { 0 };
	Admini adm_0 = { "A123","A@3366",sr,sr,sr };//后三个数据初始化为0，需后期算
	*adm = adm_0;
}
