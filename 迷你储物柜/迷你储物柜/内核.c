#include"Locker.h"
#include<stdio.h>
//����
void Interface()
{
	system("COLOR 71");
	printf("\t\t\t(�ޣգ�)~�٣ϻ�ӭ����δ������O Y ~ (�ޣգ�)\n");
	printf("\n");
	printf("\t\t\t��		O(��_��)O		ȡ\n");
	for (int i = 0; i < 45; ++i)
	{
		printf("��");
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
		printf("��");
	}
	printf("\n");
}