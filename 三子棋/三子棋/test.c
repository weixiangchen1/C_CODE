#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}

void game()
{
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//玩家下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (Iswin(board, ROW, COL) != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (Iswin(board, ROW, COL) != 'C')
		{
			break;
		}
	}
	if (Iswin(board, ROW, COL) == '*')
	{
		printf("玩家赢\n");
	}
	else if (Iswin(board, ROW, COL) == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

int main()
{
	int input = 0;
	do
	{
		printf("请选择：\n");
		menu();
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
			printf("输入错误\n");
			break;
		}

	} while (input);

	return 0;
}