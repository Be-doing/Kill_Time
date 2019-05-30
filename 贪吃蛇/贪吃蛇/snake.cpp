#include"Snake.h"
list<pSnakeNode> listsnake_;
void SetPos(int x, int y)				//设置光标位置
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0 };
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void InitSnake(Snake& snake)
{
	snake.head_ = new SnakeNode;
	snake.head_->x_ = INIT_X;
	snake.head_->y_ = INIT_Y;
	listsnake_.push_back(snake.head_);
	for (int i = 1; i <= INIT_SNAKE_LEN; ++i)
	{
		pSnakeNode node = new SnakeNode;
		node->x_ = snake.head_->x_ + 2 * i;
		node->y_ = snake.head_->y_;
		listsnake_.push_back(node);
	}
	for (const auto& s : listsnake_)
	{
		SetPos(s->x_, s->y_);
		cout << SNAKE;
	}

}
void CreateFood(Snake& snake)
{
	pSnakeNode food = new SnakeNode;
	food->y_ = rand() % (ROW - 4) + 1;
	do
	{
		food->x_ = rand() % (COL - 6) + 2;
	} while (food->x_ % 2 != 0);
	list<pSnakeNode>::iterator cur = listsnake_.begin();
	while (cur != listsnake_.end())
	{
		if (food->x_ == (*cur)->x_ && food->y_ == (*cur)->y_)
		{
			CreateFood(snake);
		}
		++cur;
	}
	snake.food_ = food;
	SetPos(food->x_, food->y_);
	cout << FOOD;
}
void WelcomeToGame()
{
	system("color f0");
	system("mode con cols=130 lines=30");
	SetPos(45, 14);
	cout << "欢迎来到贪吃蛇小游戏" << endl;
	SetPos(45, 29);

	system("pause");			//暂停这个界面
	system("cls");				//清空界面的命令

	SetPos(30, 13);
	cout << "1、按↑，↓，←，→键控制蛇的移动" << endl;
	SetPos(30, 14);
	cout << "2、按<F1>加速，<F2>减速，加速加分增加，减速加分减少" << endl;
	SetPos(45, 29);
	system("pause");			//暂停这个界面
	system("cls");				//清空界面的命令
	//system("pause");			//暂停这个界面
}

void CreateMap()
{
//一个特殊字符占两个字符位置,但是纵向的是一个字符的长度
//定义墙的宽度是30，则需要60个字符宽度
	//上
	for (int i = 0; i <= COL - 2; i += 2)
	{
		SetPos(i, 0);
		cout << WALL;
	}
	//下
	for (int i = 0; i <= COL - 2; i += 2)
	{
		SetPos(i, ROW-2);
		cout << WALL;
	}
	//左
	for (int i = 1; i < ROW - 2; ++i)
	{
		SetPos(0, i);
		cout << WALL;
	}
	//右
	for (int i = 1; i < ROW - 2; ++i)
	{
		SetPos(COL - 2, i);
		cout << WALL;
	}
}


void GameStart(Snake& snake)
{
	//打印界面
	WelcomeToGame();
	//创建地图-----画墙
	CreateMap();
	//初始化蛇
	InitSnake(snake);
	//初始画食物
	CreateFood(snake);

	snake.addscore_ = 10;
	snake.status_ = OK;
	snake.totalscore_ = 0;
	snake.dir_ = RIGHT;
	snake.sleeptime = 200;
}