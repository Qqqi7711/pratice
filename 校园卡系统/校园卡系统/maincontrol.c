#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>//Ϊ��ʹ��getch����
#include <stdlib.h>
#include <string.h>
#include"maincontrol.h"
#include <windows.h>  // ���� Sleep ����



//�˳����溯��----exit(0);

//�������뺯��,����һ��pw����,�ǵ����Ҫ�ͷ� free
char* getPW()
{
	//�ö�̬����
	char* pw = (char*)malloc(Pwlength * sizeof(char));
	if (pw == NULL) {
		fprintf(stderr, "                                  �ڴ����ʧ��!\n");
		return NULL;
	}
	int i=0;
	char ch;
	while (i < Pwlength - 1)
	{
		ch = _getch();  // �޻��Զ�ȡ�ַ�
		if (ch == '\r' || ch == '\n')    // ����س�ȷ��
		{
			printf("\n");
			pw[i] = '\0';
			break;
		}
		else if (ch == '\b')    // �����˸�ɾ��
		{
			if (i > 0)
			{
				i--;
				printf("\b \b");  // ɾ��ǰһ���Ǻ�
			}
		}
		else       // �����ַ�����
		{
			pw[i++] = ch;
			printf("*");
		}
	}
	return pw;
}

//ѧ����¼����,���� position��,�ɹ�λ�ã�ʧ��-1
int stuLogin(Student* stu,int *Sn)
{
	int id;
	char* pw=NULL;
	while (1)
	{
		printf("                                  ID��");
		if (scanf("%d", &id) != 1)
		{
			printf("                                  ID������Ч��������������\n");
			while (getchar() != '\n'); // ������뻺����
			continue;
		}

		int position = IDCompare(stu, id, *Sn);
		if (position == -1)//�˺Ų�����
		{
			printf("                                  �˺��Ѳ�����!\n");
			continue;
		}
		if (stu[position].cardState == 3 || (0 == stu[position].count))//������
		{
			printf("                                  ���˺��ѱ����ᣬ����ϵ����Ա\n");
			return -1;
		}
		do
		{
			printf("                                  (��ʼ����: @123456)\n");
			printf("                                  ����:");
			pw = getPW();
			if (!pw)
			{
				printf("                                  ���ڴ����ʧ�ܣ���������ʧ��\n");
				continue;
			}
			if (PWCompare(stu[position].password, pw))
			{
				printf("                                  ��¼�ɹ�!\n");//��¼�ɹ�
				free(pw);
				stu[position].count = 3;//��¼�ɹ�������ָ�3��
				return position;
			}
			else
			{
				printf("                                  �������!\n");//�������
				stu[position].count--;//�������
				printf("                                  �㻹��%d�λ���!\n", stu[position].count);
			}
			free(pw);
		} while (stu[position].count > 0);
		stu[position].cardState = 3;
		printf("                                  ���˻��ѱ����ᣬ����ϵ����Ա!\n");
		return -1;
	}
}

//����Ա��¼����,�ɹ�����1�����󷵻�0
int admLogin(Admini *adm)
{
	char admId[20] = { 0 };
	char* admPw;
	printf("                                  ID:");
	scanf_s("%s", admId,20);
	if (0 == strcmp(admId, adm->admID))//�˺���ȷ
	{
		printf("                                  ���룺");
		admPw = getPW();
		if (0 == strcmp(admPw, adm->admPW))
		{
			printf("                                  ��¼�ɹ�!\n");
			return 1;
		}
		else
			printf("                                  �������!\n");
		return 0;
	}
	else
	{
		printf("                                  ID����!\n");
		return 0;
	}
}


//�޸����뺯��,ǰ�᣺ID�Ѿ�ƥ��ɹ�,����Ϊѧ������,�����µ�����
char* changePW()
{
	int isValid = 0;
	char *pw1=NULL, *pw2=NULL;
	do 
	{
		// �ͷ���һ��ѭ��������ڴ�
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
		printf("                                  ������:");
		pw1 = getPW();
		if (pw1 == NULL) {
			printf("                                  ���ڴ����ʧ�ܣ���������ʧ��\n");
			continue;
		}
		printf("\n");
		// �ٴ�ȷ������
		printf("                                  ȷ������:");
		pw2 = getPW();
		printf("\n");
		if (pw2 == NULL) {
			printf("                                  ���ڴ����ʧ�ܣ���������ʧ��\n");
			free(pw1);//�ͷ�pw1�����pw2��ȡ�ڴ�ʧ��
			pw1 = NULL;
			continue;
		}
		if (PWCompare(pw1, pw2))
			isValid = 1;
		else 
			printf("                                  ���벻ƥ�䣬���������룺\n");
	} while (!isValid);
	// �ͷ� pw1��ֻ���� pw2
	free(pw1);
	printf("                                  �޸ĳɹ���\n");
	return pw2;
}

//�޸�ѧ��У԰����Ϣ����,iΪѧ������λ��(��ַ��,�޸ĳɹ�����1��ѡ�񷵻ط���0
int changeCard(Student* stu, int choice)
{
	switch (choice)
	{
	case 1:
		printf("                                  �µ�ID�ţ�\n");
		scanf_s("%d", &(stu->ID));
		while (getchar() != '\n');//���������
		printf("                                  �޸ĳɹ���\n");
		saveSFile(stu, 1); // �����޸ĺ��ѧ����Ϣ
		break;
	case 2:
		printf("                                  �µ��û�����\n");
		scanf_s("%s", stu->name, 20);
		printf("                                  �޸ĳɹ���\n");
		saveSFile(stu, 1); // �����޸ĺ��ѧ����Ϣ
		break;
	case 3:
		recharge(stu);
		saveSFile(stu, 1); // �����޸ĺ��ѧ����Ϣ
		break;
	case 4:
		printf("                                  �µĿ�״̬��1--���� 2--��ʧ 3--���ᣩ��\n");
		int state = 0;
		scanf_s("%d", &state);
		while (state < 1 || state>3)
		{
			printf("                                  ��������\n");
			printf("                                  ���������룡\n");
			scanf_s("%d", &state);
		}
		(stu->cardState) = state;
		if (state == 1)
			stu->count = 3;
		else if (state == 3)
			stu->count = 0;
		printf("                                  �޸ĳɹ���\n");
		saveSFile(stu, 1); // �����޸ĺ��ѧ����Ϣ
		break;
	case 0:
		return 0;
		break;
	}
	return 1;
}

//��ֵ����
void recharge(Student* stu)
{
	int money = 0;
	printf("                                  ��ֵ���(Ԫ)(��Ǯ)��");
	while (scanf("%d", &money) != 1 || money <= 0)
	{
		printf("                                  ��Ч��ֵ�������³�ֵ!\n");
		printf("                                  ��ֵ���(Ԫ)(��Ǯ)��");
		while (getchar() != '\n'); // ������뻺����
	}
	stu->remain += money;
	printf("                                  �ɹ�����%dԪ��\n", money);
	while (getchar() != '\n'); // ������뻺����
	saveSFile(stu, 1);
}

//����Ա��¼ѡ��
void adminiL(Admini *adm,Student *stu,int *Sn)
{
	if (admLogin(adm))//����Ա��¼�ɹ�
	{
		adminMenu();//���ù���Ա�����˵�
		int choice=getChoice(2);
		runMain_2adm(adm,stu,choice,Sn);
	}
}

//ѧ����¼ѡ��,�ɹ�����1��ʧ�ܷ���0
void stuL(Admini* adm, Student* stu, int* Sn)
{
	int position = stuLogin(stu, Sn);
	if (position == -1) // ��¼ʧ��
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
		runMain_2stu(adm, stu, choice, Sn, position); // stu ������ָ��
	}
}

//����Ա��ѯ��Ϣѡ����
void aSearInform(Admini * adm,Student* stu,int *Sn)
{
	admSearMenu();
	int choice  = getChoice(2);
	runMain_4(adm,stu, choice,Sn);
}

//����Աѧ����Ϣ����ѡ����
void stuInformManage(Admini*adm,Student* stu, int *Sn)
{
	stuInformMenu();
	int choice = getChoice(4);
	runMain_3adm(adm,stu, choice, Sn);
}

//�޸�ѧ����Ϣѡ��
void  changeStu(Admini* adm, Student* stu, int* Sn)
{
	int id = 0;
	printf("                                  ������Ҫ�޸ĵ�ID: ");
	scanf_s("%d", &id);
	int position = IDCompare(stu, id, *Sn);
	if (-1 != position)//�ҵ�
	{
		changeCardMenu();//��ʾ�˵�
		int choice = getChoice(4);
		if (changeCard(&stu[position], choice))
		{
			sortID(stu, *Sn);//����
			saveSFile(stu, *Sn);//����
		}
		else
			stuInformManage(adm, stu, Sn);
	}
	else
		printf("                                  �ÿ������ڣ�\n");
}



//�������ѡ��
void income(Admini* adm,Student *stu,int *Sn)
{
	totalFee();
	int choice = getChoice(3);
	runMain_3adm2( adm,stu,choice,Sn);
}

//������ѡ��
void dayIncome(Admini *adm,Date curDate)
{
	printf("%d/%d  �������\n ", curDate.month, curDate.year);
	printf("%-5s%-14s  %-12s", "���ڣ��գ� ", "��ʱ�䣨Сʱ��", "�ܷ��ã�Ԫ��");
	printf("\n");
	for (int i = 0; i < curDate.day; i++)
	{
		printf("   %-02d         %-04.2lf             %-04.2lf", i +1, adm->daySum[i].Time, adm->daySum[i].Fee);
		printf("\n");
	}
}

//���������
void monIncome(Admini* adm,int year,int month)
{
	printf(" %d  �������\n ", year);
	printf("%-5s%-14s  %-12s", "���ڣ��£� ", "��ʱ�䣨Сʱ��", "�ܷ��ã�Ԫ��");
	printf("\n");
	for (int i = 0; i < month; i++)
	{
		printf("   %-02d        %-04.2lf            %-04.2lf", i + 1, adm->monSum[i].Time, adm->monSum[i].Fee);
		printf("\n");
	}
}

//�������������
void yearIncome(Admini* adm,int year)
{
	printf("%-5s%-14s  %-12s", "���ڣ��꣩ ", "��ʱ�䣨Сʱ)", "�ܷ��ã�Ԫ��");
	printf("\n");
	for (int i = 0; i <5 ; i++)
	{
		printf(" %-04d       %-04.2lf             %-04.2lf", year-i, adm->yearSum[i].Time, adm->yearSum[i].Fee);
		printf("\n");
	}
}

//����ʱ��
int timeValid(Date start, Date end)
{
	int dur=useTime(start, end);
	if (dur < 0)
		return 0;
	else if (start.day != end.day|| start.month != end.month||start.year !=end.year )
		return 0;
	return 1;
}

//�ϻ�ѡ��
void useCom(Student* stu) 
{
	Date t1 = recordTime();
	if (t1.hour > 22 ||t1.hour < 7)
	{ // 7 �㵽 23 �������ֹ����
		printf("                                  �����ߵ㵽����ʮһ���ֹ��������ú���Ϣ//^o^//!\n");
		return;
	}
	printf("                                  ��ʼ�ϻ������ڿ�ʼ��ʱ...��\n");
	printf("                                  ��ע�����Ϊ 0.01(Ԫ)/����!\n");
	printf("                                  ���ʹ��ʱ��С��1���ӽ����շ�,�Ҳ������ϻ���¼�С�\n");
	printf("                                  �ڴ�����һ������ʹ������//^o^//\n");
	printf("                                  �밴 '0' �Խ����ϻ�!\n");
	Date t2;
	int dur;
	int choice = 0;
	// ѭ������Ƿ�ﵽ 23 ������û���������
	while (1) 
	{
		if (_kbhit()) 
		{  // ����Ƿ��а�������,�����û��޷������˳�
			choice = getChoice(0);
				break;
		}
		t2 = recordTime();
		if (t2.hour >= 23) 
		{
			printf("                                  �ѵ�����ʮһ�㣬�ϻ��Զ�������\n");
			break;
		}
		Sleep(1000);  // ÿ����һ��
	}

	while (!timeValid(t1, t2))
	{
		printf("                                  ��⵽ʱ���쳣�������Ǳ���ʱ�䱻�޸ģ�����ʱ�����á�\n");
		choice = getChoice(0);
		t2 = recordTime();
	}
	dur = useTime(t1, t2);
	
	if (stu->rNum == Recnum-1) // ��¼��������������ļ�¼
	{ 
		// ���м�¼��ǰ�ƶ�һλ
		for (int j = 0; j < Recnum - 2; j++)
			stu->totalRecord[j] = stu->totalRecord[j + 1];
	}	
	stu->totalRecord[stu->rNum].starttime = t1;
	stu->totalRecord[stu->rNum].endtime = t2;
	recordIP(stu->totalRecord[stu->rNum].address);
	stu->totalRecord[stu->rNum].duration = dur;
	stu->totalRecord[stu->rNum].fee = sumFee(dur);
	stu->remain -= stu->totalRecord[stu->rNum].fee;
	
	printf("                                  ��л����ʹ��!\n");
	printf("                                  ����ʹ����ʱ��Ϊ :%d����\n", stu->totalRecord[stu->rNum].duration);
	printf("                                  ���� :%.2lf Ԫ\n", stu->totalRecord[stu->rNum].fee);
	printf("                                  ʣ����%.2lf Ԫ\n", stu->remain);
	stu->rNum++;
	saveSFile(stu, 1);
}


//ѡ����,���� choice(�Ǹ�)�����������һ���˵�
int getChoice(int max)
{
	int choice = 0;
	printf("                                  ���������ѡ�� : ");
	while (scanf("%d", &choice) != 1 || choice < 0 || choice > max)
	{
		printf("                                  ��Ч�����������룺\n");
		while (getchar() != '\n'); // ������뻺����
	}
	return choice;
}

// ����ģ�飬ѡ��һ���˵�����ִ��
void runMain_1(Student* stu, Admini* adm, int choice,int *Sn)
{
	saveSFile(stu, *Sn);//����
	switch (choice)
	{
	case 1:   //1.����Ա��¼
		adminiL(adm,stu,Sn);
		break;
	case 2:   //2.ѧ����¼
		stuL(adm,stu,Sn);
		break;
	case 0:   //0.�˳�ϵͳ
		sortID(stu, *Sn);
		saveSFile(stu, *Sn);
		saveAFile(adm, Admnum);
		exit(0);
		break;
	}
}

//����ģ�飬ѡ������˵��й���Ա����ִ��
void runMain_2adm(Admini* adm, Student* stu, int choice, int* Sn)
{
	int sum = 0;
	switch (choice)
	{
	case 1:  //1.ѧ����Ϣ����
		stuInformManage(adm, stu,Sn);
		break;
	case 2:  //2.�������
		income(adm, stu, Sn);
		break;
	case 0:  //0.����
		mainMenu();
		int choice = getChoice(3);
		runMain_1(stu, adm, choice, Sn);
		break;
	}
	saveAFile(adm, Admnum);
	saveSFile(stu, *Sn);
}

//����ģ�飬ѡ������˵���ѧ������ִ��,����Ϊѧ������ṹ���ַ
void runMain_2stu(Admini* adm, Student* stu, int choice, int* Sn, int position)
{
	char* nPW;
	switch (choice)
	{
	case 1:   //1.��ѯ��Ϣ
		printStu(stu[position]);
		stuMenu();//��ʾѧ�����ܲ˵�
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 2:   //2.��ֵ
		recharge(&stu[position]);
		saveSFile(stu, *Sn);
		stuMenu();//��ʾѧ�����ܲ˵�
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 3:   //3.�޸�����
		nPW = changePW();
		if (nPW != NULL)
		{
			strcpy(stu[position].password, nPW);
			free(nPW);
		}
		saveSFile(stu, *Sn);
		stuMenu();//��ʾѧ�����ܲ˵�
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 4:   //4.����ʧ
		lossCard(&stu[position]);
		saveSFile(stu, *Sn);
		stuMenu();//��ʾѧ�����ܲ˵�
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 5:   //5.�����
		cancelLost(&stu[position]);
		saveSFile(stu, *Sn);
		stuMenu();//��ʾѧ�����ܲ˵�
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 6:    //����--�ϻ�
		if (stu[position].remain < 20.0)
			printf("                                  ���㣬���ֵ������20Ԫ��\n");
		else
			useCom(&stu[position]);
		saveSFile(stu, *Sn);
		stuMenu();//��ʾѧ�����ܲ˵�
		choice = getChoice(6);
		runMain_2stu(adm, stu, choice, Sn, position);
		break;
	case 0:   //0.����
		mainMenu();
		choice = getChoice(3);
		runMain_1(stu, adm, choice, Sn);
		break;
	}
}


//����ģ�飬ѡ�������˵�����Ա��Ϣ������ִ��
void runMain_3adm(Admini*adm,Student * stu, int choice, int* Sn)
{
	switch (choice)
	{
	case 1:   //1.��ѯѧ��У԰����Ϣ
		aSearInform(adm,stu,Sn);
		break;
	case 2:   //2.����ѧ��У԰����Ϣ--��ע��
		if (Stunum == *Sn)
		{
			printf("                                  ��Ա!\n");
			stuInformManage(adm,stu, Sn);//����
			sortID(stu, *Sn);//����
			saveSFile(stu, *Sn);//����
		}
		else//ע��
		{
			*Sn=readStu(stu,Sn);
			printf("                                  ��ӳɹ�!\n");
			sortID(stu, *Sn);//����
			saveSFile(stu,*Sn);
			stuInformManage(adm,stu, Sn);//����
		}
		break;
	case 3:   //3.ɾ��ѧ��У԰����Ϣ
		*Sn=deleteCard(stu, Sn);
		saveSFile(stu, *Sn);
		stuInformManage(adm,stu, Sn);//����
		break;
	case 4:   //4.�޸�ѧ��У԰����Ϣ
		changeStu(adm,stu, Sn);
		sortID(stu, *Sn);//����
		saveSFile(stu, *Sn);
		stuInformManage(adm,stu, Sn);//����
		break;
	case 0:   //0.����
		adminMenu();//���ù���Ա�����˵�
		int choice = getChoice(2);
		runMain_2adm(adm,stu, choice, Sn);
		break;
	}
}

//����ģ�飬ѡ�������˵�����Ա�����ѯ����ִ��
void runMain_3adm2(Admini * adm,Student *stu,int choice,int *Sn)
{
	Date curDate = recordTime();//�Ȼ�ȡ����ʱ��
	int ch = 0;
	switch (choice)
	{
	case 1:   //1.���������
		uDay(adm, stu, curDate, *Sn);
		dayIncome(adm,curDate);
		income(adm,stu,Sn);
		break;
	case 2:   //2.���������
		uMon(adm,stu,curDate,*Sn);
		monIncome(adm, curDate.year,curDate.month );
		income(adm, stu, Sn);
		break;
	case 3:   //3.���������
		uYear(adm, stu, curDate, *Sn);
		yearIncome(adm, curDate.year);
		income(adm, stu, Sn);
		break;
	case 0:   //0.����
		adminMenu();//���ù���Ա�����˵�
		choice = getChoice(2);
		runMain_2adm(adm,stu, choice, Sn);
		break;
	}
	saveAFile(adm,Admnum);
}

//����ģ�飬ѡ���ļ��˵�����Ա����ִ��
void runMain_4(Admini*adm,Student* stu, int choice,int *Sn)
{
	switch (choice)
	{
	case 1:   //1.ѧ�����˻�����Ϣ
		searchStu(stu);
		aSearInform(adm,stu,Sn);
		break;
	case 2:   //2.ȫ��ѧ��������Ϣ
		stuHead();//��ӡ��ͷ
		printTStu(stu,*Sn);//��ӡȫ��ѧ����Ϣ
		aSearInform(adm,stu,Sn);
		break;
	case 0:   //0.����ѧ����Ϣ����ѡ��
		stuInformManage(adm,stu,Sn);
		break;
	}
}

int main()
{
	Student stu[Stunum] = { 0 };//�ṹ�����飬�洢ѧ����Ϣ
	Admini adm[Admnum] = { 0 };//�洢����Ա��Ϣ
	int  Sn = 0, An = 0;//�ֱ�洢ѧ�����͹���Ա��
	Sn = readSFile(stu);//��ȡ�ļ�Ȼ��洢ѧ����
	if (!Sn)//���δ�洢ѧ����Ϣ�ļ�
		Sn = createSFile(stu, &Sn);//�ӿ���̨��ȡ���ݣ��ٻ�ȡѧ����
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
