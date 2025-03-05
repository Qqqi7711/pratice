#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "file.h"
/*函数功能：将文件中内容读出置与数组中
  函数参数：形参是结构体指针
  函数返回值：从文件中读出的实际记录条数
  */
int readSFile(Student* stu)
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("D:\\student.txt", "r")) == NULL)//以读方式打开指定文件
	{
		printf("                                  学生文件不存在，请先创建文件\n");//打开失败输出提示信息
		return 0;//返回值0
	}
	while (fread(&stu[i], sizeStu, 1, fp) == 1) {
		i++;
	}
	fclose(fp);
	return i;//返回记录条数,即已注册学生人数
}

//读管理员文件
int readAFile(Admini *adm)
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("D:\\administrator.txt", "r")) == NULL)//以读方式打开指定文件
	{
		printf("管理员文件不存在，请先创建文件\n");//打开失败输出提示信息
		return 0;//返回值0
	}
	fread(&adm[i], sizeAdm, 1, fp);//读出第一条记录
	while (!feof(fp))//文件未结束时的循环
	{
		i++;
		fread(&adm[i], sizeAdm, 1, fp);//读下一条记录
	}
	fclose(fp);//关闭文件
	return i;//返回记录条数，即管理员人数
}
/*函数功能：将结构体数组内容写入文件
  函数参数：2个形参分别是结构体指针、实际记录条数
  函数返回值：无返回值
 */
void saveSFile(Student* stu, int Sn)
{
	FILE* fp;
	if ((fp = fopen("D:\\student.txt", "w")) == NULL)//以写方式打开文件
	{
		printf("                                  文件打开失败!\n");//打开失败输出提示信息
		exit(0);//退出
	}
	fwrite(stu,sizeStu, Sn, fp);//一次性向文件中写入n条记录
	fclose(fp);//关闭文件
}

//保存管理员信息
void saveAFile(Admini *adm, int An)
{
	FILE* fp;
	if ((fp = fopen("D:\\administrator.txt", "w")) == NULL)//以写方式打开文件
	{
		printf("                                  文件打开失败!\n");//打开失败输出提示信息
		exit(0);//退出
	}
	fwrite(adm, sizeAdm, Admnum, fp);//一次性向文件中写入n条记录
	fclose(fp);//关闭文件
}
/*函数功能：建立初始的数据文件
  函数参数：形参分别为结构体指针
  函数返回值：返回写入文件的记录数
 */

int createSFile(Student* stu,int *Sn)
{
	FILE* fp;
	if ((fp = fopen("D:\\student.txt","w")) == NULL)//以写方式打开指定文件
	{
		printf("                                  文件打开失败!\n");//打开失败输出提示信息
		exit(0);//退出
	}
	printf("                                  请输入学生信息:\n");
	int oldSn = *Sn;
	readStu(stu, Sn);
	fwrite(&stu[oldSn], sizeStu, *Sn - oldSn, fp);//将读入的记录全写入文件
	fclose(fp);//关闭文件
	printf("                                  创建成功!\n");
	return *Sn;//返回记录条数
}

//创建管理员的文件
void createAFile(Admini* adm)//n为管理员人数
{
	printf("                                  创建管理员文件\n");
	FILE* fp;
	if ((fp = fopen("D:\\administrator.txt", "w")) == NULL)//以写方式打开指定文件
	{
		printf("                                  打开文件失败!\n");//打开失败输出提示信息
		exit(0);//退出
	}
	readAdm(adm);
	fwrite(adm, sizeAdm, Admnum, fp);//将读入的记录全写入文件
	printf("                                  创建成功!\n");
	fclose(fp);//关闭文件
}

