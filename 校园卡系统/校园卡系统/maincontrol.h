#ifndef _MAINCONTROL
#define _MAINCONTROL
#include "record.h"
#include "file.h"
#include "menu.h"

char* getPW();//输入密码函数,返回一个pw字符串,记得最后要释放 free

int stuLogin(Student* stu, int* Sn);//学生登录函数,成功返回1，失败返回0
int admLogin(Admini* adm);//管理员登录函数,成功返回1，错误返回0
char* changePW();//修改密码函数,前提：ID已经匹配成功,参数为学生密码,返回新的密码
int changeCard(Student* stu, int choice);//修改学生校园卡信息函数,i为学生所在位置(传址）
void recharge(Student* stu);//充值函数
void useCom(Student* stu);//选择上机选项

int timeValid(Date start, Date end);//检验时间

void adminiL(Admini* adm, Student* stu, int* Sn);//管理员登录选项
void stuL(Admini* adm, Student* stu, int* Sn);//学生登录选项
void aSearInform(Admini* adm, Student* stu, int* Sn);//管理员查询信息选择函数

int getChoice(int max); // 选择函数, 返回 choice(非负)，不会调用上一级菜单

void runMain_1(Student* stu, Admini* adm, int choice, int* Sn);// 主控模块，选择一级菜单功能执行
void runMain_2adm(Admini* adm, Student* stu, int choice, int* Sn);//主控模块，二级菜单(管理员)
void runMain_2stu(Admini* adm, Student* stu, int choice, int* Sn, int position);//主控模块，二级菜单(学生),参数为学生数组结构体地址
void runMain_3adm(Admini* adm, Student* stu, int choice, int* Sn);//主控模块，选择三级菜单管理员功能执行
void runMain_3adm2(Admini* adm, Student* stu, int choice, int* Sn);//主控模块，选择三级菜单管理员收入查询功能执行
void runMain_4(Admini* adm, Student* stu, int choice, int* Sn);//主控模块，选择四级菜单管理员功能执行

#endif 
