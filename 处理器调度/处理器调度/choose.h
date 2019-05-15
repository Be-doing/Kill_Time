#pragma once
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int timeslice = 1;//时间片

typedef struct PCB
{
	int pid_;
	int level_;
	PCB* next;
	string status_;
	int runtime_;
}PCB;

void mune()
{
	cout << "pid" << "\t" << "level" << "\t" << "runtime" << "\t" << "status" << endl;
	cout << "===========================================" << endl;
}
void Create(PCB pcb[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "请输入process[ " << i << " ]的运行时间：";
		cin >> pcb[i].runtime_;
		pcb[i].pid_ = i;
		pcb[i].level_ = rand() % size;
		pcb[i].status_ = "R";
		pcb[i].next = nullptr;
	}
}
void Print(PCB pcb [], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << pcb[i].pid_ << "\t" << pcb[i].level_ << "\t" << pcb[i].runtime_ << "\t" << pcb[i].status_ << endl;
	}
		
}
void Sort(PCB pcb[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < size - i; ++j)
		{
			if (pcb[j].level_ < pcb[j + 1].level_)
			{
				swap(pcb[j], pcb[j + 1]);
			}
		}
	}
}
void Connect(PCB pcb[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		pcb[i].next = &pcb[i + 1];
	}
	pcb[size - 1].next = nullptr;
}
queue<PCB> pushPcb(PCB pcb[], int size)
{
	queue<PCB> qPcb;
	for (int i = 0; i < size; ++i)
	{
		qPcb.push(pcb[i]);
	}
	return qPcb;
}
int Sumtime(PCB pcb[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += pcb[i].runtime_;
	}
	return sum;
}
void Run(PCB pcb[], int size)
{
	int sum = Sumtime(pcb, size);
	for (int toRun = 0; toRun < sum; toRun += timeslice)
	{
		int runover = 0;
		Connect(pcb, size);
		--pcb[0].level_;
		while (runover < size)
		{
			if (pcb[runover].runtime_ > 0)
			{
				pcb[runover].runtime_ -= timeslice;
				if (pcb[runover].runtime_ <= 0)
				{
					pcb[runover].status_ = 'E';
				}
				break;
			}
			++runover;
		}
		Sort(pcb, size);
		mune();
		Print(pcb,size);
	}
}