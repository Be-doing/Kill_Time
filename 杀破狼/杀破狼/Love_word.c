#pragma comment(lib,"Winmm.lib")
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<mmsystem.h>
int main()
{
	FILE* fp = fopen("./word.txt","r");
	if (fp == NULL) {
		printf("文件不存在，打开失败！\n");
	}
	char word[100][100] = {0};
	int i = 0;
	while (i < 100)
	{
		fgets(word[i], sizeof(word[i]), fp);
		++i;
	}
	mciSendString("open ./test.mp3 alias yhldca", NULL, 0, NULL);
	mciSendString("play yhldca repeat", NULL, 0, NULL);
	
	int col = 0;
	while (col < 100)
	{
		system("COLOR E4");
		unsigned int row = 0;
		while (row < strlen(word[col]))
		{
		printf("%c",word[col][row]);
		++row;
			if (col < 4)
			{
				Sleep(450);
			}
			else
			{
				Sleep(150);
			}
		}
		//system("CLS");
		//printf("\n");
		++col;
		Sleep(500);
	}
	fclose(fp);
	system("pause");
	return 0;
}