#include"Locker.h"
#include<stdio.h>
//界面
void Interface()
{
	system("COLOR 71");
	printf("\t\t\t(＾Ｕ＾)~ＹＯ欢迎来到未来超市O Y ~ (＾Ｕ＾)\n");
	printf("\n");
	printf("\t\t\t存		O(∩_∩)O		取\n");
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
}