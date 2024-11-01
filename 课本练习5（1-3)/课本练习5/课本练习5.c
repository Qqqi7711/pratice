#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>

//定义函数totalCost，计算商品总金额

//double totalCost(int n, double p);//函数申明
//int main()
//{
//	double price, bill;//单价，总额
//	int number;//购买数量
//	printf("Enter the number of items purchased:");
//	scanf("%d", &number);
//	printf("Enter the price per item(RMB):");
//	scanf("%lf", &price);
//	bill = totalCost(number, price);
//	printf("The total cost of the items purchased is:%.1f RMB.\n", bill);
//	return 0;
//}
//double totalCost(int n, double p)
//{
//	const double DISCOUNT = 0.2;
//	double total;
//	if (n > 1)
//		total = n * p * (1 - DISCOUNT);
//	else
//		total = n * p;
//	return total;
//}
//
//

//定义函数 judgePrime 来判断任意一个正整数是否为正数

int judgePrime(int x)
{
	int k,i;
	if (1 == x)
		return 0;
	k =(int) sqrt(x);
	for ( i= 2; i < k; i++)
	{
		int b=x % i;
		if (b == 0)
		{
			return 0;
			break;
		}

	}
	if (i >= k)
		return 1;
}

//int main()
//{
//	int n = 0;
//	printf("Please intput a positive integrant:\n");
//	scanf("%d", &n);
//	if (n < 0)
//	{
//		n = -n;
//	}
//	int b = judgePrime(n);
//	if (b)
//	{
//		printf("%d is a prime.\n", n);
//	}
//	else
//	{
//		printf("%d is not a prime.\n", n);
//	}
//	return 0;
//}

//answer

//int judgePrime(int n)
//{
//	int i, k;
//	int judge = 1;
//	if (n == 1)
//		judge=0;
//	k = (int)sqrt(n);
//	for (i = 2;judge && i <= n; i++)
//	{
//		if (n % k == 0)
//			judge = 0;
//	}
//	return judge;
//}
//int main()
//{
//	int n = 0;
//	printf("Please intput a positive integrant:\n");
//	scanf("%d", &n);
//	if (n < 0)
//	{
//		n = -n;
//	}
//	int b = judgePrime(n);
//	if (b)
//	{
//		printf("%d is a prime.\n", n);
//	}
//	else
//	{
//		printf("%d is not a prime.\n", n);
//	}
//	return 0;
//}


//改动主函数，调用judgePrime函数输出所有三位质数，并按每行5个的形式输出

int judgePrime();
//int main()
//{
//	for(int n = 100; n < 1000;n++)
//		{
//		    int b = judgePrime(n);
//
//			if (b)
//			{
//				static int j = 0;
//				printf("%d ", n);
//				j+=1;
//				if (0==j%5)
//					printf("\n");
//			}
//
//		}
//	return 0;
//}

//answer

//int main()
//{
//	int m;
//	int count = 0; //累加器，用于统计已输出个数
//	for (m=101;m<1000;m=m+2)
//		if (judgePrime(m))
//		{
//			printf("%6d", m);
//			count++;
//			if (count % 5 == 0)
//				printf("\n");
//		}
//	return 0;
//}


//define a function of drawLine to draw a line made of n minus sign

//void drawLine(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("-");
//	}
//	printf("\n");
//}
//
//int main()
//{
//	printf("Please input a positive integrant:");
//	int n;
//	scanf("%d", &n);
//	if (n < 0)
//		n = -n;
//	drawLine(n);
//	return 0;
//}


