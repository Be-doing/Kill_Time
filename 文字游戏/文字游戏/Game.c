#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
char name[1024] = { 0 };
char* sex[1];
char name2[1024] = { 0 };
void startGame()
{
	printf("��Ϊ%s�����·���",name2);
	printf(" ");
}
void getname()
{
	getchar();
	while (1)
	{
		gets_s(name2, 1023);
		if (strlen(name2) > 9 || name2[0] == '\0')
		{
			memset(name2, 0, 1023);
			printf("�Ƿ����룬���������룡\n");
		}
		else
		{
			break;
		}
	}
	startGame();
}
//
void Choice()
{
	getchar();
again2:
		printf("�����ޣ��ޣ��������ޣ��ޣ��������ޣ��ޣ���\n");
		printf("Ϊ��������ȷ��ȡ��ۣ���ѡ�����Ķ���\n");
		printf("A��Ů���ѣ�B��������");
		printf("����ѡ���ǣ�");
		char choice = 0;
		scanf("%c", &choice);
		if (choice == 'A')
		{
			if (sex[0] == "Ů")
			{
				printf("Ϊ������г�����������ļ�ֵ�ۣ�������ѡ��\n");
				goto again2;
			}
			printf("��Ϊ����Ů����ȡһ�����֣�");
			getname();
		}
		else if (choice == 'B')
		{
			if (sex[0] == "��")
			{
				printf("Ϊ������г�����������ļ�ֵ�ۣ�������ѡ��\n");
				goto again2;
			}
			printf("��Ϊ����������ȡһ�����֣�");
			getname();
		}
		else if (choice != 'A' || choice != 'B')
		{
			printf("����Ƿ������������롣\n");
			getchar();
			goto again2;
		}
}
//��¼
void Log_in()
{
	int log = 0;
	srand((int)time(0));
	for (int i = 0; i < 9; ++i)
	{
		printf("%s���ڵ�¼����%d%%\n",name, log);
		log = log + rand() % 20;
		Sleep(1111);
	}
	printf("%s���ڵ�¼����100%%\n",name);
	Choice();
}
//����
void Game()
{
	getchar();
	while (1)
	{
		printf("�����ޣ��ޣ��������ޣ��ޣ��������ޣ��ޣ���\n");
		printf("���ã��봴������ID(С��5�����֣���������ĸ���ֺ���)��");
		gets_s(name,1023);
		if (strlen(name) > 9 || name[0] == '\0')
		{
			getchar();
			printf("�Ƿ����룬���������룡\n");
		}
		else
		{
			printf("%s���ã���ѡ�������Ա�",name);
			printf("A����\tB��Ů\n");
			printf("����ѡ���ǣ�");
			char choice = getchar();
			if (choice == 'A')
			{
				sex[0] = "��";
				break;
			}
			else if (choice == 'B')
			{
				sex[0] = "Ů";
				break;
			}
			else
			{
				getchar();
				memset(name,0,1023);
				printf("�Ƿ����룬���������룡\n");
			}
		}
	}
	printf("�����ޣ��ޣ��������ޣ��ޣ��������ޣ��ޣ���\n");
	printf("���Ľ�ɫ�ǣ�%s�������Ա��ǣ�%s\n",name,sex[0]);
	//��¼
	Log_in();
}
void Start()
{
	char choice = 0;
	printf("��ӭ����ģ��������Ϸ��\n");
again:
	{
		printf("�����ޣ��ޣ��������ޣ��ޣ��������ޣ��ޣ���\n");
		printf("��������������1 ������Ϸ<������������\n");
		printf("��������������0 �˳���Ϸ<������������\n");
		printf("�����ޣ��ޣ��������ޣ��ޣ��������ޣ��ޣ���\n");
		printf("����������ѡ��");
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
			printf("�Ƿ����룬���������롣");
			goto again;
		}
	}
}