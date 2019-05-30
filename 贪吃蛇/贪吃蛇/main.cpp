#include"Snake.h"
void test1();

void GameTest()
{
	Snake snake = { 0 };		//创建蛇一条
	GameStart(snake);					//游戏开始的准备工作，把墙画出来，蛇画出来
	//GameRun();					//跑起来的逻辑，增加分数、游戏状态
	//GameEnd();					//游戏结束时，总结分数，怎么结束的。
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
	cout << "光标在这里";
}