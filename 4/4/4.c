#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int day= 0;
	printf("ѧϰ����\n");
	scanf("%d\n", &day);
	
	if (day >= 10000)
	{
		printf("��ϲ��ѧҵ�гɣ�\n");
	}
	else
	{
		printf("�ǳ��ź������������\n");
	}
	while (day < 10000);
	{
		printf("ѧϰ������%d\n", day);
		day++;
	}
	return 0;
}