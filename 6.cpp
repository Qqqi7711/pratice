#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//�����������֣���max
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		printf("%d", a);
//	}
//	else
//	{
//		printf("%d", b);
//	}
//	return 0;
//}

//y=f(x),��x<0,y=1;��x=0,y=0;��x>0,y=-1����-10000<x<10000
int main()
//{
//	int x=0;
//	scanf("%d", &x);
//	if (x < 0)
//	{
//		printf("%d",1);
//	}
//	if (x == 0)
//	{
//		printf("%d", 0);
//	}
//	else
//	{
//		printf("%d,-1");
//		return 0;
//	}
//

{
	int x = 0;
	scanf("%d",&x);
	int y = 0;
	if (x < 0)
		y = 1;
	else if (x == 0)
		y = 0;
	else
		y = -1;
	printf("%d", y);
	return 0;
}