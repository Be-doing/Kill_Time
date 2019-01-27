#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<Windows.h>
void Log_in()
{
	printf("正在登录……0%%\n");
	Sleep(1111);
	printf("正在登录……10%%\n");
	Sleep(1111);
	printf("正在登录……25%%\n");
	Sleep(1111);
	printf("正在登录……50%%\n");
	Sleep(1111);
	printf("正在登录……66%%\n");
	Sleep(1111);
	printf("正在登录……79%%\n");
	Sleep(1111);
	printf("正在登录……90%%\n");
	Sleep(1111);
	printf("正在登录……100%%\n");
}
void Game()
{
	char name[1024] = { 0 };
	
	getchar();
	while (1)
	{
		printf("您好，请创建您的ID(小于5个汉字，可以是字母数字汉字)：");
		gets_s(name,1023);
		if (strlen(name) > 9 || name[0] == '\0')
		{
			getchar();
			printf("非法输入，请重新输入！\n");
		}
		else
		{
			break;
		}
	}
	printf("您的ID是%s\n",name);
	Log_in();
}
void Start()
{
	char choice = 0;
	printf("欢迎进入模拟情侣游戏！\n");
again:
	printf("输入 1 进入游戏，输入 0 退出游戏。请输入您的选择：");
	choice = getchar();
	if (choice)
	{
		if (choice != '1' && choice != '0')
		{
			printf("输入非法！\n");
			goto again;
		}
		else
		{
			Game();
		}
		
	}
	else
	{
		return;
	}
} 