#include<iostream>
#include<Windows.h>
using namespace std;
//���ڿ���̨���ڲ�����API�������£�
//GetConsoleScreenBufferInfo ��ȡ����̨������Ϣ
//GetConsoleTitle ��ȡ����̨���ڱ���
//ScrollConsoleScreenBuffer �ڻ��������ƶ����ݿ�
//SetConsoleScreenBufferSize ����ָ����������С
//SetConsoleTitle ���ÿ���̨���ڱ���
//SetConsoleWindowInfo ���ÿ���̨������Ϣ

void Practice1()
{
	//GetConsoleScreenBufferInfo(HANDLE hConsoleOutput, CONSOLE_SCREEN_BUFFER_INFO *bInfo)
	//��һ��hConsoleOutput����(��׼���ƾ��)ͨ��GetStdHandle()��������ֵ���
	//�ڶ�������CONSOLE_SCREEN_BUFFER_INFO �������̨��Ϣ�ṹ��ָ��
	/*���ݳ�Ա���£�
	{
		COORD dwSize; // ��������С
		COORD dwCursorPosition; //��ǰ���λ��
		WORD wAttributes; //�ַ�����
		SMALL_RECT srWindow; //��ǰ������ʾ�Ĵ�С��λ��
		COORD dwMaximumWindowSize; //���Ĵ��ڻ�������С
	}*/
	SetConsoleTitle("Consoleѧϰ");//���ÿ���̨������Ϣ
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO binfo;
	GetConsoleScreenBufferInfo(houtput, &binfo);
	cout << "���ڻ�������С��" << binfo.dwSize.X << ", " << binfo.dwSize.Y << endl;
	cout << "��������λ�ã�" << binfo.srWindow.Left << ", " << binfo.srWindow.Top
		<< ", " << binfo.srWindow.Right << ", " << binfo.srWindow.Bottom << endl;

    //BOOL SetConsoleScreenBufferSize(HANDLE hConsoleOutput, COORD dwSize)����ָ����������С
	COORD size = { 120,1000 };
	SetConsoleScreenBufferSize(houtput, size);
	cout << "���ڻ�������С��" << size.X << ", " << size.Y << endl;

	//BOOL SetConsoleWindowInfo(HANDLE, BOOL, SMALL_RECT *);���ÿ���̨������Ϣ
	SMALL_RECT window = { 0, 0, 100, 28 };
	SetConsoleWindowInfo(houtput, true, &window);
	cout << "��������λ�ã�" << binfo.srWindow.Left << ", " << binfo.srWindow.Top
		<< ", " << binfo.srWindow.Right << ", " << binfo.srWindow.Bottom << endl;

	//DWORD GetConsoleTitle(LPTSTR lpConsoleTitle, DWORD nSize)��ȡ����̨���ڱ���
	char cTitle[255];
	GetConsoleTitleA(cTitle, 255);
	cout << "���ڱ��⣺" << cTitle << endl;
	CloseHandle(houtput);
}
void Practice2()
{
	//BOOL SetConsoleTextAttribute(HANDLE hConsoleOutput, WORD wAttributes);���, �ı�����
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wr1 = 0x0a;//������ɫ���ԣ���һλΪ����ɫ���ڶ�λΪǰ��ɫ
		//0 = ��ɫ       8 = ��ɫ
		//1 = ��ɫ       9 = ����ɫ
		//2 = ��ɫ       A = ����ɫ
		//3 = ǳ��ɫ     B = ��ǳ��ɫ
		//4 = ��ɫ       C = ����ɫ
		//5 = ��ɫ       D = ����ɫ
		//6 = ��ɫ       E = ����ɫ
		//7 = ��ɫ       F = ����ɫ
	SetConsoleTextAttribute(houtput, wr1);//����ֱ������
	cout << "������ɫ�Ŀ���~" << endl;
	CloseHandle(houtput);
}
void Practice3()
{
//���ù��λ��
//SetConsoleCursorPosition(HANDLE hConsoleOutput,COORD dwCursorPosition);
//���ù����Ϣ
//BOOL SetConsoleCursorInfo(HANDLE hConsoleOutput, PCONST PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
//��ȡ�����Ϣ
//BOOL GetConsoleCursorInfo(HANDLE hConsoleOutput,  PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
//����1�����������2��CONSOLE_CURSOR_INFO�ṹ��{DWORD dwSize;(����Сȡֵ1-100)BOOL bVisible;���Ƿ�ɼ�)}
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(houtput, 0x0a);//����ֱ������
	cout << "������~" << endl;

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
	cout << "���̲���" << endl;
	while (1)
	{
		if (_kbhit())
		{
			SetConsoleCursorPosition(houtput, location);
			//cout << "            " << endl;
			Move(&location, _getch());
			SetConsoleCursorPosition(houtput, location);
			cout << "���̲���" ;
		}
	}
}
int main()
{
	Practice5();
	system("pause");
	return 0;
}
