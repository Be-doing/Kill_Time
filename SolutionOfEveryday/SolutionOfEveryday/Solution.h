#pragma once

#include<iostream>
#include<vector>
using namespace std;

class Solution2
{
public:
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
	bool Programe2()
	{
		int teamNum = 0;
		int sum = 0;
		cout << "请输入队伍数量: ";
		cin >> teamNum;
		if (teamNum < 1 && teamNum > 10 ^ 5)
		{
			cout << "输入非法" << endl;
			return false;
		}
		vector<int> people;
		people.resize(3 * teamNum);
		cout << "请输入选手顺平值：" << endl;
		for (int i = 0; i < 3 * teamNum; ++i)//每队3人
		{
			cout << "选手[ " << i << " ] :";
			cin >> people[i];
			if (people[i] < 1 && people[i] > 10 ^ 9)
			{
				cout << "输入非法" << endl;
				return false;
			}
		}
		size_t size = people.size();
		Sort(people, size);

		int mid = teamNum;
		for (int i = 0; i < teamNum; ++i)
		{
			sum += people[mid];
			++mid;
		}
		cout << sum << endl;
	}
};