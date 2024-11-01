#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void game()
{
	int ret = rand() % 10 + 1;
	printf("请输入一个数字（0-10）：\n");
	int a = 0;
	do
	{
		scanf("%d", &a);
		if (a == ret)
		{
			printf("恭喜你！＼(＠＾０＾＠)/\n");
			break;
		}
		else if (a < ret)
		{
			printf("猜小咯……\( > < )/\n");
		}
		else
		{
			printf("猜大咯(๑•̀ㅂ•́)و✧\n");
		}
	} while (1);
}

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	printf("你的电脑即将关机，请60秒内输入“我是大傻子”并完成猜数字大小游戏以取消关机<(￣︶￣)>\n");
	while (1)
	{
		scanf("%s", input);
		if (strcmp(input,"我是大傻子") == 0)
		{
			srand((unsigned int)time(NULL));
			game();
			system("shutdown -a");
			break;
		}
		else
		{
			printf("勉为其难再给你一次机会o(￣ヘ￣o＃)\n");

		}
	}
	return 0;
}