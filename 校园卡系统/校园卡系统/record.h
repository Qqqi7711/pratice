#ifndef _RECORD
#define _RECORD

typedef struct Date //����
{
	int year; //��
	int month; //��
	int day; //��
	int hour; //ʱ
	int minute; //��
}Date;
typedef struct Record //һ���ϻ���¼
{
	Date starttime; //��ʼʱ��
	Date endtime; //����ʱ��
	int duration;//�ϻ���ʱ��min)
	char address[20]; //�ϻ��ص�
	double fee; //�ϻ�����
}Record;

typedef struct sumRecord //ͳ���ϻ���¼(������)��������Ա�鿴��
{
	double Time; //��ʱ���ܽ�(hour)
	double Fee; //�շ����ܽ�(yuan)
}sumRecord;

Date recordTime();//��ȡ��ǰʱ�亯��
void recordIP(char *add);//��ȡ����IP��ַ,ʧ�ܷ���0,�ɹ�����1������IP����
int useTime(Date startTime, Date endTime);//���㱾���ϼ�ʱ��(��λ��minute)!������������һ��
double sumFee(int useTime);//���㱾���ϻ��������



#endif