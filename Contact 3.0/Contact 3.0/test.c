#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

enum Option
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

void meun()
{
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("******      1.Add       2.Delete     ******\n");
	printf("******      3.Search    4.Modify     ******\n");
	printf("******      5.Show      6.Sort       ******\n");
	printf("******           0.Exit              ******\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
}

int main()
{
	int input = 0;
	struct contact con;
	InitContact(&con);
	do {
		meun();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DELETE:
			DeleteContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			//保存通讯录
			SaveContact(&con);
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选项非法，请重新输入\n");
			break;
		}

	} while (input);

	return 0;
}