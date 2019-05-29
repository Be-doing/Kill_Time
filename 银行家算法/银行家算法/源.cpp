#include <string.h>
#include <iostream>
#include<vector>
using namespace std;


int ALL_RESOURCE[3] = { 9,3,6 };//������Դ����Ŀ�ܺ�


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
		cout << "       ��Դ0" << "     ��Դ1" << "     ��Դ2" << endl;
		for (i = 0; i < PROCESS; i++)
		{
			cout << "����p" << i << ":    ";
			for (j = 0; j < SPECIENUM; j++)
			{
				cout << max_[i][j] << "       ";
			}
			cout << endl;
		}


		cout << "allocation_: "<< endl;
		cout << "       ��Դ0" << "     ��Դ1" << "     ��Դ2" << endl;
		for (i = 0; i < PROCESS; i++)
		{
			cout << "����p" << i << ":    ";
			for (j = 0; j < SPECIENUM; j++)cout << allocation_[i][j] << "       ";
			cout << endl;
		}
		cout << endl;
		cout << "need_:" << endl << endl;
		cout << "       ��Դ0" << "     ��Դ1" << "    ��Դ2" << endl;
		for (i = 0; i < PROCESS; i++)
			for (i = 0; i < PROCESS; i++)
			{
				cout << "����p" << i << ":   ";
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
	void Distribution(int k) //������Դ
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
	void Regain(int k) //�ָ��ֳ�
	{
		int j;
		for (j = 0; j < SPECIENUM; j++)
		{
			available_[j] = available_[j] + request[j];
			allocation_[k][j] = allocation_[k][j] - request[j];
			need_[k][j] = need_[k][j] + request[j];
		}
	}

	bool Check(int s) //����Ƿ�ȫ
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
					cout << " ϵͳ����ȫ!!! ������Դ���벻�ɹ�!!!" << endl;
					cout << endl;
					return false;
				}
			}
		}
		cout << endl;
		cout << " ����ȫ�Լ�飬ϵͳ��ȫ�����η���ɹ���" << endl;
		size_t size = safepro.size();
		cout << "��ȫ����Ϊ��";
		Print(safepro, size);//��ӡ��ȫ����
		cout << endl;
		return false;
	}
	void SetBank()   //���м��㷨����
	{
		int i = 0, j = 0;
		char flag = 'Y';
		while (flag == 'Y' || flag == 'y')
		{
			i = -1;
			while (i < 0 || i >= PROCESS)//����������ж�
			{
				cout << " ��������������Դ�Ľ��̺ţ���P0��P" << PROCESS - 1 << "������������!��:";
				cout << "P";
				cin >> i;
				if (i < 0 || i >= PROCESS)
				{
					cout << " ����Ľ��̺Ų����ڣ���������!" << endl;
				}
				save.push_back(i);
			}
			cout << " ���������P" << i << "�������Դ��:" << endl;
			for (j = 0; j < SPECIENUM; j++)
			{
				cout << " ��Դ" << j << ": ";
				cin >> request[j];
					if (request[j] > available_[j]) //���������Դ�����ڿ�����Դ��
					{
						cout << " ����P" << i << "�������Դ������ϵͳ����" << j << "����Դ����Դ��!";
						cout << "���벻��������!������ѡ��!" << endl << endl;
						flag = 'N';
						break;
					}
			}
			if (flag == 'Y' || flag == 'y')
			{
				Distribution(i); //����changdata(i)�������ı���Դ��
				if (Check(i)) //��ϵͳ��ȫ
				{
					Show();   //�����Դ�������
				}
				else       //��ϵͳ����ȫ
				{
					Regain(i); //����Check(i)�������ָ���Դ��
					Show(); //�����Դ�������
				}
					
			}
			else      //��flag=N||flag=n
				Show();
			cout << endl;
			cout << " �Ƿ�������м��㷨��ʾ,��'Y'��'y'������,��'N'��'n'���˳���ʾ: ";
			cin >> flag;
		}
	}

	int max_[PROCESS][SPECIENUM] = { {3,2,2},{6,1,3},{3,1,4},{4,2,2} };//PROCESS������SPECIENUM����Դ���������
	int available_[SPECIENUM] = { 0 }; //ϵͳʣ�µĿ�����Դ��
	int allocation_[PROCESS][SPECIENUM] = { {1,0,0},{6,1,2},{2,1,1},{0,0,2} };// PROCESS������SPECIENUM����Դ�Ѿ�����
	int need_[PROCESS][SPECIENUM] = { 0 };//����
	int request[SPECIENUM] = { 0 };//����
	vector<int> save;
};

int main()
{
	Bank bank;
	int i = 0, j = 0, p;
	//��ʼ����Դ����
	for (j = 0; j < SPECIENUM; j++)
	{
		p = ALL_RESOURCE[j];
		for (i = 0; i < PROCESS; i++)
		{
			p = p - bank.allocation_[i][j];//��ȥ�Ѿ���ռ�ݵ���Դ
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
	cout << "��ȫ������Ϊ��";
	Print(bank.save, size);
	system("pause");
	return 0;
}
