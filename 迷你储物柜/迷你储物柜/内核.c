#include"Locker.h"
#include<stdio.h>
#include<stdlib.h>

//����
int choice = 0;
int Interface()
{
	system("COLOR 71");
	printf("\t\t\t(�ޣգ�)~�٣ϻ�ӭ����δ������O Y ~ (�ޣգ�)\n");
	printf("\n");
	printf("\t\t\t��(1)		O(��_��)O		ȡ(0)\n");
	printf("����������ѡ��");
	
	scanf("%d",&choice);
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
	return choice;
}

//�����������
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
//��������
char* lock[100] = { 0 };
char* Lock()
{
		for (int j = 0; j < 100; ++j)
		{	
			lock[j] = Generate_Password();
		}
	return lock;
}
