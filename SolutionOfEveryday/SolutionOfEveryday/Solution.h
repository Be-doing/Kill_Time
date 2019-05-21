#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//牛牛举办了一次编程比赛, 参加比赛的有3*n个选手, 每个选手都有一个水平值a_i.现在要将这些选手进行组队, 一共组成n个队伍, 即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//例如 :
//一个队伍三个队员的水平值分别是3, 3, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是3, 2, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是1, 5, 2.那么队伍的水平值是2
//为了让比赛更有看点, 牛牛想安排队伍使所有队伍的水平值总和最大。
//如样例所示 :
//如果牛牛把6个队员划分到两个队伍
//如果方案为 :
//team1: {1, 2, 5}, team2 : {5, 5, 8}, 这时候水平值总和为7.
//	而如果方案为 :
//	team1 : {2, 5, 8}, team2 : {1, 5, 5}, 这时候水平值总和为10.
//	没有比总和为10更大的方案, 所以输出10.
#define TEAMNUMMAX 500000
#define PERSONLEVEL 1000000000
#include<algorithm>
class Day1
{
public:
	//思路，先将队伍的人数进行排序，选择最大的和第二大的数，加最小的数。同理一次选择
	//最后加上每个队伍中间的数。
	void Sort(vector<int>& v, size_t size)
	{
		for (size_t i = 1; i < size; ++i)
		{
			for (size_t j = 0; j < size - i; ++j)
			{
				if (v[j] < v[j + 1])
				{
					swap(v[j], v[j + 1]);
				}
			}
		}
	}
	bool SolutionOne()
	{
		int teamNum = 2;

		cout << "请输入队伍数量: ";
		cin >> teamNum;
		if (teamNum < 1 && teamNum > TEAMNUMMAX)
		{
			cout << "输入非法" << endl;
			return false;
		}
		vector<int> personNum;
		personNum.resize(3 * teamNum);
		cout << "请输入选手顺平值：" << endl;
		for (int i = 0; i < 3 * teamNum; ++i)//每队3人
		{
			cout << "选手[ " << i << " ] :";
			cin >> personNum[i];
			if (personNum[i] < 1 && personNum[i] > PERSONLEVEL)
			{
				cout << "输入非法" << endl;
				return false;
			}
		}
		size_t size = personNum.size();
		//Sort(personNum, size);
		sort(personNum.begin(), personNum.end());//递增排序
		long long sum = 0;
		//int mid = teamNum;
		for (size_t mid = teamNum; mid <= size - 2; mid += 2)
		{
			sum += personNum[mid];
		}
		cout << sum << endl;
		return true;
	}

	//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
	//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
	void SolutionTwo()
	{
		string src_;
		string des_;
		getline(cin, src_);
		getline(cin, des_);

		int hash[256] = { 0 };
		int srcLen_ = src_.size();
		int desLen_ = des_.size();

		//ascii码表对应
		for (int i = 0; i < desLen_; ++i)
		{
			hash[des_[i]]++;
		}
		string res;
		for (int i = 0; i < srcLen_; ++i)
		{
			if (hash[src_[i]] == 0)
			{
				res += src_[i];
			}
		}
		cout << res;
	}
};
class Solution2
{
public:
	int Programe1()
	{
		int num = 0;
		printf("数字个数（数组长度）：");
		scanf("%d", &num);
		if (num < 1 || num > 100000)
		{
			printf("输入非法\n");
			return -1;
		}

		//int num = 6;
		int* arr = new int[num];
		printf("输入数据（空格隔开）：");
		for (int i = 0; i < num; ++i)
		{
			scanf("%d", &arr[i]);//1 2 3 2 2 1
			if (arr[i] < 1 || arr[i] > 1000000000)
			{
				printf("输入非法\n");
				return -1;
			}
		}

		//int arr[6] = { 1,2,3,2,2, 1};
		//只有一个数或者两个数的数组，要么递增要么递减
		if (num == 1 || num == 2)
		{
			return 1;
		}


		int flag = 1;		//标记每个子序列是递增的还是递减的
		int count = 1;
		//除上面的情况外,数组的长度是大于2的。
		//如果一个数大于后面的数，flag置1，向后执行，否则++cout；flag置为2，向后执行否则++count
		if (arr[0] < arr[1])
		{
			flag = 1;
		}
		else
		{
			flag = 2;
		}
		for (int i = 1; i < num; ++i)
		{
			if (flag == 2 && arr[i] < arr[i + 1])
			{
				flag = 1;
				++count;
			}
			else if (flag == 1 && arr[i] > arr[i + 1])
			{
				flag = 2;
				++count;
			}
		}
		return count;
	}
};