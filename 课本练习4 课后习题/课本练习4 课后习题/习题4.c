#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>

//int main()
//{
//	int x = 1, y = 1, z = 1;
//	switch (x)
//	{
//	case 1:
//		switch (y)
//		{
//		case 1:printf("!!"); break;
//		case 2:printf("@@"); break;
//		case 3:printf("##"); break;
//		}
//	case 0:
//		switch (z)
//		{
//		case 0:printf("$$");
//		case 1:printf("^^");
//		case 2:printf("&&");
//		}
//	default:printf("**");
//	}
//
//	return 0;
//}

//int main()
//{
//	int m = 0, n = 4521;
//	do
//	{
//		m = m * 10 + n % 10;
//		n /= 10;
//	} while (n);
//	printf("m=%d\n", m);
//	return 0;
//}

//int main()
//{
//	int x, y = 0, z = 0;
//	for (x = 1; x <= 5; x++)
//	{
//		y = y + x;
//		z = z + y;
//	}
//	printf("z=%d\n", z);
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2;
//	for (; a < 8; a++)
//	{
//		a += 2;
//		if (a == 6)
//		{
//			continue;
//		}
//		if (a > 7)
//		{
//			break;
//		}
//		b++;
//	}
//	printf("%d %d\n", a, b);
//	return 0;
//}

//输出符号函数的值

//用if

//int main()
//{
//	double x;
//	printf("Enter a number:");
//	scanf("%lf", &x);
//	if (x < 0)
//	{
//		printf("-1");
//	}
//	else if (x == 0)
//	{
//		printf("0");
//	}
//	else
//	{
//		printf("1");
//	}
//	return 0;
//}


//成绩转换输出

//int main()
//{
//	int x,y;
//	do
//	{
//		printf("Please intput a grade:");
//		scanf("%d", &x);
//	} while (x < 0 || x>100);
//	y = x / 10;
//	switch (y)
//	{
//	case 10:
//	case 9:
//		printf("The grade is A.\n");
//		break;
//	case 8:
//		printf("The grade is B.\n");
//		break;
//	case 7:
//		printf("The grade is C.\n");
//		break;
//	case 6:
//		printf("The grade is D.\n");
//		break;
//	case 5:
//	case 4:
//	case 3:
//	case 2:
//	case 1:
//	case 0:
//		printf("The grade is F.\n");
//	}
//	return 0;
//}

//answer

//int main()
//{
//	int score;
//	char grade;
//	printf("Enter a score:");
//	scanf("%d", &score);
//	if (score < 0 || score>100)
//	{
//		printf("Error input!\n");
//	}
//	else
//	{
//		switch (score / 10)
//		{
//		case 10:
//		case 9:
//			grade = 'A';
//			break;
//		case 8:
//			grade = 'B';
//			break;
//		case 7:
//			grade = 'C'; 
//			break;
//		case 6:
//			grade = 'D';
//			break;
//		case 5:
//		case 4:
//		case 3:
//		case 2:
//		case 1:
//		case 0:
//			grade = 'F';
//		}
//		printf("%d--%c\n",  score,grade);
//	}
//	return 0;
//}

//3.

//int main()
//{
//	int n, f1,f2,f3;
//	f1 = 1;
//	f2 = 1;
//	printf("%d %d ", f1, f2);
//	for (n = 3; n <= 10; n++)
//	{
//		f3 = f1 + f2;
//		printf("%d ", f3);
//		f1 = f2;
//		f2 = f3;
//	}
//	return 0;
//}

//4.

//int main()
//{
//	int x, y, z;
//	for (x = 1; x <35; x++)
//	{
//		for (y = x+1; y < 50; y++)
//		{
//			for (z = y+1; z <=50;z++)
//			{
//				if (x * x + y * y == z * z)
//					printf("%d %d %d\n", x, y, z);
//			}
//		}
//	}
//	return 0;
//}

//answer

//int main()
//{
//	int x, y,z;
//	for (x = 1; x <= 48; x++)
//	{
//		for (y = x + 1; y <=49; y++)
//		{
//			for (z = y + 1; z <= 50; z++)
//			{
//				if (x * x + y * y == z * z)
//					printf("%3d %3d %3d\n", x, y, z);
//			}
//		}
//	}
//	return 0;
//}

//5.

//int main()
//{
//	int a, b, c;
//	printf("Enter two integers:");
//	scanf("%d %d", &a, &b);
//	for (c = a % b; c != 0; )
//	{
//		a = b;
//		b = c;
//		c = a % b;
//	}
//	printf("%d", b);
//	return 0;
//}

//answer

//int main()
//{
//	int a, b, d;
//	scanf("%d%D", &a, &b);
//	d = a % b;
//	while (d != 0)
//	{
//		a = b;
//		b = d;
//		d = a % b;
//	}
//	printf("%d\n", b);
//	return 0;
//}

//6.

//int main()
//{
//	float s, m,i;
//	int n, sign,y;
//	printf("Enter a number:");
//	scanf("%f", &m);
//	n = 1;
//	y = 1;
//	sign = 1;
//	s = 0;
//	do
//	{
//		y *=n ;//阶层
//		i = sign * pow(m, n) / y;//计算每一项
//		s += i;//求和
//		n++;
//		sign = -sign;//改变符号
//	} while (fabs(i)>=1e-4);
//	printf("%.2f", s);
//	return 0;
//}

//answer

//int main()
//{
//	double s, m, item;
//	int n, sign;
//	scanf("%lf", &m);
//	s = 0;
//	n = 1;
//	sign = 1;
//	item = 1;
//	do
//	{
//		item = item * m / n;
//		s += sign * item;
//		sign = -sign;
//		n++;
//	} while (fabs(item) >= 1e-4);
//	printf("%.2f\n", s);
//	return 0;
//}

//7.

//int main()
//{
//	int i, j;//i控制行数，j控制空格数与*数
//	for (i = 1; i <= 5; i++)
//	{
//		for (j = 0; j < i - 1; j++)//控制空格数
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 11 - 2 * i; j++)//控制*数
//		{
//			printf("*");
//		}
//		for (j = 0; j < i - 1 + 6; j++)//控制第二个空格数
//		{
//			printf(" ");
//		}
//		for (j = i; j<=2;j++)//控制第三个空格数
//		{
//			printf(" ");
//		}
//		for (j=i;j>0&&j<=3;j--)//控制第二个*数
//		{
//			printf("*");
//		}
//		for (j = i; j>3&&j<=5; j++)//控制第三个*数
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//answer

//int main()
//{
//	int i, j;
//	for (i = 1; i <= 5; i++)
//	{
//		if (i <= 3)
//		{
//			for (j = 1; j <= 3 - i; j++)
//				printf(" ");
//		}
//		for (j = 1; j <= 3 - fabs(3 - i); j++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}

//8.

//int main()
//{
//	int  i,n, k, j;//i控制循环次数，n控制数字，k等于根号n，j控制每行输出个数
//	j = 0;
//	for (n = 101; n < 999; n += 2)
//	{
//		k = (int)sqrt(n);
//		for (i = 2; i <= k; i++)
//		{
//			if (n % i == 0)
//				break;
//		}
//		if (i > k)
//		{
//			printf("%d ", n);
//			j++;
//			if (j % 8 == 0)
//			{
//				printf("\n");     //这个换行if的判断要放在输出的这个选择里面，否则当它不输出时，
//                                   j的值会一直不变，即一直输出\n，直到出现新的质数
//			}
//		}
//	}
//	return 0;
//}

//answer

//int main()
//{
//	int n, i, k, count = 0;
//	for (n = 101; n <= 999; n += 2)
//	{
//		k = (int)sqrt(n);
//		for (i = 2; i <= k; i++)
//		{
//			if (n % i == 0)
//				break;
//		}
//		if (i > k)
//		{
//			count++;
//			printf("%4d", n);
//			if (count % 8 == 0)
//				printf("\n");
//		}
//	}
//	printf("\n");
//	return 0;
//}

//9.

//int main()
//{
//	int x, y, z,count=0;
//	for (z = 1; z <= 30; z++)
//	{
//		y = 50 - 4 * z;
//		x = 50 + 3 * z;
//		if (y >= 1 && x >= 1)
//		{
//			printf("1 cent--%2d,2 cent--%2d,5 cent--%2d\n", x, y, z);
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//answer

//int main()
//{
//	int i, j, k, count = 0;
//	for (i = 1; i <= 30; i++)
//	{
//		for (j = 1; j < 73; j++)
//		{
//			k = 100 - i - j;
//			if (5 * i + 2 * j + k == 150)
//			{
//				printf("%3d %3d %3d\n", i, j, k);
//				count++;
//			}
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}