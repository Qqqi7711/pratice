#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "file.h"
/*�������ܣ����ļ������ݶ�������������
  �����������β��ǽṹ��ָ��
  ��������ֵ�����ļ��ж�����ʵ�ʼ�¼����
  */
int readSFile(Student* stu)
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("D:\\student.txt", "r")) == NULL)//�Զ���ʽ��ָ���ļ�
	{
		printf("                                  ѧ���ļ������ڣ����ȴ����ļ�\n");//��ʧ�������ʾ��Ϣ
		return 0;//����ֵ0
	}
	while (fread(&stu[i], sizeStu, 1, fp) == 1) {
		i++;
	}
	fclose(fp);
	return i;//���ؼ�¼����,����ע��ѧ������
}

//������Ա�ļ�
int readAFile(Admini *adm)
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("D:\\administrator.txt", "r")) == NULL)//�Զ���ʽ��ָ���ļ�
	{
		printf("����Ա�ļ������ڣ����ȴ����ļ�\n");//��ʧ�������ʾ��Ϣ
		return 0;//����ֵ0
	}
	fread(&adm[i], sizeAdm, 1, fp);//������һ����¼
	while (!feof(fp))//�ļ�δ����ʱ��ѭ��
	{
		i++;
		fread(&adm[i], sizeAdm, 1, fp);//����һ����¼
	}
	fclose(fp);//�ر��ļ�
	return i;//���ؼ�¼������������Ա����
}
/*�������ܣ����ṹ����������д���ļ�
  ����������2���βηֱ��ǽṹ��ָ�롢ʵ�ʼ�¼����
  ��������ֵ���޷���ֵ
 */
void saveSFile(Student* stu, int Sn)
{
	FILE* fp;
	if ((fp = fopen("D:\\student.txt", "w")) == NULL)//��д��ʽ���ļ�
	{
		printf("                                  �ļ���ʧ��!\n");//��ʧ�������ʾ��Ϣ
		exit(0);//�˳�
	}
	fwrite(stu,sizeStu, Sn, fp);//һ�������ļ���д��n����¼
	fclose(fp);//�ر��ļ�
}

//�������Ա��Ϣ
void saveAFile(Admini *adm, int An)
{
	FILE* fp;
	if ((fp = fopen("D:\\administrator.txt", "w")) == NULL)//��д��ʽ���ļ�
	{
		printf("                                  �ļ���ʧ��!\n");//��ʧ�������ʾ��Ϣ
		exit(0);//�˳�
	}
	fwrite(adm, sizeAdm, Admnum, fp);//һ�������ļ���д��n����¼
	fclose(fp);//�ر��ļ�
}
/*�������ܣ�������ʼ�������ļ�
  �����������βηֱ�Ϊ�ṹ��ָ��
  ��������ֵ������д���ļ��ļ�¼��
 */

int createSFile(Student* stu,int *Sn)
{
	FILE* fp;
	if ((fp = fopen("D:\\student.txt","w")) == NULL)//��д��ʽ��ָ���ļ�
	{
		printf("                                  �ļ���ʧ��!\n");//��ʧ�������ʾ��Ϣ
		exit(0);//�˳�
	}
	printf("                                  ������ѧ����Ϣ:\n");
	int oldSn = *Sn;
	readStu(stu, Sn);
	fwrite(&stu[oldSn], sizeStu, *Sn - oldSn, fp);//������ļ�¼ȫд���ļ�
	fclose(fp);//�ر��ļ�
	printf("                                  �����ɹ�!\n");
	return *Sn;//���ؼ�¼����
}

//��������Ա���ļ�
void createAFile(Admini* adm)//nΪ����Ա����
{
	printf("                                  ��������Ա�ļ�\n");
	FILE* fp;
	if ((fp = fopen("D:\\administrator.txt", "w")) == NULL)//��д��ʽ��ָ���ļ�
	{
		printf("                                  ���ļ�ʧ��!\n");//��ʧ�������ʾ��Ϣ
		exit(0);//�˳�
	}
	readAdm(adm);
	fwrite(adm, sizeAdm, Admnum, fp);//������ļ�¼ȫд���ļ�
	printf("                                  �����ɹ�!\n");
	fclose(fp);//�ر��ļ�
}

