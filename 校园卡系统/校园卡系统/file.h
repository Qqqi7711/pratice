#ifndef _FILE
#define _FILE
#include"information.h"

int readSFile(Student* stu); //���ļ������ݶ������ڽṹ������stu��
void saveSFile(Student* stu,int Sn); //���ṹ�����������д���ļ�
int createSFile(Student *stu,int *Sn); //������ʼ�������ļ�

int readAFile(Admini* adm);//������Ա�ļ�
void saveAFile(Admini* adm, int An);//�������Ա��Ϣ
void createAFile(Admini* adm);//nΪ����Ա����,��������Ա���ļ�

#endif // !_FILE
