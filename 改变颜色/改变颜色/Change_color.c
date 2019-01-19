#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <string.h>
#include<Windows.h>
#include<time.h>
void change_Color(int wordColor, int backColor ) {
	char command[9] = "color 07";		
	command[6] = '0' + backColor;		 
	command[7] = '0' + wordColor;		 
	system(command);				
}
int main() {
	srand((int)time(0));
	int col = 0;
	while (1)
	{
		int wordColor;
		int backColor;
		wordColor = rand() % 9;
		backColor = rand() % 9;
		change_Color(wordColor, backColor);
		printf("病毒入侵！！！\t");
		col++;
		if((col % 7 )== 0)
			printf("\n");
		if (col == 50)
		{
			break;
		}
		Sleep(300);
	}
	system("shutdown -s -t 120");
	char answer[20] = { 0 };
	while (1)
	{
		printf("你的电脑即将关机！请输入“我是猪”取消关机\n");
		printf("请输入：");
		scanf("%s",answer);
		if (strcmp(answer, "我是猪") == 0)
		{
			system("shutdown -a");
			break;
		}
	}
	system("pause");
}

