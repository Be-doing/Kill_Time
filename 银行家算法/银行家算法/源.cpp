#include <string.h>
#include <iostream>
#include<vector>
using namespace std;


int ALL_RESOURCE[3] = { 9,3,6 };//各种资源的数目总和


#define PROCESS 4
#define SPECIENUM 3
void Print(vector<int> v, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		cout << "p[ " << v[i] << " ]";
		if (i != size - 1)
		{
			cout << "->";
		}
	}
	cout << endl;
}
class Bank
{
public:
	Bank()
	{}
	void Show()
	{
		int i, j;
		cout << "max_: " << endl << endl;
		cout << "       资源0" << "     资源1" << "     资源2" << endl;
		for (i = 0; i < PROCESS; i++)
		{
			cout << "进程p" << i << ":    ";
			for (j = 0; j < SPECIENUM; j++)
			{
				cout << max_[i][j] << "       ";
			}
			cout << endl;
		}


		cout << "allocation_: "<< endl;
		cout << "       资源0" << "     资源1" << "     资源2" << endl;
		for (i = 0; i < PROCESS; i++)
		{
			cout << "进程p" << i << ":    ";
			for (j = 0; j < SPECIENUM; j++)cout << allocation_[i][j] << "       ";
			cout << endl;
		}
		cout << endl;
		cout << "need_:" << endl << endl;
		cout << "       资源0" << "     资源1" << "    资源2" << endl;
		for (i = 0; i < PROCESS; i++)
			for (i = 0; i < PROCESS; i++)
			{
				cout << "进程p" << i << ":   ";
				for (j = 0; j < SPECIENUM; j++)cout << need_[i][j] << "        ";;
				cout << endl;
			}
		cout << endl;
		cout << "available_:";
		cout << " [";
		for (j = 0; j < SPECIENUM; j++)cout << " " << available_[j];
		cout << " ]";
		cout << endl;
	}
	void Distribution(int k) //分配资源
	{
		int j;
		for (j = 0; j < SPECIENUM; j++)
		{
			available_[j] = available_[j] - request[j];
			allocation_[k][j] = allocation_[k][j] + request[j];
			need_[k][j] = need_[k][j] - request[j];
			available_[j] = available_[j] + allocation_[k][j];
		}
		
	}
	void Regain(int k) //恢复现场
	{
		int j;
		for (j = 0; j < SPECIENUM; j++)
		{
			available_[j] = available_[j] + request[j];
			allocation_[k][j] = allocation_[k][j] - request[j];
			need_[k][j] = need_[k][j] + request[j];
		}
	}

	bool Check(int s) //检查是否安全
	{
		int WORK, FINISH[PROCESS];
		int i, j, k = 0;
		for (i = 0; i < PROCESS; i++)
		{
			FINISH[i] = false;
		}
		vector<int> safepro;
		for (j = 0; j < SPECIENUM; j++)
		{
			WORK = available_[j];
			i = s;
			do
			{
				if (FINISH[i] == false && need_[i][j] <= WORK)
				{
					WORK = WORK + allocation_[i][j];
					FINISH[i] = true;
					safepro.push_back(i);
					i = 0;
				}
				else
				{

					i++;
				}
			} while (i < PROCESS);

			for (i = 0; i < PROCESS; i++)
			{
				if (FINISH[i] == false)
				{
					cout << endl;
					cout << " 系统不安全!!! 本次资源申请不成功!!!" << endl;
					cout << endl;
					return false;
				}
			}
		}
		cout << endl;
		cout << " 经安全性检查，系统安全，本次分配成功。" << endl;
		size_t size = safepro.size();
		cout << "安全序列为：";
		Print(safepro, size);//打印安全序列
		cout << endl;
		return false;
	}
	void SetBank()   //银行家算法主体
	{
		int i = 0, j = 0;
		char flag = 'Y';
		while (flag == 'Y' || flag == 'y')
		{
			i = -1;
			while (i < 0 || i >= PROCESS)//对输入进行判断
			{
				cout << " 请输入需申请资源的进程号（从P0到P" << PROCESS - 1 << "，否则重输入!）:";
				cout << "P";
				cin >> i;
				if (i < 0 || i >= PROCESS)
				{
					cout << " 输入的进程号不存在，重新输入!" << endl;
				}
				save.push_back(i);
			}
			cout << " 请输入进程P" << i << "申请的资源数:" << endl;
			for (j = 0; j < SPECIENUM; j++)
			{
				cout << " 资源" << j << ": ";
				cin >> request[j];
					if (request[j] > available_[j]) //若请求的资源数大于可用资源数
					{
						cout << " 进程P" << i << "申请的资源数大于系统可用" << j << "类资源的资源量!";
						cout << "申请不合理，出错!请重新选择!" << endl << endl;
						flag = 'N';
						break;
					}
			}
			if (flag == 'Y' || flag == 'y')
			{
				Distribution(i); //调用changdata(i)函数，改变资源数
				if (Check(i)) //若系统安全
				{
					Show();   //输出资源分配情况
				}
				else       //若系统不安全
				{
					Regain(i); //调用Check(i)函数，恢复资源数
					Show(); //输出资源分配情况
				}
					
			}
			else      //若flag=N||flag=n
				Show();
			cout << endl;
			cout << " 是否继续银行家算法演示,按'Y'或'y'键继续,按'N'或'n'键退出演示: ";
			cin >> flag;
		}
	}

	int max_[PROCESS][SPECIENUM] = { {3,2,2},{6,1,3},{3,1,4},{4,2,2} };//PROCESS个进程SPECIENUM类资源最大需求量
	int available_[SPECIENUM] = { 0 }; //系统剩下的可用资源数
	int allocation_[PROCESS][SPECIENUM] = { {1,0,0},{6,1,2},{2,1,1},{0,0,2} };// PROCESS个进程SPECIENUM类资源已经分配
	int need_[PROCESS][SPECIENUM] = { 0 };//需求
	int request[SPECIENUM] = { 0 };//请求
	vector<int> save;
};

int main()
{
	Bank bank;
	int i = 0, j = 0, p;
	//初始化资源数量
	for (j = 0; j < SPECIENUM; j++)
	{
		p = ALL_RESOURCE[j];
		for (i = 0; i < PROCESS; i++)
		{
			p = p - bank.allocation_[i][j];//减去已经被占据的资源
			bank.available_[j] = p;
			if (bank.available_[j] < 0)
				bank.available_[j] = 0;
		}
	}
	for (i = 0; i < PROCESS; i++)
	{
		for (j = 0; j < SPECIENUM; j++)
		{
			bank.need_[i][j] = bank.max_[i][j] - bank.allocation_[i][j];
		}
	}
	bank.Show();
	bank.SetBank();
	size_t size = bank.save.size();
	cout << "安全性序列为：";
	Print(bank.save, size);
	system("pause");
	return 0;
}
