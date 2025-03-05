#ifndef _FILE
#define _FILE
#include"information.h"

int readSFile(Student* stu); //将文件中内容读出置于结构体数组stu中
void saveSFile(Student* stu,int Sn); //将结构体数组的内容写入文件
int createSFile(Student *stu,int *Sn); //建立初始的数据文件

int readAFile(Admini* adm);//读管理员文件
void saveAFile(Admini* adm, int An);//保存管理员信息
void createAFile(Admini* adm);//n为管理员人数,创建管理员的文件

#endif // !_FILE
