#include"Locker.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
main()
{
	srand((int)time(0));
	char* lock = Lock();
	while (1)
	{
		int choice = Interface();
		if (choice)
		{
			int flag = 0;
			printf("���������ǣ�%s",lock[flag]);
			++flag;
		}
		else
		{
			char* arr = "0";
			printf("�������������룺");
			scanf("%s",arr);
			for (int i = 0; i < 100; i++)
			{
				if (strcmp(arr,lock[i]) == 1)
				{
					printf("��ȡ��������Ʒ!\n");
					for (int i = 0; i < 45; ++i)
					{
						printf("��");
					}
					printf("\n");
					for (int row = 0; row < 10; ++row)
					{
						printf("|%02d|\t", row + 1);
						for (int col = 0; col < 10; ++col)
						{
							printf("[^%d^] \t", col + 1);
						}
						printf("||\n");
					}
					for (int i = 0; i < 45; ++i)
					{
						printf("��");
					}
					printf("\n");

				}
			}

		}
	}
	system("pause");
}