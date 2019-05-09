#include<iostream>
#include<Windows.h>
using namespace std;
//用于控制台窗口操作的API函数如下：
//GetConsoleScreenBufferInfo 获取控制台窗口信息
//GetConsoleTitle 获取控制台窗口标题
//ScrollConsoleScreenBuffer 在缓冲区中移动数据块
//SetConsoleScreenBufferSize 更改指定缓冲区大小
//SetConsoleTitle 设置控制台窗口标题
//SetConsoleWindowInfo 设置控制台窗口信息

void Practice1()
{
	//GetConsoleScreenBufferInfo(HANDLE hConsoleOutput, CONSOLE_SCREEN_BUFFER_INFO *bInfo)
	//第一个hConsoleOutput参数(标准控制句柄)通过GetStdHandle()函数返回值获得
	//第二个参数CONSOLE_SCREEN_BUFFER_INFO 保存控制台信息结构体指针
	/*数据成员如下：
	{
		COORD dwSize; // 缓冲区大小
		COORD dwCursorPosition; //当前光标位置
		WORD wAttributes; //字符属性
		SMALL_RECT srWindow; //当前窗口显示的大小和位置
		COORD dwMaximumWindowSize; //最大的窗口缓冲区大小
	}*/
	SetConsoleTitle("Console学习");//设置控制台窗口信息
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO binfo;
	GetConsoleScreenBufferInfo(houtput, &binfo);
	cout << "窗口缓冲区大小：" << binfo.dwSize.X << ", " << binfo.dwSize.Y << endl;
	cout << "窗口坐标位置：" << binfo.srWindow.Left << ", " << binfo.srWindow.Top
		<< ", " << binfo.srWindow.Right << ", " << binfo.srWindow.Bottom << endl;

    //BOOL SetConsoleScreenBufferSize(HANDLE hConsoleOutput, COORD dwSize)更改指定缓冲区大小
	COORD size = { 120,1000 };
	SetConsoleScreenBufferSize(houtput, size);
	cout << "窗口缓冲区大小：" << size.X << ", " << size.Y << endl;

	//BOOL SetConsoleWindowInfo(HANDLE, BOOL, SMALL_RECT *);设置控制台窗口信息
	SMALL_RECT window = { 0, 0, 100, 28 };
	SetConsoleWindowInfo(houtput, true, &window);
	cout << "窗口坐标位置：" << binfo.srWindow.Left << ", " << binfo.srWindow.Top
		<< ", " << binfo.srWindow.Right << ", " << binfo.srWindow.Bottom << endl;

	//DWORD GetConsoleTitle(LPTSTR lpConsoleTitle, DWORD nSize)获取控制台窗口标题
	char cTitle[255];
	GetConsoleTitleA(cTitle, 255);
	cout << "窗口标题：" << cTitle << endl;
	CloseHandle(houtput);
}
void Practice2()
{
	//BOOL SetConsoleTextAttribute(HANDLE hConsoleOutput, WORD wAttributes);句柄, 文本属性
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wr1 = 0x0a;//定义颜色属性；第一位为背景色，第二位为前景色
		//0 = 黑色       8 = 灰色
		//1 = 蓝色       9 = 淡蓝色
		//2 = 绿色       A = 淡绿色
		//3 = 浅绿色     B = 淡浅绿色
		//4 = 红色       C = 淡红色
		//5 = 紫色       D = 淡紫色
		//6 = 黄色       E = 淡黄色
		//7 = 白色       F = 亮白色
	SetConsoleTextAttribute(houtput, wr1);//或是直接输入
	cout << "主题颜色的控制~" << endl;
	CloseHandle(houtput);
}
void Practice3()
{
//设置光标位置
//SetConsoleCursorPosition(HANDLE hConsoleOutput,COORD dwCursorPosition);
//设置光标信息
//BOOL SetConsoleCursorInfo(HANDLE hConsoleOutput, PCONST PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
//获取光标信息
//BOOL GetConsoleCursorInfo(HANDLE hConsoleOutput,  PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
//参数1：句柄；参数2：CONSOLE_CURSOR_INFO结构体{DWORD dwSize;(光标大小取值1-100)BOOL bVisible;（是否可见)}
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(houtput, 0x0a);//或是直接输入
	cout << "光标控制~" << endl;

	Sleep(2000);
	COORD location = { 0, 0 };
	SetConsoleCursorPosition(houtput, location);

	Sleep(2000);
	CONSOLE_CURSOR_INFO w = { 1,0};
	SetConsoleCursorInfo(houtput, &w);

	CloseHandle(houtput);
}
#include <conio.h>
void Move(COORD* MoPos, int key)
{
	switch (key)
	{
	case 72: MoPos->Y--; break;
	case 75: MoPos->X--; break;
	case 77: MoPos->X++; break;
	case 80: MoPos->Y++; break;
	default: break;
	}
}
void prin(COORD PrPos)
{

}
void Practice5()
{
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD location = { 0, 0 };
	SetConsoleCursorPosition(houtput, location);
	cout << "键盘操作" << endl;
	while (1)
	{
		if (_kbhit())
		{
			SetConsoleCursorPosition(houtput, location);
			//cout << "            " << endl;
			Move(&location, _getch());
			SetConsoleCursorPosition(houtput, location);
			cout << "键盘操作" ;
		}
	}
}
int main()
{
	Practice5();
	system("pause");
	return 0;
}
