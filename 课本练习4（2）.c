#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>

//switch���

//int main()
//{
//	int year, month, daysum;
//	printf("Enter the year and the month:");
//	scanf("%d%d", &year, &month);
//	switch(month)
//	{
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12:
//			daysum = 31;
//			break;
//		case 4:
//		case 6:
//		case 9:
//		case 11:
//			daysum = 30;
//			break;
//		case 2:
//			if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
//			{
//				daysum = 29;
//			}
//			else
//			{
//				daysum = 28;
//			}
//			break;
//	}
//	printf("%d.%d has %d days.\n", year, month, daysum); 
//	return 0;
//}

//while���

//int main()
//{
//	int n, i, sum;
//	printf("Enter a positive integer:");
//	scanf("%d", &n);
//	if (n < 0)
//	{
//		n = -n;//Ϊȷ��nΪ����
//	}
//	i = 1;
//	sum = 0;
//	while (i <= n)
//	{
//		sum +=i;
//		i++;
//
//	}
//	printf("sum=%d\n", sum);
//	return 0;
//}

//do while���

//int main()
//{
//	int fac, i, n;
//	printf("Enter a positive integer:");
//	scanf("%d", &n);
//	if (n < 0)
//	{
//		n = -n;
//	}
//	i = 1;
//	fac = 1;
//	do
//	{
//		fac *= i;
//		i++;
//	} while (i <= n);
//	printf("%d!=%d\n", n, fac);
//	return 0;
//}

//int main()
//{
//	int n, i, sum;
//	printf("Enter a positive intger:");
//	scanf("%d", &n);
//	if (n < 0)
//	{
//		n = -n;
//	}
//	i = 1;
//	sum = 0;
//	do
//	{
//		sum += i;
//		i++;
//	} while (i <= n);
//		printf("sum %d=%d\n", n, sum);
//	return 0;
//} 

//for ���

//�������

//int main()
//{
//	int i, sign;
//	double item, sum;
//	sum = 0;
//	sign = 1;
//	for (i = 1; i <= 1000; i++)
//	{
//		item = sign / (2.0 * i - 1);    //����ÿһ����ۼ���item 2.0���Ա�֤���ᱻ��ȥС��
//		sum += item;                    //���ۼ���item�ӵ��ܺ�sum��
//		sign = -sign;                   //������һ���ۼ���ķ���
//	}
//	printf("sum=%f\n", sum);
//	return 0;
//}

//int main()
//{
//	int i, sign,n;
//	double sum, item;
//	sum = 0;
//	item = 1;
//	sign = 1;
//	printf("Enter a positive interger:");
//	scanf("%d", &n);
//	if (n < 0)
//	{
//		n = -n;
//	}
//	if (1 / (2.0 * n - 1) >=1e-3)
//	{
//		printf("Error!");
//	}
//	else
//	{
//		for (i = 1; i <= n; i++)
//		{
//			item = sign / (2.0 * i - 1);
//			sum += item;
//			sign = -sign;
//		}
//		printf("sum=%f\n", sum);
//	}
//	return 0;
//}
//
//
//

//break��continue������

//int main()
//{
//	int i,n;
//	for (i = 1; i <= 5;i++)
//	{
//		printf("Enter n:");
//		scanf("%d", &n);
//		if (n < 0)
//		{
//			break;
//		}
//		printf("n=%d\n", n);
//	}
//	printf("The end.\n");
//	return 0;
//}

//int main()
//{
//	int i, n;
//	for (i = 1; i <= 5; i++)
//	{
//		printf("Enter n:");
//		scanf("%d", &n);
//		if (n < 0)
//		{
//			continue;
//		}
//		printf("n=%d\n",n);
//	}
//	printf("The end.\n");
//	return 0;
//}

//int main()
//{
//	int i, n;
//	for (i = 1; i <= 5; i++)
//	{
//		printf("Enter n:");
//		scanf("%d", &n);
//		if (n < 0)
//		{
//			break;//�����˴�ѭ��
//		}
//		printf("n=%d\n", n);
//	}
//	printf("The end.\n");
//	return 0;
//}

//Ӧ�þ���

//forѭ����ӡ99�ӷ���

//int main()
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d+%d=%d ", i, j, i + j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//whileѭ����ӡ

//int main()
//{
//	int i = 1;
//    int j;
//	while (i <= 9)
//	{
//		j = 1;
//		while (j <= i)
//		{
//			printf("%d+%d=%2d ", i, j, i + j);
//			j++;
//		}
//		printf("\n");
//		i++;
//	}
//	return 0;
//}

//do whileѭ����ӡ

//int main()
//{
//	int i=1;
//	do
//	{
//		int j = 1;
//		do
//		{
//			printf("%d+%d=%d ", i, j, i + j);
//			j++;
//		} while (j <= i);
//		printf("\n");
//		i++;
//	} while (i <= 9);
//	return 0;
//}
//

//��ӡ������

//int main()
//{
//	int i,j,k;
//	for (i = 1; i<=9; i++)
//	{
//		for (k = 0; k <i - 1; k++)
//		{
//			printf("       ");
//		}
//		for (j = i; j <= 9; j++)
//		{
//			printf("%d+%d=%2d ", i, j, i + j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//answer

//int main()
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%7c", ' ');
//		}
//		for (j = i; j <= 9; j++)
//		{
//			printf("%d+%d=%2d ", i, j, i + j);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int i, j, k;
//	for (i = 1; i <= 4; i++)     //��������
//	{
//		for (k = 4; k> i; k--)     //���ƿո���
//		{
//			printf("%c", ' ');
//		}
//		for (j = 1; j <=2*i+1 ;j++ )   //����*��
//		{
//			printf("%c", '*');
//		}
//		printf("\n");
//	}
//	return 0;
//}

//answer

//int main()
//{
//	int i, j;
//	for (i = 1; i <= 4; i++)
//	{
//		for (j = 1; j <= 4 - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//�����ж�

//int main()
//{
//	int n, k, i;
//	do
//	{
//		printf("Enter a positive integer:");
//		scanf("%d", &n);
//	} while (n <= 0);
//	if (n == 1)
//	{
//		printf("%d is not a prime.\n", n);
//	}
//	else
//	{
//		k = (int)sqrt(n);
//		for (i = 2; i <= k; i++)
//		{
//			if (n % i == 0)
//			{
//				break;
//			}
//		}
//		if (i > k)
//		{
//			printf("%d is a prime.\n", n);
//		}
//		else
//		{
//			printf("%d is not a prime.\n", n);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	//nΪҪ���жϵ�����kΪ����n��iΪѭ������
//	int n, k, i;
//	//��֤nΪ������
//	do
//	{
//		printf("Enter a positive integer:");
//		scanf("%d", &n);
//	} while (n <= 0);
//	k = (int)sqrt(n);
//	//���ж�1
//	if (n == 1)
//	{
//		printf("%d is not a prime.\n", n);
//	}
//	else
//	{
//		for (i = 1; i <= k; i++)
//		{
//			if (n % i == 0)
//				break;
//		}
//		if (i > k)
//		{
//			printf("%d is a prime.\n", n);
//		}
//		else
//		{
//			printf("%d is not a prime.\n",n);
//		}
//	}
//	
//	return 0;
//}

//���100-200������

//int main()
//{
//	int n, k, i;
//	for (n = 100; n <= 200; n++)
//	{
//		k = (int)sqrt(n);
//		for (i = 2; i <= k; i++)
//		{
//			if (n % i  == 0)
//			{
//				break;
//			}
//		}
//		if (i>k)
//		{
//			printf("%d ", n);
//		}
//	}
//	return 0;
//}

//answer

//int main()
//{
//	int n, i, k;
//	for (n = 101; n <= 200; n += 2)
//	{
//		k = (int)sqrt(n);
//		for (i = 2; i <= k; i++)
//		{
//			if (n % i == 0)
//			{
//				break;
//			}
//		}
//		if (i > k)
//		{
//			printf("%4d", n);
//		}
//	}
//	return 0;
//}

//��Ǯ�ټ�

//��ѭ��

//int main()
//{
//	int a, b, c;
//	for (a = 0; a <= 20; a++)
//	{
//		for (b = 0; b <= 33; b++)
//		{
//			for (c = 0; c <= 100; c++)
//			{
//				if (a + b + c == 100 && 15 * a + 9 * b + c == 300)
//				{
//					printf("%d,%d,%d\n", a, b, c);
//				}
//			}
//		}
//	}
//	return 0;
//}

//��ѭ��

//int main()
//{
//	int a, b, c;
//	for (a = 0; a <= 20; a++)
//	{
//		for (b = 0; b <= 33; b++)
//		{
//			c = 100 - a - b;
//			if (15 * a + 9 * b + c == 300)
//			{
//				printf("%d,%d,%d\n", a, b, c);
//			}
//		}
//	}
//	return 0;
//}

//һѭ��

//int main()
//{
//	int a, b, c;
//	for (a = 0; a <= 14; a++)
//	{
//		b = (100 - 7*a)/4;
//		c = (300 + 3*a) / 4;
//		if (a + b + c == 100)
//		{
//			printf("%d,%d,%d\n", a, b, c);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a, b = 0;
//	for (a = 0; a++ <= 2;);
//	b += a;
//	printf("%d,%d\n", a, b);
//	return 0;
//}