#ifndef _STUDENT
#define _STUDENT
#include "record.h"

#define Recnum 20//上机次数
#define Stunum 20//学生人数
#define Pwlength 20//密码长度
#define Admnum 1//管理员人数
#define sizeStu sizeof(Student)//一个学生记录所需要的空间大小
#define sizeAdm sizeof(Admini)//一个管理员记录所需的空间大小

typedef struct Student   /*学生结构体*/
{
	int ID;//卡号
	char name[20];//姓名
	double remain;//余额
	int cardState;//卡状态 1--正常 2--挂失 3--冻结
	char password[Pwlength];//初始密码@123456
	Record totalRecord[Recnum];//总上机记录，只存20次
	int rNum;//下一次上机记录要存放在数组中的位置
	int count;//密码错误机会
}Student;

typedef struct Administrator
{
	char admID[20];
	char admPW[Pwlength];
	sumRecord daySum[31];//储存所有学生日记录,只记录本一月
	sumRecord monSum[12];//储存所有学生月记录，只记录本一年
	sumRecord yearSum[5];//存储所有学生年记录,只记录近五年
}Admini;


void uDay(Admini* adm, Student* stu, Date date, int Sn);//计算所有学生本日,及本月以前的日期的上机总时长(hour),及费用，并存入adm中
void uMon(Admini* adm, Student* stu, Date date, int Sn);// 计算本年每月的上机时长与费用
void uYear(Admini* adm, Student* stu, Date curDate, int Sn);// 计算近五年的上机时长与费用

int IDCompare(Student* stu, int id, int Sn);//学号匹配函数,匹配成功返回i(学生所在位置），失败返回-1
int PWCompare(char password[], char* pw);//密码匹配函数，成功返回1，失败返回0

void sortID(Student* stu, int n);//把学号排序函数,选择交换法,n为储存学生人数
void searchStu(Student* stu);//通过ID来查找学生校园卡基本信息函数

const char* getCS(int cardSate);//卡状态显示函数
void stuHead();//表头函数，打印表头,学生信息
void recHead();//上机记录信息的表头
void printTime(Date date);//打印时间函数,不会自动转行
void printTStu(Student* stu, int Sn);//打印全部学生信息
void printStu(Student stu);//打印某个学生基本信息

int deleteCard(Student* stu, int *Sn);//删除学生校园卡信息函数,返回现有学生人数,n为学生人数



void lossCard(Student *stu);//将卡挂函数，参数为需要挂失的学生结构体
void cancelLost(Student *stu);//解挂函数

int readStu(Student* stu,int *Sn);//从键盘获得学生初始数据(管理员权限
void readAdm(Admini* adm);//读管理员信息

#endif
