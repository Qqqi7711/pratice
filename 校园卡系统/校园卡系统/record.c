#define _CRT_SECURE_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include "record.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <time.h>//为了获取时间


#pragma comment(lib,"ws2_32.lib")//lib表明是链接库相关指令，后着是要连接的库文件名
//若缺失这行会导致编译器无法正确解析Windows Sockets函数的引用

//获取当前时间函数
Date recordTime()
{
	Date date;
	time_t timeCount = time(NULL);//获取时间戳，1970年开始的秒数
	struct tm* currentTime = localtime(&timeCount);
	date.year = currentTime->tm_year+1900;//年，从1900年开始
	date.month = currentTime->tm_mon + 1;//月，0-11
	date.day = currentTime->tm_mday ;//日
	date.hour = currentTime->tm_hour;//时
	date.minute = currentTime->tm_min;//分
	return date;
}

//获取本机IP地址，并把IP储存
void recordIP(char*add)
{
	WSADATA wsaData;//初始化Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		perror("初始化失败");//初始化失败
		return ;
	}
	//获取主机名
	char hostname[256];
	if (gethostname(hostname, sizeof(hostname)) != 0)
	{
		perror("获取主机名失败");
		WSACleanup();
		return ;
	}
    //根据主机名获取IP地址
	struct hostent* hostinfo = gethostbyname(hostname);
	if (NULL == hostinfo)
	{
		perror("获取主机名失败");
		WSACleanup();
		return ;
	}
	//存储IP地址
	char ip[30];
	struct in_addr** addr_list = (struct in_addr**)hostinfo->h_addr_list;
	for (int i = 0; addr_list[i] != NULL; i++)
	{
		//将网络字节序的IP地址转换为点分十进制字符串形式,存在ip数组里
		strcpy(ip, inet_ntoa(*addr_list[i]));
		strcpy(add, ip);
	}
	WSACleanup();//清理Windows Sockets库资源
	return ;
}


//计算本次上级时长(单位：minute)!不能连续上网一天
int useTime(Date startTime, Date endTime)
{
	return (endTime.hour - startTime.hour) * 60 + (endTime.minute - startTime.minute);
}
//计算本次上机所需费用
double sumFee(int useTime)
{
	return 0.01 * useTime;
}


