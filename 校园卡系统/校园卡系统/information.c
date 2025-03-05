#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include "information.h"

//��������ѧ������,��������ǰ�����ڵ��ϻ���ʱ��(hour),�����ã�������adm��
void uDay(Admini* adm, Student* stu, Date date, int Sn) {
	// �Ƚ�ÿ�����ʱ���ͷ�������
	for (int k = 0; k < date.day; k++) {
		adm->daySum[k].Time = 0;
		adm->daySum[k].Fee = 0;
	}

	// ����ѧ������
	for (int i = 0; i < Sn; i++) {
		// ������ѧ����¼����
		for (int j = 0; j < stu[i].rNum; j++) {
			if (date.year == stu[i].totalRecord[j].starttime.year &&
				date.month == stu[i].totalRecord[j].starttime.month &&
				date.day >= stu[i].totalRecord[j].starttime.day) {
				// ȷ�����ڲ�������ǰ����
				if (stu[i].totalRecord[j].starttime.day <= date.day) {
					adm->daySum[stu[i].totalRecord[j].starttime.day - 1].Time += (stu[i].totalRecord[j].duration / 60.0);
				}
			}
		}
	}

	// ���м�¼ʱ���ۼ���ɺ�ͳһ����ÿ��ķ���
	for (int k = 0; k < date.day; k++) {
		adm->daySum[k].Fee = adm->daySum[k].Time * 0.6;
	}
}


void uMon(Admini* adm, Student* stu, Date date, int Sn) 
{
	// �Ƚ����µ���ʱ���ͷ�������
	adm->monSum[date.month - 1].Time = 0;
	adm->monSum[date.month - 1].Fee = 0;

	for (int i = 0; i < Sn; i++) // ����ѧ������
	{ 
		for (int j = 0; j < stu[i].rNum; j++)// ������ѧ����¼����
		{ 
			if (date.year == stu[i].totalRecord[j].starttime.year &&
				date.month == stu[i].totalRecord[j].starttime.month) // �ۼӱ��µ���ʱ��
				adm->monSum[date.month - 1].Time += (stu[i].totalRecord[j].duration / 60.0);
		}
	}
	adm->monSum[date.month - 1].Fee = adm->monSum[date.month - 1].Time * 0.6;// ���㱾�µķ���
}

// �����������ϻ�ʱ�������
void uYear(Admini* adm, Student* stu, Date curDate, int Sn) 
{
	for (int i = 0; i < 5; i++) // �ȳ�ʼ���������ͳ������
	{
		adm->yearSum[i].Time = 0;
		adm->yearSum[i].Fee = 0;
	}
	// ����ÿ��ѧ��
	for (int i = 0; i < Sn; i++) {
		// ������ѧ����ÿ����¼
		for (int j = 0; j < stu[i].rNum; j++) {
			int recordYear = stu[i].totalRecord[j].starttime.year;
			if ((recordYear >= (curDate.year -4)) && recordYear <= curDate.year) // �ۼӸ���ݵ��ϻ�ʱ��
				adm->yearSum[curDate.year - recordYear].Time += stu[i].totalRecord[j].duration / 60.0;
		}
	}
	for (int i = 0; i < 5; i++) // ���������ÿ����ܷ���
		adm->yearSum[i].Fee = adm->yearSum[i].Time * 0.6;
}


//ѧ��ƥ�亯��,ƥ��ɹ�����i(ѧ������λ�ã���ʧ�ܷ���-1
int IDCompare(Student* stu, int id, int Sn) {
	for (int i = 0; i < Sn; i++) {
		if (stu[i].ID == id&&id!=0) 
		{
			return i; // ����ѧ��λ��
		}
	}
	return -1; // δ�ҵ�
}

//����ƥ�亯�����ɹ�����1��ʧ�ܷ���0
int PWCompare(char password[], char* pw)
{
	return (0 == strcmp(password, pw));
}

//��״̬��ʾ����
const char* getCS(int cardSate)
{
	switch (cardSate)
	{
	case 1:
		return "����";
	case 2:
		return "��ʧ";
	case 3:
		return "����";
	default:
		return "����";
    }
}

//��ͷ��������ӡ��ͷ,ѧ����Ϣ
void stuHead()
{
	printf("%-8s%-10s%-10s%-10s%-15s", "ID", "����", "���", "״̬","����");
	printf("\n");
}

//��ӡȫ��ѧ����Ϣ
void printTStu(Student *stu,int Sn)
{
	for (int i=0; i < Sn; i++)
	{
		printf("%-8d%-10s%-10.2lf", stu[i].ID , stu[i].name,stu[i].remain);
		printf("%-10s%-15s", getCS(stu[i].cardState ), stu[i].password);
		printf("\n");
	}
}

//�ϻ���¼��Ϣ�ı�ͷ
void recHead()
{
	printf(" %-15s   %-15s %-15s   %-15s    %-15s", "��ʼʱ��", "����ʱ��", "�ϻ�ʱ�䣨���ӣ�", 
		   
		"�ص�", "���ã�Ԫ��");
}

//��ѧ��������,ѡ�񽻻���,nΪ����ѧ������
void sortID(Student* stu, int n)
{
	int i, j, m;//m���汾����СԪ���±�
	Student temp;
	for (i = 0; i < n - 1; i++)//ѭ��n-1��
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

//ͨ��ID������ѧ��У԰��������Ϣ����
void  searchStu(Student* stu)
{
	int i,  findID;
	printf("                                  �������������ID\n");
	scanf_s("%d", &findID);
	i = IDCompare(stu, findID,Stunum);
	if ( i != -1)  //�ж�У԰���Ƿ����
	{
		stuHead();//��ӡ��ͷ
		printf("%-8d%-10s%-10.2f", stu[i].ID, stu[i].name, stu[i].remain);
		printf("%-10s%-15s",getCS(stu[i].cardState), stu[i].password);
	}//�������ӡ
	else
	{
		printf("                                  ��ѧ����������!\n");
	}//�����ڸ�����ʾ
}

//��ӡʱ�亯��,�����Զ�ת��
void printTime(Date date)
{
	printf("%d/%d/%d %02d:%02d  ",date.day,date.month ,date.year ,date.hour ,date.minute );
}

//��ӡĳ��ѧ��������Ϣ
void printStu(Student stu)
{
	printf("%-8s%-10s%-8s%-8s\n", "ID", "����", "���", "״̬");
	printf("%-8d%-10s%-8.2lf", stu.ID ,stu.name ,stu.remain );
	printf("%-8s", getCS(stu.cardState));
	printf("\n\n");
	recHead();
	printf("\n");
	if (stu.rNum == 0)
	{
		printf("�����ϻ���¼��\n");
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

//ɾ��ѧ��У԰����Ϣ����,��������ѧ������,nΪѧ������
int deleteCard(Student* stu, int *Sn)  
{
	int  findID=0,choice=0;
	Student s = { 0 };
	do
	{
		printf("                                  ����������ɾ��ID: ");
		scanf_s("%d", &findID);
		int position = IDCompare(stu, findID, *Sn);
		if (-1 == position)
		{
			printf("                                  ��У԰��������!\n");
		}
		else
		{
			for (int i = position; i < ((*Sn) - 1); i++)
				stu[i] = stu[i + 1];    //����λ������������ǰ����
			stu[(*Sn) - 1] = s;
			--(*Sn);   //��¼ѧ�������ļ���
			printf("                                  ��Ƭɾ���ɹ�!\n");
		}
		printf("                                  �Ƿ����ɾ��?\n(YES--1 NO--0)\n");
		do 
		{
			if (scanf("%d", &choice) != 1)
			{
				printf("                                  ��Ч���룬������������\n");
				while (getchar() != '\n'); // ������뻺����
			}
		} while (choice<0||choice>1);
	} while (choice);
	return *Sn;    //��������ѧ������
}




//�����Һ���������Ϊ��Ҫ��ʧ��ѧ���ṹ��
void lossCard(Student *stu)
{
	if (stu->cardState == 2)//���鿨Ƭ״̬�Ƿ��ѹ�ʧ
	{
		printf("                                  ��Ƭ%d�ѹ�ʧ!\n", stu->ID);//���ѹ�ʧ������β���
		printf("                                  ������β���!\n");
	}
	else//��δ��ʧ
	{
		stu->cardState = 2;//������ʧ
		printf("                                  ��Ƭ%d��ʧ�ɹ���", stu->ID);
	}
	
}

//��Һ���
void cancelLost(Student *stu)
{
	if (stu->cardState == 1)//����
	{
		printf("                                  ��Ƭ%d״̬����\n", stu->ID);//������
	}
	else if (stu->cardState == 2)//��ʧ
	{
		stu->cardState = 1;
		printf("                                  ��Ƭ%d��ҳɹ���\n", stu->ID);
	}
	else//����
		printf("                                  ��Ƭ%d�Ѷ��ᣡ\n", stu->ID);
}

// �Ӽ��̻��ѧ����ʼ����(����ԱȨ��,��ѧ��������ַ
int readStu(Student* stu, int* Sn)
{
	int n;
	int id = 0;
	printf("                                  ������ѧ������:(1-%d) ", Stunum-*Sn);
	while (scanf("%d", &n) != 1 || n < 1 || (*Sn + n) > Stunum)
	{
		printf("                                  ��Ч�������������������\n");
		printf("                                  ���ٴ�����: ");
		while (getchar() != '\n'); // ������뻺����
	}
	for (int i = *Sn; i < *Sn + n; i++)
	{
		printf("                                  ����ѧ����Ϣ\n");
		printf("                                  ID: ");
		while (scanf("%d", &id) != 1 || id < 0|| id ==0)
		{
			printf("                                  ID������Ч������������\n");
			while (getchar() != '\n'); // ������뻺����
			printf("                                  ID: "); // ������ʾ���� ID
		}
		if (IDCompare(stu, id, *Sn+i) != -1)
		{
			printf("                                  ��ID�Ѵ���!\n");
			i--; // ��������
			while (getchar() != '\n'); // ������뻺����
			continue;
		}
		stu[i].ID = id;
		printf("                                  ����: ");
		scanf_s("%s", stu[i].name,20);
		strcpy(stu[i].password, "@123456"); // ��ʼ����
		stu[i].remain = 0;
		stu[i].cardState = 1; // ����
		stu[i].count = 3; // ��������������
		stu[i].rNum = 0;//�ϻ���¼Ϊ0
		Record rec = { 0 };
		for (int j = 0; j < Recnum; j++)
			stu[i].totalRecord[j] = rec;
	}
	*Sn += n; // ����ѧ������
	sortID(stu, *Sn);//����
	return *Sn; // ����ѧ������
}

//������Ա��Ϣ
void readAdm(Admini *adm)
{
	sumRecord sr = { 0 };
	Admini adm_0 = { "A123","A@3366",sr,sr,sr };//���������ݳ�ʼ��Ϊ0���������
	*adm = adm_0;
}
