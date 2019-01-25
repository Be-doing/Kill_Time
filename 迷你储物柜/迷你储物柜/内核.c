#include"Locker.h"
#include<stdio.h>
#include<stdlib.h>

//界面
int choice = 0;
int Interface()
{
	system("COLOR 71");
	printf("\t\t\t(＾Ｕ＾)~ＹＯ欢迎来到未来超市O Y ~ (＾Ｕ＾)\n");
	printf("\n");
	printf("\t\t\t存(1)		O(∩_∩)O		取(0)\n");
	printf("请输入您的选择：");
	
	scanf("%d",&choice);
	for (int i = 0; i < 45; ++i)
	{
		printf("—");
	}
	printf("\n");
	for (int row = 0; row < 10; ++row)
	{
		printf("|%02d|\t",row+1);
		for (int col = 0; col < 10; ++col)
		{
			printf("[^%d^] \t",col+1);
		}
		printf("||\n");
	}
	for (int i = 0; i < 45; ++i)
	{
		printf("—");
	}
	printf("\n");
	return choice;
}

//随机生成密码
char buff[8] = { 0 };

char* Generate_Password()
{
	
	//int arr[8] = { 0 };
	for (int temp = 0; temp < 8; ++temp)
	{
		buff[temp] = '0' + rand() % 9;
	}	
	return buff;
}
//柜子锁存
char* lock[100] = { 0 };
char* Lock()
{
		for (int j = 0; j < 100; ++j)
		{	
			lock[j] = Generate_Password();
		}
	return lock;
}
