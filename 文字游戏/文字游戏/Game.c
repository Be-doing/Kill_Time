#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void Game()
{
	char name[1024] = { 0 };
	
	getchar();
	while (1)
	{
		printf("���ã��봴������ID(С��5�����֣���������ĸ���ֺ���)��");
		gets_s(name,1023);
		if (strlen(name) > 9 || name[0] == '\0')
		{
			getchar();
			printf("�Ƿ����룬���������룡\n");
		}
		else
		{
			break;
		}
	}
	printf("%s",name);
}
void Start()
{
	char choice = 0;
	printf("��ӭ����ģ��������Ϸ��\n");
again:
	printf("���� 1 ������Ϸ������ 0 �˳���Ϸ������������ѡ��");
	choice = getchar();
	if (choice)
	{
		if (choice != '1' && choice != '0')
		{
			printf("����Ƿ���\n");
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