#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int day= 0;
	printf("学习天数\n");
	scanf("%d\n", &day);
	
	if (day >= 10000)
	{
		printf("恭喜你学业有成！\n");
	}
	else
	{
		printf("非常遗憾，请继续加油\n");
	}
	while (day < 10000);
	{
		printf("学习天数：%d\n", day);
		day++;
	}
	return 0;
}