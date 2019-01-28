#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
char name[1024] = { 0 };
char* sex[1];
char name2[1024] = { 0 };
//
void Choice()
{
	getchar();
again2:
		printf("为了引导正确的取向观，请选择您的对象：\n");
		printf("A—女朋友，B—男朋友");
		printf("您的选择是：");
		char choice = 0;
		scanf("%c", &choice);
		if (choice == 'A')
		{
			if (sex[0] == "女")
			{
				printf("为构建和谐的社会主义核心价值观，请重新选择\n");
				goto again2;
			}
			printf("请为您的女朋友取一个名字\n");
		}
		else if (choice == 'B')
		{
			if (sex[0] == "男")
			{
				printf("为构建和谐的社会主义核心价值观，请重新选择\n");
				goto again2;
			}
			printf("请为您的男朋友取一个名字\n");
		}
		else if (choice != 'A' || choice != 'B')
		{
			printf("输入非法！请重新输入。\n");
			getchar();
			goto again2;
		}
}
//登录
void Log_in()
{
	int log = 0;
	srand((int)time(0));
	for (int i = 0; i < 9; ++i)
	{
		printf("%s正在登录……%d%%\n",name, log);
		log = log + rand() % 20;
		Sleep(1111);
	}
	printf("%s正在登录……100%%\n",name);
	Choice();
}
//界面
void Game()
{
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
			printf("%s您好，请选择您的性别：",name);
			printf("A—男\tB—女\n");
			printf("您的选择是：");
			char choice = getchar();
			if (choice == 'A')
			{
				sex[0] = "男";
				break;
			}
			else if (choice == 'B')
			{
				sex[0] = "女";
				
				break;
			}
			else
			{
				getchar();
				memset(name,0,1023);
				printf("非法输入，请重新输入！\n");
			}
		}
	}
	printf("您的角色是：%s，您的性别是：%s\n",name,sex[0]);
	//登录
	Log_in();
}
void Start()
{
	char choice = 0;
	printf("欢迎进入模拟情侣游戏！\n");
again:
	{
		printf("输入 1 进入游戏，输入 0 退出游戏。请输入您的选择：");
		scanf("%c", &choice);
		if (choice == '1')
		{
			Game();
		}
		else if (choice == '0')
		{
			return;
		}
		else
		{
			printf("非法输入，请重新输入。");
			goto again;
		}
	}
}