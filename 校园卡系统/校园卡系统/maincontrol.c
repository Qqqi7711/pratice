#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>//为了使用getch函数
#include <stdlib.h>
#include <string.h>
#include"maincontrol.h"
#include <windows.h>  // 用于 Sleep 函数



//退出界面函数----exit(0);

//输入密码函数,返回一个pw数组,记得最后要释放 free
char* getPW()
{
	//用动态数组
	char* pw = (char*)malloc(Pwlength * sizeof(char));
	if (pw == NULL) {
		fprintf(stderr, "                                  内存分配失败!\n");
		return NULL;
	}
	int i=0;
	char ch;
	while (i < Pwlength - 1)
	{
		ch = _getch();  // 无回显读取字符
		if (ch == '\r' || ch == '\n')    // 处理回车确认
		{
			printf("\n");
			pw[i] = '\0';
			break;
		}
		else if (ch == '\b')    // 处理退格删除
		{
			if (i > 0)
			{
				i--;
				printf("\b \b");  // 删除前一个星号
			}
		}
		else       // 正常字符输入
		{
			pw[i++] = ch;
			printf("*");
		}
	}
	return pw;
}

//学生登录函数,返回 position，,成功位置，失败-1
int stuLogin(Student* stu,int *Sn)
{
	int id;
	char* pw=NULL;
	while (1)
	{
		printf("                                  ID：");
		if (scanf("%d", &id) != 1)
		{
			printf("                                  ID输入无效，请输入整数！\n");
			while (getchar() != '\n'); // 清除输入缓冲区
			continue;
		}

		int position = IDCompare(stu, id, *Sn);
		if (position == -1)//账号不存在
		{
			printf("                                  账号已不存在!\n");
			continue;
		}
		if (stu[position].cardState == 3 || (0 == stu[position].count))//被冻结
		{
			printf("                                  该账号已被冻结，请联系管理员\n");
			return -1;
		}
		do
		{
			printf("                                  (初始密码: @123456)\n");
			printf("                                  密码:");
			pw = getPW();
			if (!pw)
			{
				printf("                                  因内存分配失败，密码输入失败\n");
				continue;
			}
			if (PWCompare(stu[position].password, pw))
			{
				printf("                                  登录成功!\n");//登录成功
				free(pw);
				stu[position].count = 3;//登录成功，机会恢复3次
				return position;
			}
			else
			{
				printf("                                  密码错误!\n");//密码错误
				stu[position].count--;//机会减少
				printf("                                  你还有%d次机会!\n", stu[position].count);
			}
			free(pw);
		} while (stu[position].count > 0);
		stu[position].cardState = 3;
		printf("                                  该账户已被冻结，请联系管理员!\n");
		return -1;
	}
}

//管理员登录函数,成功返回1，错误返回0
int admLogin(Admini *adm)
{
	char admId[20] = { 0 };
	char* admPw;
	printf("                                  ID:");
	scanf_s("%s", admId,20);
	if (0 == strcmp(admId, adm->admID))//账号正确
	{
		printf("                                  密码：");
		admPw = getPW();
		if (0 == strcmp(admPw, adm->admPW))
		{
			printf("                                  登录成功!\n");
			return 1;
		}
		else
			printf("                                  密码错误!\n");
		return 0;
	}
	else
	{
		printf("                                  ID错误!\n");
		return 0;
	}
}


//修改密码函数,前提：ID已经匹配成功,参数为学生密码,返回新的密码
char* changePW()
{
	int isValid = 0;
	char *pw1=NULL, *pw2=NULL;
	do 
	{
		// 释放上一次循环分配的内存
		if (pw1) 
		{
			free(pw1);
			pw1 = NULL;
		}
		if (pw2) 
		{
			free(pw2);
			pw2 = NULL;
		}
		printf("                                  新密码:");
		pw1 = getPW();
		if (pw1 == NULL) {
			printf("                                  因内存分配失败，密码输入失败\n");
			continue;
		}
		printf("\n");
		// 再次确认密码
		printf("                                  确认密码:");
		pw2 = getPW();
		printf("\n");
		if (pw2 == NULL) {
			printf("                                  因内存分配失败，密码输入失败\n");
			free(pw1);//释放pw1，如果pw2获取内存失败
			pw1 = NULL;
			continue;
		}
		if (PWCompare(pw1, pw2))
			isValid = 1;
		else 
			printf("                                  密码不匹配，请重新输入：\n");
	} while (!isValid);
	// 释放 pw1，只返回 pw2
	free(pw1);
	printf("                                  修改成功！\n");
	return pw2;
}

//修改学生校园卡信息函数,i为学生所在位置(传址）,修改成功返回1，选择返回返回0
int changeCard(Student* stu, int choice)
{
	switch (choice)
	{
	case 1:
		printf("                                  新的ID号：\n");
		scanf_s("%d", &(stu->ID));
		while (getchar() != '\n');//清除缓冲区
		printf("                                  修改成功！\n");
		saveSFile(stu, 1); // 保存修改后的学生信息
		break;
	case 2:
		printf("                                  新的用户名：\n");
		scanf_s("%s", stu->name, 20);
		printf("                                  修改成功！\n");
		saveSFile(stu, 1); // 保存修改后的学生信息
		break;
	case 3:
		recharge(stu);
		saveSFile(stu, 1); // 保存修改后的学生信息
		break;
	case 4:
		printf("                                  新的卡状态（1--正常 2--挂失 3--冻结）：\n");
		int state = 0;
		scanf_s("%d", &state);
		while (state < 1 || state>3)
		{
			printf("                                  输入有误！\n");
			printf("                                  请重新输入！\n");
			scanf_s("%d", &state);
		}
		(stu->cardState) = state;
		if (state == 1)
			stu->count = 3;
		else if (state == 3)
			stu->count = 0;
		printf("                                  修改成功！\n");
		saveSFile(stu, 1); // 保存修改后的学生信息
		break;
	case 0:
		return 0;
		break;
	}
	return 1;
}

//充值函数
void recharge(Student* stu)
{
	int money = 0;
	printf("                                  充值金额(元)(整钱)：");
	while (scanf("%d", &money) != 1 || money <= 0)
	{
		printf("                                  无效充值，请重新充值!\n");
		printf("                                  充值金额(元)(整钱)：");
		while (getchar() != '\n'); // 清除输入缓冲区
	}
	stu->remain += money;
	printf("                                  成功存入%d元！\n", money);
	while (getchar() != '\n'); // 清除输入缓冲区
	saveSFile(stu, 1);
}

//管理员登录选项
void adminiL(Admini *adm,Student *stu,int *Sn)
{
	if (admLogin(adm))//管理员登录成功
	{
		adminMenu();//调用管理员二级菜单
		int choice=getChoice(2);
		runMain_2adm(adm,stu,choice,Sn);
	}
}

//学生登录选项,成功返回1，失败返回0
void stuL(Admini* adm, Student* stu, int* Sn)
{
	int position = stuLogin(stu, Sn);
	if (position == -1) // 登录失败
	{ 
		mainMenu();
		int choice = getChoice(3);
		saveSFile(stu, *Sn);
		runMain_1(stu, adm, choice, Sn);
	}
	else 
	{
		stuMenu();
		int choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position); // stu 是数组指针
	}
}

//管理员查询信息选择函数
void aSearInform(Admini * adm,Student* stu,int *Sn)
{
	admSearMenu();
	int choice  = getChoice(2);
	runMain_4(adm,stu, choice,Sn);
}

//管理员学生信息管理选择函数
void stuInformManage(Admini*adm,Student* stu, int *Sn)
{
	stuInformMenu();
	int choice = getChoice(4);
	runMain_3adm(adm,stu, choice, Sn);
}

//修改学生信息选项
void  changeStu(Admini* adm, Student* stu, int* Sn)
{
	int id = 0;
	printf("                                  请输入要修改的ID: ");
	scanf_s("%d", &id);
	int position = IDCompare(stu, id, *Sn);
	if (-1 != position)//找到
	{
		changeCardMenu();//显示菜单
		int choice = getChoice(4);
		if (changeCard(&stu[position], choice))
		{
			sortID(stu, *Sn);//排序
			saveSFile(stu, *Sn);//保存
		}
		else
			stuInformManage(adm, stu, Sn);
	}
	else
		printf("                                  该卡不存在！\n");
}



//收入情况选项
void income(Admini* adm,Student *stu,int *Sn)
{
	totalFee();
	int choice = getChoice(3);
	runMain_3adm2( adm,stu,choice,Sn);
}

//日收入选项
void dayIncome(Admini *adm,Date curDate)
{
	printf("%d/%d  收入情况\n ", curDate.month, curDate.year);
	printf("%-5s%-14s  %-12s", "日期（日） ", "总时间（小时）", "总费用（元）");
	printf("\n");
	for (int i = 0; i < curDate.day; i++)
	{
		printf("   %-02d         %-04.2lf             %-04.2lf", i +1, adm->daySum[i].Time, adm->daySum[i].Fee);
		printf("\n");
	}
}

//月收入情况
void monIncome(Admini* adm,int year,int month)
{
	printf(" %d  收入情况\n ", year);
	printf("%-5s%-14s  %-12s", "日期（月） ", "总时间（小时）", "总费用（元）");
	printf("\n");
	for (int i = 0; i < month; i++)
	{
		printf("   %-02d        %-04.2lf            %-04.2lf", i + 1, adm->monSum[i].Time, adm->monSum[i].Fee);
		printf("\n");
	}
}

//近五年收入情况
void yearIncome(Admini* adm,int year)
{
	printf("%-5s%-14s  %-12s", "日期（年） ", "总时间（小时)", "总费用（元）");
	printf("\n");
	for (int i = 0; i <5 ; i++)
	{
		printf(" %-04d       %-04.2lf             %-04.2lf", year-i, adm->yearSum[i].Time, adm->yearSum[i].Fee);
		printf("\n");
	}
}

//检验时间
int timeValid(Date start, Date end)
{
	int dur=useTime(start, end);
	if (dur < 0)
		return 0;
	else if (start.day != end.day|| start.month != end.month||start.year !=end.year )
		return 0;
	return 1;
}

//上机选项
void useCom(Student* stu) 
{
	Date t1 = recordTime();
	if (t1.hour > 22 ||t1.hour < 7)
	{ // 7 点到 23 点以外禁止上网
		printf("                                  早上七点到晚上十一点禁止上网，请好好休息//^o^//!\n");
		return;
	}
	printf("                                  开始上机（现在开始计时...）\n");
	printf("                                  请注意费用为 0.01(元)/分钟!\n");
	printf("                                  如果使用时长小于1分钟将不收费,且不计入上机记录中。\n");
	printf("                                  期待您有一次愉快的使用体验//^o^//\n");
	printf("                                  请按 '0' 以结束上机!\n");
	Date t2;
	int dur;
	int choice = 0;
	// 循环检查是否达到 23 点或者用户主动结束
	while (1) 
	{
		if (_kbhit()) 
		{  // 检查是否有按键输入,否则用户无法正常退出
			choice = getChoice(0);
				break;
		}
		t2 = recordTime();
		if (t2.hour >= 23) 
		{
			printf("                                  已到晚上十一点，上机自动结束。\n");
			break;
		}
		Sleep(1000);  // 每秒检查一次
	}

	while (!timeValid(t1, t2))
	{
		printf("                                  检测到时间异常，可能是本地时间被修改，请检查时间设置。\n");
		choice = getChoice(0);
		t2 = recordTime();
	}
	dur = useTime(t1, t2);
	
	if (stu->rNum == Recnum-1) // 记录已满，覆盖最早的记录
	{ 
		// 所有记录向前移动一位
		for (int j = 0; j < Recnum - 2; j++)
			stu->totalRecord[j] = stu->totalRecord[j + 1];
	}	
	stu->totalRecord[stu->rNum].starttime = t1;
	stu->totalRecord[stu->rNum].endtime = t2;
	recordIP(stu->totalRecord[stu->rNum].address);
	stu->totalRecord[stu->rNum].duration = dur;
	stu->totalRecord[stu->rNum].fee = sumFee(dur);
	stu->remain -= stu->totalRecord[stu->rNum].fee;
	
	printf("                                  感谢您的使用!\n");
	printf("                                  本次使用总时长为 :%d分钟\n", stu->totalRecord[stu->rNum].duration);
	printf("                                  花费 :%.2lf 元\n", stu->totalRecord[stu->rNum].fee);
	printf("                                  剩余余额：%.2lf 元\n", stu->remain);
	stu->rNum++;
	saveSFile(stu, 1);
}


//选择函数,返回 choice(非负)，不会调用上一级菜单
int getChoice(int max)
{
	int choice = 0;
	printf("                                  请输入你的选择 : ");
	while (scanf("%d", &choice) != 1 || choice < 0 || choice > max)
	{
		printf("                                  无效！请重新输入：\n");
		while (getchar() != '\n'); // 清除输入缓冲区
	}
	return choice;
}

// 主控模块，选择一级菜单功能执行
void runMain_1(Student* stu, Admini* adm, int choice,int *Sn)
{
	saveSFile(stu, *Sn);//保存
	switch (choice)
	{
	case 1:   //1.管理员登录
		adminiL(adm,stu,Sn);
		break;
	case 2:   //2.学生登录
		stuL(adm,stu,Sn);
		break;
	case 0:   //0.退出系统
		sortID(stu, *Sn);
		saveSFile(stu, *Sn);
		saveAFile(adm, Admnum);
		exit(0);
		break;
	}
}

//主控模块，选择二级菜单中管理员功能执行
void runMain_2adm(Admini* adm, Student* stu, int choice, int* Sn)
{
	int sum = 0;
	switch (choice)
	{
	case 1:  //1.学生信息管理
		stuInformManage(adm, stu,Sn);
		break;
	case 2:  //2.收入情况
		income(adm, stu, Sn);
		break;
	case 0:  //0.返回
		mainMenu();
		int choice = getChoice(3);
		runMain_1(stu, adm, choice, Sn);
		break;
	}
	saveAFile(adm, Admnum);
	saveSFile(stu, *Sn);
}

//主控模块，选择二级菜单中学生功能执行,参数为学生数组结构体地址
void runMain_2stu(Admini* adm, Student* stu, int choice, int* Sn, int position)
{
	char* nPW;
	switch (choice)
	{
	case 1:   //1.查询信息
		printStu(stu[position]);
		stuMenu();//显示学生功能菜单
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 2:   //2.充值
		recharge(&stu[position]);
		saveSFile(stu, *Sn);
		stuMenu();//显示学生功能菜单
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 3:   //3.修改密码
		nPW = changePW();
		if (nPW != NULL)
		{
			strcpy(stu[position].password, nPW);
			free(nPW);
		}
		saveSFile(stu, *Sn);
		stuMenu();//显示学生功能菜单
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 4:   //4.卡挂失
		lossCard(&stu[position]);
		saveSFile(stu, *Sn);
		stuMenu();//显示学生功能菜单
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 5:   //5.卡解挂
		cancelLost(&stu[position]);
		saveSFile(stu, *Sn);
		stuMenu();//显示学生功能菜单
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 6:    //消费--上机
		if (stu[position].remain < 20.0)
			printf("                                  余额不足，请充值！至少20元！\n");
		else
			useCom(&stu[position]);
		saveSFile(stu, *Sn);
		stuMenu();//显示学生功能菜单
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 0:   //0.返回
		mainMenu();
		choice = getChoice(3);
		runMain_1(stu, adm, choice, Sn);
		break;
	}
}


//主控模块，选择三级菜单管理员信息管理功能执行
void runMain_3adm(Admini*adm,Student * stu, int choice, int* Sn)
{
	switch (choice)
	{
	case 1:   //1.查询学生校园卡信息
		aSearInform(adm,stu,Sn);
		break;
	case 2:   //2.增加学生校园卡信息--即注册
		if (Stunum == *Sn)
		{
			printf("                                  满员!\n");
			stuInformManage(adm,stu, Sn);//返回
			sortID(stu, *Sn);//排序
			saveSFile(stu, *Sn);//保存
		}
		else//注册
		{
			*Sn=readStu(stu,Sn);
			printf("                                  添加成功!\n");
			sortID(stu, *Sn);//排序
			saveSFile(stu,*Sn);
			stuInformManage(adm,stu, Sn);//返回
		}
		break;
	case 3:   //3.删除学生校园卡信息
		*Sn=deleteCard(stu, Sn);
		saveSFile(stu, *Sn);
		stuInformManage(adm,stu, Sn);//返回
		break;
	case 4:   //4.修改学生校园卡信息
		changeStu(adm,stu, Sn);
		sortID(stu, *Sn);//排序
		saveSFile(stu, *Sn);
		stuInformManage(adm,stu, Sn);//返回
		break;
	case 0:   //0.返回
		adminMenu();//调用管理员二级菜单
		int choice = getChoice(2);
		runMain_2adm(adm,stu, choice, Sn);
		break;
	}
}

//主控模块，选择三级菜单管理员收入查询功能执行
void runMain_3adm2(Admini * adm,Student *stu,int choice,int *Sn)
{
	Date curDate = recordTime();//先获取当日时间
	int ch = 0;
	switch (choice)
	{
	case 1:   //1.日收入情况
		uDay(adm, stu, curDate, *Sn);
		dayIncome(adm,curDate);
		income(adm,stu,Sn);
		break;
	case 2:   //2.月收入情况
		uMon(adm,stu,curDate,*Sn);
		monIncome(adm, curDate.year,curDate.month );
		income(adm, stu, Sn);
		break;
	case 3:   //3.年收入情况
		uYear(adm, stu, curDate, *Sn);
		yearIncome(adm, curDate.year);
		income(adm, stu, Sn);
		break;
	case 0:   //0.返回
		adminMenu();//调用管理员二级菜单
		choice = getChoice(2);
		runMain_2adm(adm,stu, choice, Sn);
		break;
	}
	saveAFile(adm,Admnum);
}

//主控模块，选择四级菜单管理员功能执行
void runMain_4(Admini*adm,Student* stu, int choice,int *Sn)
{
	switch (choice)
	{
	case 1:   //1.学生个人基本信息
		searchStu(stu);
		aSearInform(adm,stu,Sn);
		break;
	case 2:   //2.全体学生基本信息
		stuHead();//打印表头
		printTStu(stu,*Sn);//打印全体学生信息
		aSearInform(adm,stu,Sn);
		break;
	case 0:   //0.返回学生信息管理选项
		stuInformManage(adm,stu,Sn);
		break;
	}
}

int main()
{
	Student stu[Stunum] = { 0 };//结构体数组，存储学生信息
	Admini adm[Admnum] = { 0 };//存储管理员信息
	int  Sn = 0, An = 0;//分别存储学生数和管理员数
	Sn = readSFile(stu);//读取文件然后存储学生数
	if (!Sn)//如果未存储学生信息文件
		Sn = createSFile(stu, &Sn);//从控制台获取数据，再获取学生数
	An = readAFile(adm);
	if (!An)
		createAFile(adm);
	sortID(stu, Sn);
	saveSFile(stu, Sn);
	saveAFile(adm, Admnum);
	int choice = 0;
	do
	{
		mainMenu();
		choice = getChoice(2);
		runMain_1(stu, adm, choice, &Sn);
	} while (choice);
	sortID(stu, Sn);
	saveSFile(stu, Sn);
	saveAFile(adm, Admnum);
	return 0;
}
