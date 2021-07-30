#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void meun()
{
	printf("*********************************\n");
	printf("*********************************\n");
	printf("***********  1. play  ***********\n");
	printf("***********  0. exit  ***********\n");
	printf("*********************************\n");
	printf("*********************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化数组
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印数组
	//布置雷
	SetMine(mine, ROW, COL); 
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//排雷
	FindBoard(mine, show, ROW, COL);
	DisplayBoard(show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		meun();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}

	} while (input);


	return 0;
}