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
		cout << "�������������: ";
		cin >> teamNum;
		if (teamNum < 1 && teamNum > 10 ^ 5)
		{
			cout << "����Ƿ�" << endl;
			return false;
		}
		vector<int> people;
		people.resize(3 * teamNum);
		cout << "������ѡ��˳ƽֵ��" << endl;
		for (int i = 0; i < 3 * teamNum; ++i)//ÿ��3��
		{
			cout << "ѡ��[ " << i << " ] :";
			cin >> people[i];
			if (people[i] < 1 && people[i] > 10 ^ 9)
			{
				cout << "����Ƿ�" << endl;
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