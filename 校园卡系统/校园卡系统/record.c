#define _CRT_SECURE_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include "record.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <time.h>//Ϊ�˻�ȡʱ��


#pragma comment(lib,"ws2_32.lib")//lib���������ӿ����ָ�������Ҫ���ӵĿ��ļ���
//��ȱʧ���лᵼ�±������޷���ȷ����Windows Sockets����������

//��ȡ��ǰʱ�亯��
Date recordTime()
{
	Date date;
	time_t timeCount = time(NULL);//��ȡʱ�����1970�꿪ʼ������
	struct tm* currentTime = localtime(&timeCount);
	date.year = currentTime->tm_year+1900;//�꣬��1900�꿪ʼ
	date.month = currentTime->tm_mon + 1;//�£�0-11
	date.day = currentTime->tm_mday ;//��
	date.hour = currentTime->tm_hour;//ʱ
	date.minute = currentTime->tm_min;//��
	return date;
}

//��ȡ����IP��ַ������IP����
void recordIP(char*add)
{
	WSADATA wsaData;//��ʼ��Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		perror("��ʼ��ʧ��");//��ʼ��ʧ��
		return ;
	}
	//��ȡ������
	char hostname[256];
	if (gethostname(hostname, sizeof(hostname)) != 0)
	{
		perror("��ȡ������ʧ��");
		WSACleanup();
		return ;
	}
    //������������ȡIP��ַ
	struct hostent* hostinfo = gethostbyname(hostname);
	if (NULL == hostinfo)
	{
		perror("��ȡ������ʧ��");
		WSACleanup();
		return ;
	}
	//�洢IP��ַ
	char ip[30];
	struct in_addr** addr_list = (struct in_addr**)hostinfo->h_addr_list;
	for (int i = 0; addr_list[i] != NULL; i++)
	{
		//�������ֽ����IP��ַת��Ϊ���ʮ�����ַ�����ʽ,����ip������
		strcpy(ip, inet_ntoa(*addr_list[i]));
		strcpy(add, ip);
	}
	WSACleanup();//����Windows Sockets����Դ
	return ;
}


//���㱾���ϼ�ʱ��(��λ��minute)!������������һ��
int useTime(Date startTime, Date endTime)
{
	return (endTime.hour - startTime.hour) * 60 + (endTime.minute - startTime.minute);
}
//���㱾���ϻ��������
double sumFee(int useTime)
{
	return 0.01 * useTime;
}


