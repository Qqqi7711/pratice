#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>


//if���


//int main()
//{
//	double edge1, edge2, edge3, p, area;
//	printf("Enter three edges of a triangle:");
//	scanf("%lf%lf%lf", &edge1, &edge2, &edge3);
//	//�ж�3edges�Ƿ��ܹ���triangle
//	//ע�����߳��Ⱦ�����0��
//	if (edge1 + edge2 > edge3 && edge2 + edge3 > edge1 && edge1 + edge3 > edge2
//		&&edge1>0&&edge2>0&&edge3>0)
//	{
//		p = (edge1 + edge2 + edge3) / 2;
//		area = sqrt(p * (p - edge1) * (p - edge2) * (p - edge3));
//		printf("The area is=%lf\n", area);
//	}
//	else
//	{
//		printf("Error input!z\n");
//	}
//	return 0;
//}

//int main()
//{
//	int age1, age2;
//	printf("Please enter age of two person:\n");
//	scanf("%d%d", &age1, &age2);
//	if (age1 > age2)
//	{
//		printf("The older age is %d\n", age1);
//	}
//	else
//	{
//		printf("The older age is %d\n", age2);
//	}
//	return 0;
//}
//

//int main()
//{
//	double edge1, edge2, edge3;
//	printf("Enter three edges of a triangle:");
//	scanf("%lf%lf%lf", &edge1, &edge2, &edge3);
//	if (edge1 <= 0 || edge2 <= 0 || edge3 <= 0)//�ж����������
//	{
//		printf("Error input!");
//	}
//	else
//	{//triangle ���б�  Ƕ��if
//		if (edge1 + edge2 > edge3 && edge1 + edge3 > edge2 && edge2 + edge3 > edge1)
//		{
//			//�жϳɹ��������ν����ж��Ƿ�Ϊֱ��������
//			if (fabs(edge1 * edge1 + edge2 * edge2 - edge3 * edge3)<1e-2
//				||fabs(edge1*edge1+edge3*edge3-edge2*edge2)<1e-2
//				||fabs(edge2*edge2+edge3*edge3-edge1*edge1)<1e-2)
//				//double�������ݲ�׼ȷ��һ�㲻ʹ��==�����жϣ�һ����Ϊ������Ľ��С��һ����С��ֵ�ͽ��������
//			{
//				printf("%f,%f,%f is a right triangle.\n", edge1, edge2, edge3);//right triangle
//			}
//			else
//			{
//				printf("%f,%f,%f is a ordinary triangle.\n", edge1, edge2, edge3);//oridinary triangle
//			}
//		}
//		//not a triangle
//		else
//		{
//			printf("%f,%f,%f is not a triangle,\n", &edge1, &edge2, &edge3);
//		}
//	}
//	return 0;
//}

//switch���

//�����·�����
//int main()
//{
//	int year, month, daysum;
//	printf("Enter the year and the month:");
//	scanf("%d%d", &year, &month);
//	switch (month)
//	{
//	case 1:
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:
//		daysum = 31;
//		break;
//	case 4:
//	case 6:
//	case 9:
//	case 11:
//		daysum = 30;
//		break;
//	case 2:
//		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
//		{
//			daysum = 29;
//		}
//		else
//		{
//			daysum = 28;
//		}
//	}
//	printf("%d.%d has %d days.\n", year, month, daysum);
//	return 0;
//}

//while���

 //���ۼӺ�
//int main()
//{
//	int n, sum, i;
//	printf("Enter a positive integer:");
//	scanf("%d", &n);
//	//�ж�n�Ƿ�Ϊa positive integer
//	if (n < 0)
//	{
//		n = -n;
//	}
//	i = 1;
//	sum = 0;
//	while (i <= n)
//	{
//		sum += i;
//		i++;
//	}
//	printf("=%d\n", sum);
//	return 0;
//}
