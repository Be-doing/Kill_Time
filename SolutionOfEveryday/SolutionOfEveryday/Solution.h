#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

//ţţ�ٰ���һ�α�̱���, �μӱ�������3*n��ѡ��, ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������, һ�����n������, ��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
//���� :
//һ������������Ա��ˮƽֵ�ֱ���3, 3, 3.��ô�����ˮƽֵ��3
//һ������������Ա��ˮƽֵ�ֱ���3, 2, 3.��ô�����ˮƽֵ��3
//һ������������Ա��ˮƽֵ�ֱ���1, 5, 2.��ô�����ˮƽֵ��2
//Ϊ���ñ������п���, ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
//��������ʾ :
//���ţţ��6����Ա���ֵ���������
//�������Ϊ :
//team1: {1, 2, 5}, team2 : {5, 5, 8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
//	���������Ϊ :
//	team1 : {2, 5, 8}, team2 : {1, 5, 5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
//	û�б��ܺ�Ϊ10����ķ���, �������10.
#define IN_LEN_MAX 500000
#define IN_NUM_MAX 1000000000
#include<algorithm>
class Day1
{
public:
	//˼·���Ƚ������������������ѡ�����ĺ͵ڶ������������С������ͬ��һ��ѡ��
	//������ÿ�������м������
	bool SolutionOne()
	{
		int teamNum = 2;

		cout << "�������������: ";
		cin >> teamNum;
		if (teamNum < 1 && teamNum > IN_LEN_MAX)
		{
			cout << "����Ƿ�" << endl;
			return false;
		}
		vector<int> personNum;
		personNum.resize(3 * teamNum);
		cout << "������ѡ��˳ƽֵ��" << endl;
		for (int i = 0; i < 3 * teamNum; ++i)//ÿ��3��
		{
			cout << "ѡ��[ " << i << " ] :";
			cin >> personNum[i];
			if (personNum[i] < 1 && personNum[i] > IN_NUM_MAX)
			{
				cout << "����Ƿ�" << endl;
				return false;
			}
		}
		size_t size = personNum.size();
		//Sort(personNum, size);
		sort(personNum.begin(), personNum.end());//��������
		long long sum = 0;
		//int mid = teamNum;
		for (size_t mid = teamNum; mid <= size - 2; mid += 2)
		{
			sum += personNum[mid];
		}
		cout << sum << endl;
		return true;
	}
	//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
	//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
	void SolutionTwo()
	{
		string src_;
		string des_;
		getline(cin, src_);
		getline(cin, des_);

		int hash[256] = { 0 };
		int srcLen_ = src_.size();
		int desLen_ = des_.size();

		//ascii����Ӧ
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




class Day2
{
public:
		//1���ѵ�һ��ȡ������Ϊ��һ�����еĿ�ʼ����ڶ������Ƚϣ�ȷ��������ݼ���ϵ
		//2���ٰѵڶ�����ȡ������Ϊ��һ�����еĵڶ�������
		//3��ȡ�������������ڶ������Ƚϣ�����͵�һ������ϵ��ͬ�������һ�����з����ؿ�һ�����С�
	int SolutionOne()
	{
		int num = 0;
		scanf("%d", &num);
		if (num < 1 || num > IN_LEN_MAX)
		{
			printf("����Ƿ�\n");
			return -1;
		}
		//int num = 6;
		int* arr = new int[num + 1];
		for (int i = 0; i < num; ++i)
		{
			scanf("%d", &arr[i]);//1 2 3 2 2 1
			if (arr[i] < 1 || arr[i] > IN_NUM_MAX)
			{
				printf("����Ƿ�\n");
				return -1;
			}
		}
		arr[num] = 0;
		int flag = 0;
		int count = 0;
		while (flag < num)
		{
			if (arr[flag] < arr[flag + 1])
			{
				while (flag < num && arr[flag] <= arr[flag + 1])
				{
					++flag;
				}
				++count;
				++flag;
			}//1 2 1 2 1 2 1 2 1
			else if (arr[flag + 1] == arr[flag])
			{
				++flag;
			}
			else //(arr[flag-1] > arr[flag])
			{
				while (flag < num && arr[flag] >= arr[flag + 1])
				{
					++flag;
				}
				++count;
				++flag;
			}
		}
		return count;
	}
		//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
		//ÿ�������������1������������ I like beijing.�����������Ȳ�����100
		//�����������֮����ַ���, �Կո�ָ�
	void SolutionTwo()
	{
		string strRes;
		string strIn;
		cin >> strIn;
		while (cin >> strRes)
		{
			strIn = strRes + " " + strIn;
		}
		cout << strIn;
	}

};





class Day3
{
public:
	//����һ���ַ���str������ַ���str�е�����������ִ�
	//abcd12345ed125ss123456789
	//123456789
	int SolutionOne()
	{
	}
	//����n��������������ִ������ڵ������鳤��һ�������
	//3 9 3 2 5 6 7 3 2 3 3 3
	//3
	void SolutionTwo()
	{
		string strRes;
		string strIn;
		cin >> strIn;
		while (cin >> strRes)
		{
			strIn = strRes + " " + strIn;
		}
		cout << strIn;
	}

};






class Day4
{
public:
	void SolutionOne()
	{
		int A;
		int B;

		vector<int> v_in;
		int num;
		int i = 0;
		while (i < 4)
		{
			cin >> num;
			v_in.push_back(num);
			++i;
		}
		A = (v_in[0] + v_in[2]) / 2;
		B = v_in[2] - A;
		if ((B - v_in[1]) == (v_in[3] - B))
		{
			cout << A << " " << B << " " << v_in[3] - B;
		}
		else
		{
			cout << "NO";
		}
	}
	void  SolutionTwo(int num, int ra)
	{
		char re;
		stack<char> result;
		while (num >= ra)
		{
			int res = num % ra;
			if (res > 9)
			{
				re = 17 + res - 10 + '0';
			}
			else
			re = (res + '0');
			num /= ra;
			result.push(re);
		}
		if (num > 9)
		{
			re = 17 + num - 10 + '0';
		}
		else
		{
			re = (num + '0');
		}
		result.push(re);

		while (!result.empty())
		{
			cout << result.top();
			result.pop();
		}
	}
};