#include"Snake.h"
void test1();

void GameTest()
{
	Snake snake = { 0 };		//������һ��
	GameStart(snake);					//��Ϸ��ʼ��׼����������ǽ���������߻�����
	//GameRun();					//���������߼������ӷ�������Ϸ״̬
	//GameEnd();					//��Ϸ����ʱ���ܽ��������ô�����ġ�
}
int main()
{
	GameTest();

	system("pause");
	return 0;
}

void test1()
{
	HANDLE handle = NULL;
	COORD pos = { 0 };
	system("mode con cols=100 lines=50");
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 50;
	pos.Y = 15;
	SetConsoleCursorPosition(handle, pos);
	cout << "���������";
}