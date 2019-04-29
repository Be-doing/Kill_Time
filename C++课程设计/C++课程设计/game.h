#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;
#define ROW 9//��ͼ����
#define COL 9//��ͼ����
#define ROWPLUS 20
#define COLPLUS 20
#define MINE_COUNT 10 //���׸��� 
#define MINE_COUNT_PLUS 20
char mine_map[ROW + 2][COL + 2];//�����ͼ��+2��ʾ�߿�ͳ��������
char show_map[ROW + 2][COL + 2];//չʾ��ͼ��+2��ʾ�߿�ͳ��������
char mine_map_plus[ROWPLUS + 2][COLPLUS + 2];
char show_map_plus[ROWPLUS + 2][COLPLUS + 2];
//class MineClearance
//{
//	MineClearance()
//	{
//
//	}
//
//private:
//	vector<vector<char>> mine_map_;
//	vector<vector<char>> show_map_;
//};

int LevelGame()
{
	cout << "#####  ��ѡ���Ѷ�  ######" << endl;
	cout << "##### 1.9 * 9 ���� ######" << endl;
	cout << "##### 2.20 * 20 ���� ####" << endl;
	cout << "###ף����Ϸ���~   ^_^###" << endl;
	int choice = 0;
	while (1)
	{
		cout << "����������ѡ��";
		cin >> choice;
		if (choice < 1 || choice>2) {
			cout << "������������⣬���������룡" << endl;
			continue;
		}
		break;
	}
	return choice;
}
int StartGame()
{
	cout << "#######MineClearance########" << endl;
	cout << "#######>>>1.Start    ########" << endl;
	cout << "#######>>>2.Exit      #######" << endl;
	cout << ">>>����������ѡ��";
	int choice = 0;
	while (1)
	{
		cin >> choice;
		if (choice < 1 || choice>2) {
			cout << "������������⣬���������룡" << endl;
			cout << "��������������ѡ��" << endl;
			continue;
		}
		break;
	}
	return choice;
}
void PrintMap(char map[ROW + 2][COL + 2])
{
	cout << "   ";
	for (int col = 1; col <= COL; col++) 
	{
		cout << col << "  ";
	}
	cout << endl;
	for (int col = 1; col <= COL; col++) 
	{
		cout << "----";
	}
	cout << endl;
	for (int row = 1; row <= ROW; row++)
	{
		cout <<  row << " |";
		for (int col = 1; col <= COL; col++) 
		{
			cout << map[row][col] << "  ";
		}
		cout << endl;
	}
}
void init_arr(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2]) 
{
	memset(mine_map, '0', (ROW + 2)*(COL + 2));
	memset(show_map, '*', (ROW + 2)*(COL + 2));
	int mine_count = MINE_COUNT;
	srand(time(0));
	while (mine_count > 0) 
	{
		int row = rand() % 9 + 1;
		int col = rand() % 9 + 1;
		if (mine_map[row][col] == '0') 
		{
			mine_map[row][col] = '1';
			--mine_count;
		}
	}
}
////��ӡplus������
//void print_map_plus(char map[ROWPLUS + 2][COLPLUS + 2]) {
//	printf("    ");
//	for (int col = 1; col <= COLPLUS; col++) {
//		printf(" %02d", col);
//	}
//	printf("\n");
//	for (int col = 0; col <= COLPLUS; col++) {
//		printf("---");
//	}
//	printf("\n");
//	for (int row = 1; row <= ROWPLUS; row++) {
//		printf(" %02d|", row);
//		for (int col = 1; col <= COLPLUS; col++) {
//			printf(" %c ", map[row][col]);
//		}
//		printf("\n");
//	}
//}
//
////��ʾ��Χ����
//void prompt_mine_count(char map[ROW + 2][COL + 2], char mmap[ROW + 2][COL + 2], int row, int col) {
//	int mine_count = (mine_map[row - 1][col - 1] - '0') + (mine_map[row - 1][col] - '0') + (mine_map[row - 1][col + 1] - '0')//��һ��
//		+
//		(mine_map[row][col - 1] - '0') + (mine_map[row][col + 1] - '0') +//�ڶ���
//		(mine_map[row + 1][col - 1] - '0') + (mine_map[row + 1][col] - '0') + (mine_map[row + 1][col + 1] - '0');//������
//	show_map[row][col] = '0' + mine_count;
//}
////plus��ʾ����
//void prompt_mine_count_plus(char map[ROWPLUS + 2][COLPLUS + 2], char mmap[ROWPLUS + 2][COLPLUS + 2], int row, int col) {
//	int mine_count = (mine_map_plus[row - 1][col - 1] - '0') + (mine_map_plus[row - 1][col] - '0') + (mine_map_plus[row - 1][col + 1] - '0')//��һ��
//		+
//		(mine_map_plus[row][col - 1] - '0') + (mine_map_plus[row][col + 1] - '0') +//�ڶ���
//		(mine_map_plus[row + 1][col - 1] - '0') + (mine_map_plus[row + 1][col] - '0') + (mine_map_plus[row + 1][col + 1] - '0');//������
//	show_map_plus[row][col] = '0' + mine_count;
//}
////�����ʼ������֪����
//void init_arr(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2]) {
//	memset(mine_map, '0', (ROW + 2)*(COL + 2));
//	memset(show_map, '*', (ROW + 2)*(COL + 2));
//	int mine_count = MINE_COUNT;
//	srand(time(0));
//	while (mine_count > 0) {
//		int row = rand() % 9 + 1;
//		int col = rand() % 9 + 1;
//		if (mine_map[row][col] == '0') {
//			mine_map[row][col] = '1';
//			--mine_count;
//		}
//	}
//}
////PLUS�����ʼ��
//void init_arr_plus(char mine_map_plus[ROWPLUS + 2][COLPLUS + 2], char show_map_plus[ROWPLUS + 2][COLPLUS + 2]) {
//	memset(mine_map_plus, '0', (ROWPLUS + 2)*(COLPLUS + 2));
//	memset(show_map_plus, '*', (ROWPLUS + 2)*(COLPLUS + 2));
//	int mine_count = MINE_COUNT_PLUS;
//	srand(time(0));
//	while (mine_count > 0) {
//		int row = rand() % 9 + 1;
//		int col = rand() % 9 + 1;
//		if (mine_map_plus[row][col] == '0') {
//			mine_map_plus[row][col] = '1';
//			--mine_count;
//		}
//	}
//}
//
//void to_game() {
//	//���ǵ��׶��㷽����
//	int not_mine_count = 0;
//	//��ʼ������
//	init_arr(mine_map, show_map);
//	//��ӡչʾ��ͼ
//	print_map(show_map);
//	//��ʼ��Ϸ
//	while (1) {
//		int row = 0;
//		int col = 0;
//		//��ʾ�û�����
//		printf("������ª��������Ҫ���������꣨�� �У���");
//		scanf("%d %d", &row, &col);
//		//���кϷ��ж�
//		if (row<1 || row>ROW || col<1 || col>ROW) {
//			printf("����������곬����Χ�����������룡");
//			continue;
//		}
//		//�ж��Ƿ����
//		//���ף���Ϸ����
//		if (mine_map[row][col] == '1') {
//			printf("�������ˣ���Ϸ������\n");
//			print_map(mine_map);
//			break;
//		}
//		//û���ף��Ƿ�ʤ����Ϊʤ����ʾ��Χ����
//		//ʤ�����˳�ѭ����
//		++not_mine_count;
//		if (not_mine_count == ROW * COL - MINE_COUNT) {
//			printf("�����ף�ɨ�׳ɹ���\n");
//			print_map(mine_map);
//			break;
//		}
//		//û��ʤ������ʾ��Χ����
//		prompt_mine_count(show_map, mine_map, row, col);
//		print_map(show_map);
//	}
//}
//void to_game_plus() {
//	//���ǵ��׶��㷽����
//	int not_mine_count = 0;
//	//��ʼ������
//	init_arr_plus(mine_map_plus, show_map_plus);
//	//��ӡչʾ��ͼ
//	print_map_plus(show_map_plus);
//	//��ʼ��Ϸ
//	while (1) {
//		int row = 0;
//		int col = 0;
//		//��ʾ�û�����
//		printf("������ª��������Ҫ���������꣨�� �У���");
//		scanf("%d %d", &row, &col);
//		//���кϷ��ж�
//		if (row<1 || row>ROWPLUS || col<1 || col>ROWPLUS) {
//			printf("����������곬����Χ�����������룡");
//			continue;
//		}
//		//�ж��Ƿ����
//		//���ף���Ϸ����
//		if (mine_map_plus[row][col] == '1') {
//			printf("�������ˣ���Ϸ������\n");
//			print_map_plus(mine_map_plus);
//			break;
//		}
//		//û���ף��Ƿ�ʤ����Ϊʤ����ʾ��Χ����
//		//ʤ�����˳�ѭ����
//		++not_mine_count;
//		if (not_mine_count == ROWPLUS * COLPLUS - MINE_COUNT_PLUS) {
//			printf("�����ף�ɨ�׳ɹ���\n");
//			print_map_plus(mine_map_plus);
//			break;
//		}
//		//û��ʤ������ʾ��Χ����
//		prompt_mine_count_plus(show_map_plus, mine_map_plus, row, col);
//		print_map_plus(show_map_plus);
//	}
//}
//
//void start_game() {
//	while (1) {
//		int choice = man_select();
//		if (choice == 0) {
//			break;
//		}
//		int choice2 = level_game();
//		if (choice2 == 1) {
//			to_game();
//		}
//		else {
//			to_game_plus();
//		}
//	}
//}
