
#include"game.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<queue>
#include<ctype.h>
#define A 17	//地图的高
#define B 17	//地图的宽
#define C 30	//雷的总数
using namespace std;

//全局变量
DWORD a, b;
char map[A][B], news, spare;
int BoomTotalNum, floatx, floaty, flag[A][B], flagnum, mode, slect[A][B], game;

//颜色属性
const WORD FORE_BLUE = FOREGROUND_BLUE;	//蓝色文本属性
const WORD FORE_GREEN = FOREGROUND_GREEN;	//绿色文本属性
const WORD FORE_RED = FOREGROUND_RED;	//红色文本属性

//开垦地图结构体 
struct node {
	int x;
	int y;
};
queue <node> dui;

//打印位置
void position(int x, int y) {
	COORD pos = { x,y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

//隐藏光标 
void Hide() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息  
	CursorInfo.bVisible = false; //隐藏控制台光标  
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态   
}

//初始化
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
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
	CONSOLE_SCREEN_BUFFER_INFO csbi;                        //定义窗口缓冲区信息结构体  
	GetConsoleScreenBufferInfo(handle_out, &csbi);          //获得窗口缓冲区信息
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
		for (int j = 0; j < B; j++) printf("█");
		printf("\n");
	}
	position(floaty * 2, floatx);
	SetConsoleTextAttribute(handle_out, FORE_RED);
	printf("");	//光标位置
	position(44, 9);
	printf("扫雷模式");
	position(44, 5);
	printf("剩余雷数：%d ", C - flagnum);
	SetConsoleTextAttribute(handle_out, FORE_GREEN);
	position(5, 22);
	printf("按“空格”切换模式");
	position(5, 23);
	printf("按“Enter”确认");
	position(5, 24);
	printf("按“方向键”选择方块");

}

//打印地图的一块儿 
void Lump(int xx, int yy) {
	switch (map[xx][yy]) {
	case '1': printf("①"); break;	//周围雷的数量（下同） 
	case '2': printf("②"); break;
	case '3': printf("③"); break;
	case '4': printf("④"); break;
	case '5': printf("⑤"); break;
	case '6': printf("⑥"); break;
	case '7': printf("⑦"); break;
	case '8': printf("⑧"); break;
	case ' ':
		if (xx == floatx && yy == floaty) {
			if (flag[xx][yy] == 0) {
				if (mode % 2 == 0) printf("");
				else printf("");
			}
			else printf("");
		}
		else {
			if (flag[xx][yy] == 0) printf("█");
			else printf("");
		}
		break;
	case '@':
		if (xx == floatx && yy == floaty) {
			if (flag[xx][yy] == 0) {
				if (mode % 2 == 0) printf("");
				else printf("");
			}
			else printf("");
		}
		else {
			if (flag[xx][yy] == 0) printf("█");
			else printf("");
		}
		break;
	case 'x': if (floatx == xx && floaty == yy) printf(""); else printf("  "); break;	//已经挖开的空白
	}
}

//移动光标
void Move() {
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
	CONSOLE_SCREEN_BUFFER_INFO csbi;                        //定义窗口缓冲区信息结构体  
	GetConsoleScreenBufferInfo(handle_out, &csbi);          //获得窗口缓冲区信息
	int xxx, yyy;
	xxx = floatx;
	yyy = floaty;
	switch (news) {
	case 72: floatx--; break;	//上 
	case 80: floatx++; break;	//下 
	case 75: floaty--; break;	//左 
	case 77: floaty++; break;	//右 
	}
	if (floatx == -1) floatx = A - 1; floatx %= A;	//两端穿模处理 
	if (floaty == -1) floaty = B - 1; floaty %= B;

	position(yyy * 2, xxx);
	SetConsoleTextAttribute(handle_out, FORE_GREEN);
	Lump(xxx, yyy);	//删除原位置

	if (map[floatx][floaty] == 'x') {
		position(floaty * 2, floatx);
		printf("  ");
	}

	position(floaty * 2, floatx);
	SetConsoleTextAttribute(handle_out, FORE_BLUE);
	Lump(floatx, floaty);	//更新新位置 
}

//插旗和排雷模式切换 
void Mode() {
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
	CONSOLE_SCREEN_BUFFER_INFO csbi;                        //定义窗口缓冲区信息结构体  
	GetConsoleScreenBufferInfo(handle_out, &csbi);          //获得窗口缓冲区信息
	mode++;
	SetConsoleTextAttribute(handle_out, FORE_BLUE);
	position(floaty * 2, floatx);
	if (mode % 2 == 0) printf("");
	else printf("");

	position(44, 9);
	if (mode % 2 == 0) {
		SetConsoleTextAttribute(handle_out, FORE_BLUE);
		printf("扫雷模式");
	}
	else {
		SetConsoleTextAttribute(handle_out, FORE_RED);
		printf("插旗模式");
	}
}

//该点周围地雷数 
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

//更新地图 
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
	freopen("排名.txt", "r", stdin);
Relife:	//重玩处
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
	CONSOLE_SCREEN_BUFFER_INFO csbi;                        //定义窗口缓冲区信息结构体  
	GetConsoleScreenBufferInfo(handle_out, &csbi);          //获得窗口缓冲区信息

	Hide();		//隐藏光标
	Beginning();//初始化地图
	a = GetTickCount();
	while (1) {
		if (kbhit() != 0) {
			spare = getch();

			//按其他
			if ((spare != (-32)) && (spare != 13) && (spare != ' ')) continue;//跳过 

			//按Enter
			if (spare == 13) {	//确认 
				//排雷
				if (mode % 2 == 0) {
					if (map[floatx][floaty] == '@'&&flag[floatx][floaty] == 0) {
						break;	//触雷
						game = 0;
					}

					if (flag[floatx][floaty] == 1) continue;	//有旗跳过
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

				//插拔旗
				else {

					//不能插旗的地方
					if (map[floatx][floaty] == 'x' || (map[floatx][floaty] > '0'&&map[floatx][floaty] < '9'))
						continue;	//跳过

					//插旗
					if (flag[floatx][floaty] == 0) {
						flagnum++;
						flag[floatx][floaty] = 1;
						position(floaty * 2, floatx);
						SetConsoleTextAttribute(handle_out, FORE_BLUE);
						Lump(floatx, floaty);
					}

					//拔旗 
					else {
						flagnum--;
						flag[floatx][floaty] = 0;
						position(floaty * 2, floatx);
						SetConsoleTextAttribute(handle_out, FORE_BLUE);
						Lump(floatx, floaty);
					}
				}
			}

			//按空格
			if (spare == ' ') Mode();	//切换模式 

			//按方向键 
			if (spare == -32) {
				news = getch();
				Move();	//移动光标
			}
			for (int i = 0; i < A; i++) for (int j = 0; j < B; j++) if (map[i][j] == 'x' || (map[i][j] > '0'&&map[i][j] < '9')) game++;
			if (game == A * B - C + 1) break;
			else game = 1;
			SetConsoleTextAttribute(handle_out, FORE_RED);
			position(44, 5);
			printf("剩余雷数：%d ", C - flagnum);
		}
		else Sleep(10);
		b = GetTickCount();
		SetConsoleTextAttribute(handle_out, FORE_RED);
		position(44, 7);
		printf("用时：");	//用时 
		if ((b - a) / 60000 < 10) printf("0");
		printf("%d:", (b - a) / 60000);
		if (((b - a) / 1000) % 60 < 10) printf("0");
		printf("%d:", ((b - a) / 1000) % 60);
		if (((b - a) / 10) % 100 < 10) printf("0");
		printf("%d", ((b - a) / 10) % 100);
	}
	SetConsoleTextAttribute(handle_out, FORE_RED);
	position(5, 5);
	if (game == 1) printf("游戏结束！");
	else printf("恭喜通关！");
	position(5, 8);
	printf("任意键重玩");
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
//#include<graphics.h>			//图形库
//#include<mmsystem.h>
//#pragma comment(lib,"winmm.lib")		//音频设备接口
//#define N 10  //格子数
//#define M 50  //图片大小
//using namespace std;
//IMAGE image[13];		//存放图片
//int map[N + 2][N + 2];			//存放雷  -1 表示雷
//int gamemodel;
//int win = N * N - 15;
//void StartWindow();		//开始界面
//void normalModel();     //10雷模式
//void BTmodel();			//99雷模式
//void DrawGraph();		//画图形
//int MouseClick();	    //鼠标点击事件
//void loadingPlay(int x, int y);	//运用递归实现点击一大片
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
//	mciSendString(L"open ./风动草.mp3 alias bgm", 0, 0, 0);
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
//	setbkmode(TRANSPARENT);		 //设置背景 透明风格
//	settextstyle(40, 18, L"楷体");
//	while (1) {
//		msg = GetMouseMsg();
//		if (msg.x > 180 && msg.x < 320 && msg.y >250 && msg.y < 290) {
//			settextcolor(RGB(255, 0, 0));		//设置字体颜色
//			outtextxy(180, 250, L"15雷模式");
//		}
//		else if (msg.x > 180 && msg.x < 320 && msg.y >330 && msg.y < 370) {
//			settextcolor(RGB(255, 0, 0));		//设置字体颜色
//			outtextxy(180, 330, L"99雷模式");
//		}
//		else if (msg.x > 180 && msg.x < 320 && msg.y >410 && msg.y < 450) {
//			settextcolor(RGB(255, 0, 0));		//设置字体颜色
//			outtextxy(180, 410, L"退出");
//		}
//		else {
//			settextcolor(RGB(0, 0, 0));		//设置字体颜色
//			outtextxy(180, 250, L"15雷模式");
//			outtextxy(180, 330, L"99雷模式");
//			outtextxy(180, 410, L"退出");
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
//		while (flag < 15) {  //实现埋15颗雷
//			x = rand() % 10 + 1;
//			y = rand() % 10 + 1;
//			if (map[x][y] != -1) {
//				map[x][y] = -1;
//				flag++;
//			}
//		}
//		for (int i = 1; i <= N; i++) {	//扫描数组10X10显示部分 实现显示周围8个格子中雷的数目
//			for (int j = 1; j <= N; j++) {
//				if (map[i][j] != -1) {
//					for (int m = i - 1; m <= i + 1; m++) {//扫描包含该数字的九个格子
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
//				if (MessageBox(hWnd, L"按下确定重玩", L"Lose", MB_OK) == IDOK) break;
//			}
//			if (win == 0) {
//				DrawGraph();
//				if (MessageBox(hWnd, L"按下确定重玩", L"Win", MB_OK) == IDOK) break;
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
//		for (int i = 1; i <= N; i++) {	//扫描数组10X10显示部分
//			for (int j = 1; j <= N; j++) {
//				if (map[i][j] != -1) {
//					for (int m = i - 1; m <= i + 1; m++) {//扫描包含该数字的九个格子
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
//				if (MessageBox(hWnd, L"按下确定重玩", L"Lose", MB_OK) == IDOK) break;
//			}
//			if (win == 0) {
//				DrawGraph();
//				if (MessageBox(hWnd, L"按下确定重玩", L"Lose", MB_OK) == IDOK) break;
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
//			if (i <= 0 || i >= 11 || j <= 0 || j >= 11)  continue; //防止越界
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
