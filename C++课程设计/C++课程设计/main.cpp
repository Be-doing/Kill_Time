
#include"game.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<queue>
#include<ctype.h>
#define A 17	//��ͼ�ĸ�
#define B 17	//��ͼ�Ŀ�
#define C 30	//�׵�����
using namespace std;

//ȫ�ֱ���
DWORD a, b;
char map[A][B], news, spare;
int BoomTotalNum, floatx, floaty, flag[A][B], flagnum, mode, slect[A][B], game;

//��ɫ����
const WORD FORE_BLUE = FOREGROUND_BLUE;	//��ɫ�ı�����
const WORD FORE_GREEN = FOREGROUND_GREEN;	//��ɫ�ı�����
const WORD FORE_RED = FOREGROUND_RED;	//��ɫ�ı�����

//���ѵ�ͼ�ṹ�� 
struct node {
	int x;
	int y;
};
queue <node> dui;

//��ӡλ��
void position(int x, int y) {
	COORD pos = { x,y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

//���ع�� 
void Hide() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ  
	CursorInfo.bVisible = false; //���ؿ���̨���  
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬   
}

//��ʼ��
void Beginning() {
	while (!dui.empty()) {
		dui.pop();
	}
	game = 1;
	//BoomTotalNum=C;
	floatx = A / 2;
	floaty = B / 2;
	flagnum = 0;
	BoomTotalNum = C;
	mode = 0;
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���  
	CONSOLE_SCREEN_BUFFER_INFO csbi;                        //���崰�ڻ�������Ϣ�ṹ��  
	GetConsoleScreenBufferInfo(handle_out, &csbi);          //��ô��ڻ�������Ϣ
	int x, y;
	srand((unsigned)time(0));
	for (int i = 0; i < A; i++) for (int j = 0; j < B; j++) {
		map[i][j] = ' ';
		flag[i][j] = 0;
		slect[i][j] = 0;
	}
	while (BoomTotalNum) {
		x = rand() % A;
		y = rand() % B;
		if (map[x][y] == ' ') {
			map[x][y] = '@';
			BoomTotalNum--;
		}
	}
	SetConsoleTextAttribute(handle_out, FORE_GREEN);
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) printf("��");
		printf("\n");
	}
	position(floaty * 2, floatx);
	SetConsoleTextAttribute(handle_out, FORE_RED);
	printf("��");	//���λ��
	position(44, 9);
	printf("ɨ��ģʽ");
	position(44, 5);
	printf("ʣ��������%d ", C - flagnum);
	SetConsoleTextAttribute(handle_out, FORE_GREEN);
	position(5, 22);
	printf("�����ո��л�ģʽ");
	position(5, 23);
	printf("����Enter��ȷ��");
	position(5, 24);
	printf("�����������ѡ�񷽿�");

}

//��ӡ��ͼ��һ��� 
void Lump(int xx, int yy) {
	switch (map[xx][yy]) {
	case '1': printf("��"); break;	//��Χ�׵���������ͬ�� 
	case '2': printf("��"); break;
	case '3': printf("��"); break;
	case '4': printf("��"); break;
	case '5': printf("��"); break;
	case '6': printf("��"); break;
	case '7': printf("��"); break;
	case '8': printf("��"); break;
	case ' ':
		if (xx == floatx && yy == floaty) {
			if (flag[xx][yy] == 0) {
				if (mode % 2 == 0) printf("��");
				else printf("��");
			}
			else printf("��");
		}
		else {
			if (flag[xx][yy] == 0) printf("��");
			else printf("��");
		}
		break;
	case '@':
		if (xx == floatx && yy == floaty) {
			if (flag[xx][yy] == 0) {
				if (mode % 2 == 0) printf("��");
				else printf("��");
			}
			else printf("��");
		}
		else {
			if (flag[xx][yy] == 0) printf("��");
			else printf("��");
		}
		break;
	case 'x': if (floatx == xx && floaty == yy) printf("��"); else printf("  "); break;	//�Ѿ��ڿ��Ŀհ�
	}
}

//�ƶ����
void Move() {
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���  
	CONSOLE_SCREEN_BUFFER_INFO csbi;                        //���崰�ڻ�������Ϣ�ṹ��  
	GetConsoleScreenBufferInfo(handle_out, &csbi);          //��ô��ڻ�������Ϣ
	int xxx, yyy;
	xxx = floatx;
	yyy = floaty;
	switch (news) {
	case 72: floatx--; break;	//�� 
	case 80: floatx++; break;	//�� 
	case 75: floaty--; break;	//�� 
	case 77: floaty++; break;	//�� 
	}
	if (floatx == -1) floatx = A - 1; floatx %= A;	//���˴�ģ���� 
	if (floaty == -1) floaty = B - 1; floaty %= B;

	position(yyy * 2, xxx);
	SetConsoleTextAttribute(handle_out, FORE_GREEN);
	Lump(xxx, yyy);	//ɾ��ԭλ��

	if (map[floatx][floaty] == 'x') {
		position(floaty * 2, floatx);
		printf("  ");
	}

	position(floaty * 2, floatx);
	SetConsoleTextAttribute(handle_out, FORE_BLUE);
	Lump(floatx, floaty);	//������λ�� 
}

//���������ģʽ�л� 
void Mode() {
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���  
	CONSOLE_SCREEN_BUFFER_INFO csbi;                        //���崰�ڻ�������Ϣ�ṹ��  
	GetConsoleScreenBufferInfo(handle_out, &csbi);          //��ô��ڻ�������Ϣ
	mode++;
	SetConsoleTextAttribute(handle_out, FORE_BLUE);
	position(floaty * 2, floatx);
	if (mode % 2 == 0) printf("��");
	else printf("��");

	position(44, 9);
	if (mode % 2 == 0) {
		SetConsoleTextAttribute(handle_out, FORE_BLUE);
		printf("ɨ��ģʽ");
	}
	else {
		SetConsoleTextAttribute(handle_out, FORE_RED);
		printf("����ģʽ");
	}
}

//�õ���Χ������ 
int Boomnum(int xx, int yy) {
	int num = 0;
	if ((xx - 1 >= 0) && (yy - 1 >= 0) && (map[xx - 1][yy - 1] == '@')) num++;
	if ((xx - 1 >= 0) && (yy + 0 >= 0) && (map[xx - 1][yy] == '@')) num++;
	if ((xx - 1 >= 0) && (yy + 1 < B) && (map[xx - 1][yy + 1] == '@')) num++;
	if ((xx + 0 >= 0) && (yy - 1 >= 0) && (map[xx][yy - 1] == '@')) num++;
	if ((xx + 0 >= 0) && (yy + 1 < B) && (map[xx][yy + 1] == '@')) num++;
	if ((xx + 1 < A) && (yy - 1 >= 0) && (map[xx + 1][yy - 1] == '@')) num++;
	if ((xx + 1 < A) && (yy + 0 >= 0) && (map[xx + 1][yy] == '@')) num++;
	if ((xx + 1 < A) && (yy + 1 < B) && (map[xx + 1][yy + 1] == '@')) num++;
	return num;
}

//���µ�ͼ 
void Open() {
	node c;
	node d;
	while (!dui.empty()) {
		dui.pop();
	}
	c.x = floatx;
	c.y = floaty;
	dui.push(c);
	slect[c.x][c.y] = 1;
	while (!dui.empty()) {
		c = dui.front();
		dui.pop();
		if (Boomnum(c.x, c.y) != 0) {
			map[c.x][c.y] = (Boomnum(c.x, c.y) + 48);
			continue;
		}
		else {
			map[c.x][c.y] = 'x';
			if ((c.x - 1 >= 0) && (c.y - 1 >= 0) && (map[c.x - 1][c.y - 1] == ' ') && (slect[c.x - 1][c.y - 1] == 0)) {
				d.x = c.x - 1;
				d.y = c.y - 1;
				dui.push(d);
				slect[d.x][d.y] = 1;
			}
			if ((c.x - 1 >= 0) && (c.y - 0 >= 0) && (map[c.x - 1][c.y] == ' ') && (slect[c.x - 1][c.y] == 0)) {
				d.x = c.x - 1;
				d.y = c.y - 0;
				dui.push(d);
				slect[d.x][d.y] = 1;
			}
			if ((c.x - 1 >= 0) && (c.y + 1 < B) && (map[c.x - 1][c.y + 1] == ' ') && (slect[c.x - 1][c.y + 1] == 0)) {
				d.x = c.x - 1;
				d.y = c.y + 1;
				dui.push(d);
				slect[d.x][d.y] = 1;
			}
			if ((c.x - 0 >= 0) && (c.y - 1 >= 0) && (map[c.x][c.y - 1] == ' ') && (slect[c.x][c.y - 1] == 0)) {
				d.x = c.x - 0;
				d.y = c.y - 1;
				dui.push(d);
				slect[d.x][d.y] = 1;
			}
			if ((c.x - 0 >= 0) && (c.y + 1 < B) && (map[c.x][c.y + 1] == ' ') && (slect[c.x][c.y + 1] == 0)) {
				d.x = c.x - 0;
				d.y = c.y + 1;
				dui.push(d);
				slect[d.x][d.y] = 1;
			}
			if ((c.x + 1 < A) && (c.y - 1 >= 0) && (map[c.x + 1][c.y - 1] == ' ') && (slect[c.x + 1][c.y - 1] == 0)) {
				d.x = c.x + 1;
				d.y = c.y - 1;
				dui.push(d);
				slect[d.x][d.y] = 1;
			}
			if ((c.x + 1 < A) && (c.y - 0 >= 0) && (map[c.x + 1][c.y] == ' ') && (slect[c.x + 1][c.y] == 0)) {
				d.x = c.x + 1;
				d.y = c.y - 0;
				dui.push(d);
				slect[d.x][d.y] = 1;
			}
			if ((c.x + 1 < A) && (c.y + 1 < B) && (map[c.x + 1][c.y + 1] == ' ') && (slect[c.x + 1][c.y + 1] == 0)) {
				d.x = c.x + 1;
				d.y = c.y + 1;
				dui.push(d);
				slect[d.x][d.y] = 1;
			}
		}
	}
}

int main() {
	freopen("����.txt", "r", stdin);
Relife:	//���洦
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���  
	CONSOLE_SCREEN_BUFFER_INFO csbi;                        //���崰�ڻ�������Ϣ�ṹ��  
	GetConsoleScreenBufferInfo(handle_out, &csbi);          //��ô��ڻ�������Ϣ

	Hide();		//���ع��
	Beginning();//��ʼ����ͼ
	a = GetTickCount();
	while (1) {
		if (kbhit() != 0) {
			spare = getch();

			//������
			if ((spare != (-32)) && (spare != 13) && (spare != ' ')) continue;//���� 

			//��Enter
			if (spare == 13) {	//ȷ�� 
				//����
				if (mode % 2 == 0) {
					if (map[floatx][floaty] == '@'&&flag[floatx][floaty] == 0) {
						break;	//����
						game = 0;
					}

					if (flag[floatx][floaty] == 1) continue;	//��������
					Open();
					position(0, 0);
					SetConsoleTextAttribute(handle_out, FORE_GREEN);
					for (int i = 0; i < A; i++) {
						for (int j = 0; j < B; j++) Lump(i, j);
						printf("\n");
					}
					position(floaty * 2, floatx);
					SetConsoleTextAttribute(handle_out, FORE_BLUE);
					Lump(floatx, floaty);
				}

				//�����
				else {

					//���ܲ���ĵط�
					if (map[floatx][floaty] == 'x' || (map[floatx][floaty] > '0'&&map[floatx][floaty] < '9'))
						continue;	//����

					//����
					if (flag[floatx][floaty] == 0) {
						flagnum++;
						flag[floatx][floaty] = 1;
						position(floaty * 2, floatx);
						SetConsoleTextAttribute(handle_out, FORE_BLUE);
						Lump(floatx, floaty);
					}

					//���� 
					else {
						flagnum--;
						flag[floatx][floaty] = 0;
						position(floaty * 2, floatx);
						SetConsoleTextAttribute(handle_out, FORE_BLUE);
						Lump(floatx, floaty);
					}
				}
			}

			//���ո�
			if (spare == ' ') Mode();	//�л�ģʽ 

			//������� 
			if (spare == -32) {
				news = getch();
				Move();	//�ƶ����
			}
			for (int i = 0; i < A; i++) for (int j = 0; j < B; j++) if (map[i][j] == 'x' || (map[i][j] > '0'&&map[i][j] < '9')) game++;
			if (game == A * B - C + 1) break;
			else game = 1;
			SetConsoleTextAttribute(handle_out, FORE_RED);
			position(44, 5);
			printf("ʣ��������%d ", C - flagnum);
		}
		else Sleep(10);
		b = GetTickCount();
		SetConsoleTextAttribute(handle_out, FORE_RED);
		position(44, 7);
		printf("��ʱ��");	//��ʱ 
		if ((b - a) / 60000 < 10) printf("0");
		printf("%d:", (b - a) / 60000);
		if (((b - a) / 1000) % 60 < 10) printf("0");
		printf("%d:", ((b - a) / 1000) % 60);
		if (((b - a) / 10) % 100 < 10) printf("0");
		printf("%d", ((b - a) / 10) % 100);
	}
	SetConsoleTextAttribute(handle_out, FORE_RED);
	position(5, 5);
	if (game == 1) printf("��Ϸ������");
	else printf("��ϲͨ�أ�");
	position(5, 8);
	printf("���������");
	scanf("%c%c", &spare, &spare);
	system("cls");
	position(0, 0);
	goto Relife;
}

#include"game.h"


//int main() 
//{
//	if (StartGame())
//	{
//		if (LevelGame())
//		{
//			init_arr(mine_map, show_map);
//			PrintMap(show_map);
//		}
//	}
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<time.h>
//#include<stdio.h>
//#include<graphics.h>			//ͼ�ο�
//#include<mmsystem.h>
//#pragma comment(lib,"winmm.lib")		//��Ƶ�豸�ӿ�
//#define N 10  //������
//#define M 50  //ͼƬ��С
//using namespace std;
//IMAGE image[13];		//���ͼƬ
//int map[N + 2][N + 2];			//�����  -1 ��ʾ��
//int gamemodel;
//int win = N * N - 15;
//void StartWindow();		//��ʼ����
//void normalModel();     //10��ģʽ
//void BTmodel();			//99��ģʽ
//void DrawGraph();		//��ͼ��
//int MouseClick();	    //������¼�
//void loadingPlay(int x, int y);	//���õݹ�ʵ�ֵ��һ��Ƭ
//void  main() {
//	initgraph(N*M, N*M);
//	StartWindow();
//	if (gamemodel == 0) {
//		normalModel();
//	}
//	else {
//		BTmodel();
//	}
//	closegraph();
//}
//void StartWindow() {
//	mciSendString(L"open ./�綯��.mp3 alias bgm", 0, 0, 0);
//	mciSendString(L"play bgm repeat", 0, 0, 0);
//	loadimage(&image[0], L"./image/blank.jpg", M, M);
//	loadimage(&image[1], L"./image/1.jpg", M, M);
//	loadimage(&image[2], L"./image/2.jpg", M, M);
//	loadimage(&image[3], L"./image/3.jpg", M, M);
//	loadimage(&image[4], L"./image/4.jpg", M, M);
//	loadimage(&image[5], L"./image/5.jpg", M, M);
//	loadimage(&image[6], L"./image/6.jpg", M, M);
//	loadimage(&image[7], L"./image/7.jpg", M, M);
//	loadimage(&image[8], L"./image/8.jpg", M, M);
//	loadimage(&image[9], L"./image/lei.jpg", M, M);
//	loadimage(&image[10], L"./image/tag.jpg", M, M);
//	loadimage(&image[11], L"./image/start.jpg", N*M, N*M);
//	loadimage(&image[12], L"./image/0.jpg", M, M);
//	putimage(0, 0, &image[11]);
//	MOUSEMSG msg = { 0 };
//	setbkmode(TRANSPARENT);		 //���ñ��� ͸�����
//	settextstyle(40, 18, L"����");
//	while (1) {
//		msg = GetMouseMsg();
//		if (msg.x > 180 && msg.x < 320 && msg.y >250 && msg.y < 290) {
//			settextcolor(RGB(255, 0, 0));		//����������ɫ
//			outtextxy(180, 250, L"15��ģʽ");
//		}
//		else if (msg.x > 180 && msg.x < 320 && msg.y >330 && msg.y < 370) {
//			settextcolor(RGB(255, 0, 0));		//����������ɫ
//			outtextxy(180, 330, L"99��ģʽ");
//		}
//		else if (msg.x > 180 && msg.x < 320 && msg.y >410 && msg.y < 450) {
//			settextcolor(RGB(255, 0, 0));		//����������ɫ
//			outtextxy(180, 410, L"�˳�");
//		}
//		else {
//			settextcolor(RGB(0, 0, 0));		//����������ɫ
//			outtextxy(180, 250, L"15��ģʽ");
//			outtextxy(180, 330, L"99��ģʽ");
//			outtextxy(180, 410, L"�˳�");
//		}
//		switch (msg.uMsg) {
//		case WM_LBUTTONDOWN:
//			if (msg.x > 180 && msg.x < 320 && msg.y >250 && msg.y < 290) {
//				gamemodel = 0;
//				return;
//			}
//			else if (msg.x > 180 && msg.x < 320 && msg.y >330 && msg.y < 370) {
//				gamemodel = 1;
//				return;
//			}
//			else if (msg.x > 180 && msg.x < 320 && msg.y >410 && msg.y < 450) {
//				exit(0);
//			}
//		}
//	}
//}
//void normalModel() {
//	while (1) {
//		cleardevice();
//		win = N * N - 15;
//		int type = 0;
//		HWND hWnd = GetHWnd();
//		int x, y, flag = 0;
//		srand((unsigned)time(NULL));
//		for (int i = 0; i < N + 2; i++) {
//			for (int j = 0; j < N + 2; j++) {
//				map[i][j] = 0;
//			}
//		}
//		while (flag < 15) {  //ʵ����15����
//			x = rand() % 10 + 1;
//			y = rand() % 10 + 1;
//			if (map[x][y] != -1) {
//				map[x][y] = -1;
//				flag++;
//			}
//		}
//		for (int i = 1; i <= N; i++) {	//ɨ������10X10��ʾ���� ʵ����ʾ��Χ8���������׵���Ŀ
//			for (int j = 1; j <= N; j++) {
//				if (map[i][j] != -1) {
//					for (int m = i - 1; m <= i + 1; m++) {//ɨ����������ֵľŸ�����
//						for (int n = j - 1; n <= j + 1; n++) {
//							if (map[m][n] == -1) {
//								map[i][j]++;
//							}
//						}
//					}
//				}
//			}
//		}
//		while (1) {
//			DrawGraph();
//			type = MouseClick();
//			if (type == -1) {
//				DrawGraph();
//				if (MessageBox(hWnd, L"����ȷ������", L"Lose", MB_OK) == IDOK) break;
//			}
//			if (win == 0) {
//				DrawGraph();
//				if (MessageBox(hWnd, L"����ȷ������", L"Win", MB_OK) == IDOK) break;
//			}
//		}
//	}
//}
//void BTmodel() {
//	cleardevice();
//	int x, y, type;
//	HWND hWnd = GetHWnd();
//	srand((unsigned)time(NULL));
//	while (1) {
//		win = 1;
//		for (int i = 0; i < N + 2; i++) {
//			for (int j = 0; j < N + 2; j++) {
//				map[i][j] = -1;
//			}
//		}
//		x = rand() % 10 + 1;
//		y = rand() % 10 + 1;
//		map[x][y] = 0;
//		for (int i = 1; i <= N; i++) {	//ɨ������10X10��ʾ����
//			for (int j = 1; j <= N; j++) {
//				if (map[i][j] != -1) {
//					for (int m = i - 1; m <= i + 1; m++) {//ɨ����������ֵľŸ�����
//						for (int n = j - 1; n <= j + 1; n++) {
//							if (map[m][n] == -1) {
//								map[i][j]++;
//							}
//						}
//					}
//				}
//			}
//		}
//		while (1) {
//			DrawGraph();
//			type = MouseClick();
//			if (type == -1) {
//				DrawGraph();
//				if (MessageBox(hWnd, L"����ȷ������", L"Lose", MB_OK) == IDOK) break;
//			}
//			if (win == 0) {
//				DrawGraph();
//				if (MessageBox(hWnd, L"����ȷ������", L"Lose", MB_OK) == IDOK) break;
//			}
//		}
//	}
//}
//void DrawGraph() {
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			switch (map[i][j])
//			{
//			case 9:putimage((i - 1)*M, (j - 1)*M, &image[9]); break;
//			case 10:putimage((i - 1)*M, (j - 1)*M, &image[0]); break;
//			case 11:putimage((i - 1)*M, (j - 1)*M, &image[1]); break;
//			case 12:putimage((i - 1)*M, (j - 1)*M, &image[2]); break;
//			case 13:putimage((i - 1)*M, (j - 1)*M, &image[3]); break;
//			case 14:putimage((i - 1)*M, (j - 1)*M, &image[4]); break;
//			case 15:putimage((i - 1)*M, (j - 1)*M, &image[5]); break;
//			case 16:putimage((i - 1)*M, (j - 1)*M, &image[6]); break;
//			case 17:putimage((i - 1)*M, (j - 1)*M, &image[7]); break;
//			case 18:putimage((i - 1)*M, (j - 1)*M, &image[8]); break;
//			case 29:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			case 30:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			case 31:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			case 32:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			case 33:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			case 34:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			case 35:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			case 36:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			case 37:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			case 38:putimage((i - 1)*M, (j - 1)*M, &image[10]); break;
//			default:putimage((i - 1)*M, (j - 1)*M, &image[12]); break;
//			}
//		}
//	}
//}
//int MouseClick() {
//	MOUSEMSG msg = { 0 };
//	while (1) {
//		msg = GetMouseMsg();
//		switch (msg.uMsg)
//		{
//		case WM_LBUTTONDOWN:
//			if (map[msg.x / M + 1][msg.y / M + 1] == 0) {
//				loadingPlay(msg.x / M + 1, msg.y / M + 1);
//			}
//			else if (map[msg.x / M + 1][msg.y / M + 1] <= 8) {
//				map[msg.x / M + 1][msg.y / M + 1] += 10;
//				win--;
//			}
//			if (map[msg.x / M + 1][msg.y / M + 1] == 9) {
//				return -1;
//			}
//			break;
//		case WM_RBUTTONDOWN:
//			if (map[msg.x / M + 1][msg.y / M + 1] <= 8) {
//				map[msg.x / M + 1][msg.y / M + 1] += 30;
//			}
//			else if (map[msg.x / M + 1][msg.y / M + 1] >= 29) {
//				map[msg.x / M + 1][msg.y / M + 1] -= 30;
//			}
//			break;
//		}
//		return 0;
//	}
//}
//void loadingPlay(int x, int y) {
//	map[x][y] += 10;
//	win--;
//	for (int i = x - 1; i <= x + 1; i++) {
//		for (int j = y - 1; j <= y + 1; j++) {
//			if (i <= 0 || i >= 11 || j <= 0 || j >= 11)  continue; //��ֹԽ��
//			if (map[i][j] <= 8) {
//				if (map[i][j] == 0) {
//					loadingPlay(i, j);
//				}
//				else if (map[i][j] != -1) {
//					map[i][j] += 10;
//					win--;
//				}
//			}
//		}
//	}
//}
