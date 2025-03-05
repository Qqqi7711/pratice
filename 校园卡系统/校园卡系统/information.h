#ifndef _STUDENT
#define _STUDENT
#include "record.h"

#define Recnum 20//�ϻ�����
#define Stunum 20//ѧ������
#define Pwlength 20//���볤��
#define Admnum 1//����Ա����
#define sizeStu sizeof(Student)//һ��ѧ����¼����Ҫ�Ŀռ��С
#define sizeAdm sizeof(Admini)//һ������Ա��¼����Ŀռ��С

typedef struct Student   /*ѧ���ṹ��*/
{
	int ID;//����
	char name[20];//����
	double remain;//���
	int cardState;//��״̬ 1--���� 2--��ʧ 3--����
	char password[Pwlength];//��ʼ����@123456
	Record totalRecord[Recnum];//���ϻ���¼��ֻ��20��
	int rNum;//��һ���ϻ���¼Ҫ����������е�λ��
	int count;//����������
}Student;

typedef struct Administrator
{
	char admID[20];
	char admPW[Pwlength];
	sumRecord daySum[31];//��������ѧ���ռ�¼,ֻ��¼��һ��
	sumRecord monSum[12];//��������ѧ���¼�¼��ֻ��¼��һ��
	sumRecord yearSum[5];//�洢����ѧ�����¼,ֻ��¼������
}Admini;


void uDay(Admini* adm, Student* stu, Date date, int Sn);//��������ѧ������,��������ǰ�����ڵ��ϻ���ʱ��(hour),�����ã�������adm��
void uMon(Admini* adm, Student* stu, Date date, int Sn);// ���㱾��ÿ�µ��ϻ�ʱ�������
void uYear(Admini* adm, Student* stu, Date curDate, int Sn);// �����������ϻ�ʱ�������

int IDCompare(Student* stu, int id, int Sn);//ѧ��ƥ�亯��,ƥ��ɹ�����i(ѧ������λ�ã���ʧ�ܷ���-1
int PWCompare(char password[], char* pw);//����ƥ�亯�����ɹ�����1��ʧ�ܷ���0

void sortID(Student* stu, int n);//��ѧ��������,ѡ�񽻻���,nΪ����ѧ������
void searchStu(Student* stu);//ͨ��ID������ѧ��У԰��������Ϣ����

const char* getCS(int cardSate);//��״̬��ʾ����
void stuHead();//��ͷ��������ӡ��ͷ,ѧ����Ϣ
void recHead();//�ϻ���¼��Ϣ�ı�ͷ
void printTime(Date date);//��ӡʱ�亯��,�����Զ�ת��
void printTStu(Student* stu, int Sn);//��ӡȫ��ѧ����Ϣ
void printStu(Student stu);//��ӡĳ��ѧ��������Ϣ

int deleteCard(Student* stu, int *Sn);//ɾ��ѧ��У԰����Ϣ����,��������ѧ������,nΪѧ������



void lossCard(Student *stu);//�����Һ���������Ϊ��Ҫ��ʧ��ѧ���ṹ��
void cancelLost(Student *stu);//��Һ���

int readStu(Student* stu,int *Sn);//�Ӽ��̻��ѧ����ʼ����(����ԱȨ��
void readAdm(Admini* adm);//������Ա��Ϣ

#endif
