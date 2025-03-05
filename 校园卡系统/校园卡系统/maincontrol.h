#ifndef _MAINCONTROL
#define _MAINCONTROL
#include "record.h"
#include "file.h"
#include "menu.h"

char* getPW();//�������뺯��,����һ��pw�ַ���,�ǵ����Ҫ�ͷ� free

int stuLogin(Student* stu, int* Sn);//ѧ����¼����,�ɹ�����1��ʧ�ܷ���0
int admLogin(Admini* adm);//����Ա��¼����,�ɹ�����1�����󷵻�0
char* changePW();//�޸����뺯��,ǰ�᣺ID�Ѿ�ƥ��ɹ�,����Ϊѧ������,�����µ�����
int changeCard(Student* stu, int choice);//�޸�ѧ��У԰����Ϣ����,iΪѧ������λ��(��ַ��
void recharge(Student* stu);//��ֵ����
void useCom(Student* stu);//ѡ���ϻ�ѡ��

int timeValid(Date start, Date end);//����ʱ��

void adminiL(Admini* adm, Student* stu, int* Sn);//����Ա��¼ѡ��
void stuL(Admini* adm, Student* stu, int* Sn);//ѧ����¼ѡ��
void aSearInform(Admini* adm, Student* stu, int* Sn);//����Ա��ѯ��Ϣѡ����

int getChoice(int max); // ѡ����, ���� choice(�Ǹ�)�����������һ���˵�

void runMain_1(Student* stu, Admini* adm, int choice, int* Sn);// ����ģ�飬ѡ��һ���˵�����ִ��
void runMain_2adm(Admini* adm, Student* stu, int choice, int* Sn);//����ģ�飬�����˵�(����Ա)
void runMain_2stu(Admini* adm, Student* stu, int choice, int* Sn, int position);//����ģ�飬�����˵�(ѧ��),����Ϊѧ������ṹ���ַ
void runMain_3adm(Admini* adm, Student* stu, int choice, int* Sn);//����ģ�飬ѡ�������˵�����Ա����ִ��
void runMain_3adm2(Admini* adm, Student* stu, int choice, int* Sn);//����ģ�飬ѡ�������˵�����Ա�����ѯ����ִ��
void runMain_4(Admini* adm, Student* stu, int choice, int* Sn);//����ģ�飬ѡ���ļ��˵�����Ա����ִ��

#endif 
