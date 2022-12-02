![在这里插入图片描述](https://img-blog.csdnimg.cn/bdf0774fbbb9479f8a8d2fbb61ba8970.png)
@[TOC]
# 前言
《扫雷》是一款大众类的益智小游戏，于1992年发行。游戏目标是在最短的时间内根据点击格子出现的数字找出所有非雷格子，同时避免踩雷，踩到一个雷即全盘皆输。

# 多文件形式
在实现游戏的首先，需要创建test.c game.c game.h三个文件。
test.c主要进行游戏的测试。
game.c主要进行游戏内部一些函数的具体实现。
game.h主要是一些声明，宏定义。

# 游戏逻辑
1、打印简易菜单
2、定义及初始化数组
3、随机生成布置雷
4、玩家排雷

# 游戏实现
![在这里插入图片描述](https://img-blog.csdnimg.cn/1cadaefeb2494508a52c2d8086fffed1.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)

## 打印简易菜单
打印菜单让玩家选择，输入1为开始游戏，输入0位退出游戏

```c
void meun()
{
	printf("*********************************\n");
	printf("*********************************\n");
	printf("***********  1. play  ***********\n");
	printf("***********  0. exit  ***********\n");
	printf("*********************************\n");
	printf("*********************************\n");
}
```

## 初始化数组
程序生成两个9*9的方块矩阵，mine数组用来保存雷的布局，show数组用来展示玩家实时的排雷进度。
mine数组中，'1'代表雷，’0‘代表无雷。
show数组中，'*'代表雷，'#'代表无雷。

```c
	//初始化数组
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

```
## 打印方块矩阵
玩家每确定一次排雷坐标，就要在屏幕上显示排雷情况。

```c
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
```
## 布置雷
利用C语言库中的rand函数生成随机数来布置雷。

```c
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
```
## 玩家排雷
玩家输入排雷的坐标，程序会在屏幕显示当前坐标周围8个方块存在的雷的数量。

```c
int MineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] +
		mine[x - 1][y] +
		mine[x - 1][x - 1]) - 8 * '0';
}

void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (mine[x][y] == '0')
			{
				int count = MineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
			else
			{
				printf("很遗憾，你被炸死了\n");
				break;
			}
		}
		else
		{
			printf("下标错误，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}


}
```
# 完整代码
## test.c

```c
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
```
## game.c

```c
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int MineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] +
		mine[x - 1][y] +
		mine[x - 1][x - 1]) - 8 * '0';
}

void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (mine[x][y] == '0')
			{
				int count = MineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
			else
			{
				printf("很遗憾，你被炸死了\n");
				break;
			}
		}
		else
		{
			printf("下标错误，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}


}
```

## game.h

```c
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define EASY_COUNT 10

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
```

