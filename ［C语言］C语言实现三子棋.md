![在这里插入图片描述](https://img-blog.csdnimg.cn/84eda3987ae74c278befbc6417cfccc1.png)
@[TOC]

# 前言
三子棋是黑白棋的一种。三子棋是一种民间传统游戏，又叫九宫棋、圈圈叉叉、一条龙、井字棋等。将正方形对角线连起来，相对两边依次摆上三个双方棋子，只要将自己的三个棋子走成一条线，对方就算输了。但是，有很多时候会出现和棋的情况。

# 多文件形式
在实现游戏的首先，需要创建test.c  game.c game.h三个文件。
test.c主要进行游戏的测试。
game.c主要进行游戏内部一些函数的具体实现。
game.h主要是一些声明，宏定义。

# 游戏逻辑
1、打印一个游戏的简易菜单。
2、初始化棋盘。
3、打印棋盘。
4、玩家下棋（键盘输入坐标）  打印棋盘，判断输赢。
5、电脑下棋（随机坐标）  打印棋盘，判断输赢。

# 游戏实现

![在这里插入图片描述](https://img-blog.csdnimg.cn/5d8351313cd74fd6b39bbf4bf8b257ab.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)


## 1.打印菜单

在屏幕打印一个简易菜单，提示玩家选择。

```c
void menu()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/77b1a9cea0914b699580711cef5026d4.png)

## 2.初始化棋盘

将3x3的数组初始化为空格。
```c
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

```
## 3.打印棋盘

在屏幕打印当前棋盘，让玩家选择下一步所要走哪一步。

```c
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
```

## 4.玩家下棋

玩家在键盘上输入坐标，所输入的合法范围是1<=x,y<=3，根据玩家所输入将对应数组赋值为星号'*'。

```cpp
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("玩家走:>\n");

	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("下标越界，请重新输入\n");
		}
	}

}
```

## 5.电脑下棋 

生成随机数，在所对应数组赋值为井号‘#’。

```c
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	x = rand() % row;
	y = rand() % col;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
```

## 6.判断输赢 
1.玩家赢返回星号
2.电脑赢返回井号
3.平局返回P
4.棋盘为满，继续游戏返回C

```c
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (IsFull(board, ROW, COL))
	{
		return 'P';
	}
	return 'C';
}
```


## 7.判断棋盘是否满 


```c
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
```

# 具体代码
## test.c 

```c
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
```

## game.c 

```c
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("玩家走:>\n");

	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("下标越界，请重新输入\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	x = rand() % row;
	y = rand() % col;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (IsFull(board, ROW, COL))
	{
		return 'P';
	}
	return 'C';
}

```

## game.h

```c
#pragma once

#include <stdio.h>
#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);	

char Iswin(char board[ROW][COL], int row, int col);
```

