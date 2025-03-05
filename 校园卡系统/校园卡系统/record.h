#ifndef _RECORD
#define _RECORD

typedef struct Date //日期
{
	int year; //年
	int month; //月
	int day; //日
	int hour; //时
	int minute; //分
}Date;
typedef struct Record //一次上机记录
{
	Date starttime; //开始时间
	Date endtime; //结束时间
	int duration;//上机用时（min)
	char address[20]; //上机地点
	double fee; //上机花费
}Record;

typedef struct sumRecord //统计上机记录(所有人)，给管理员查看的
{
	double Time; //日时间总结(hour)
	double Fee; //日费用总结(yuan)
}sumRecord;

Date recordTime();//获取当前时间函数
void recordIP(char *add);//获取本机IP地址,失败返回0,成功返回1，并把IP储存
int useTime(Date startTime, Date endTime);//计算本次上级时长(单位：minute)!不能连续上网一天
double sumFee(int useTime);//计算本次上机所需费用



#endif