#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<Windows.h>
void Log_in()
{
	printf("���ڵ�¼����0%%\n");
	Sleep(1111);
	printf("���ڵ�¼����10%%\n");
	Sleep(1111);
	printf("���ڵ�¼����25%%\n");
	Sleep(1111);
	printf("���ڵ�¼����50%%\n");
	Sleep(1111);
	printf("���ڵ�¼����66%%\n");
	Sleep(1111);
	printf("���ڵ�¼����79%%\n");
	Sleep(1111);
	printf("���ڵ�¼����90%%\n");
	Sleep(1111);
	printf("���ڵ�¼����100%%\n");
}
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
	printf("����ID��%s\n",name);
	Log_in();
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