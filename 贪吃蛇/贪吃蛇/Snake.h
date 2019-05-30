#pragma once
#include<iostream>
#include<Windows.h>
#include<time.h>
#include<list>
using namespace std;

#define COL 100	//宽
#define ROW 30//长
#define FOOD "★"
#define WALL "㊣"
#define SNAKE "■"
#define INIT_X 20
#define INIT_Y 20
#define INIT_SNAKE_LEN 4
 struct SnakeNode	//蛇身结点
{

		int x_;
		int y_;
 };			//结点
		//结点地址
typedef SnakeNode* pSnakeNode;

enum Direction		//定义方向
{
	UP = 1,				//上下左右
	DOWN,
	LEFT,
	RIGHT
};

enum GameStatus		//游戏状态
{
	OK,						//正在游戏
	NORMAL_END,		//正常退出
	KILL_BY_WALL,		//撞墙结束
	KILL_BY_SELF		//撞向自己结束
};
 struct Snake		//维护蛇身整体数据
{
	pSnakeNode head_;				//蛇头的地址
	pSnakeNode food_;				//食物的地址
	int totalscore_;						//总分数
	int addscore_;						//增加的分数
	int sleeptime;							//速度，每次减速，就是睡眠了几微秒
	enum Direction dir_;				//方向
	enum GameStatus status_;		//当前状态
	
};
typedef Snake* pSnake;


void GameStart(Snake& snake);
void WelcomeToGame();
void CreateMap();
void InitSnake(Snake& snake);
void CreateFood(Snake& snake);

void GameRun();

void GameEnd();





