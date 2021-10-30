#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//静态的版本
//void InitContact(struct contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//动态的版本
void InitContact(struct contact* pc)
{
	pc->sz = 0;
	pc->data = (struct PeoInfo*)malloc(DEAULT_SZ * sizeof(struct PeoInfo));
	pc->capacity = DEAULT_SZ;
}

//静态的版本
//void AddContact(struct contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满\n");
//	}
//	else
//	{
//		printf("请输入名字:>");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("请输入年龄:>");
//		scanf("%d", &(pc->data[pc->sz].age));
//		printf("请输入性别:>");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("请输入号码:>");
//		scanf("%s", pc->data[pc->sz].tele);
//		printf("请输入地址:>");
//		scanf("%s", pc->data[pc->sz].addr);
//		pc->sz++;
//
//		printf("添加联系人成功\n");
//	}
//}

void AddContact(struct contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//增加容量
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("扩容失败\n");
			return;
		}
	}
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入号码:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;

	printf("添加联系人成功\n");
}

void ShowContact(const struct contact* pc)
{
	int i = 0;
	printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n", "name", "age", "sex", "telephone", "address");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

int FindContactByName(const struct contact* pc, const char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DeleteContact(struct contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，删除失败\n");
		return;
	}
	else
	{
		int i = 0;
		char name[NAME_MAX];
		printf("请输入要删除人的名字:>");
		scanf("%s", name);
		int pos = FindContactByName(pc, name);
		if (pos == -1)
		{
			printf("查无此人\n");
		}
		else
		{
			for (i = pos; i < pc->sz - 1; i++)
			{
				pc->data[i] = pc->data[i + 1];
			}
			pc->sz--;
			printf("删除成功\n");
		}
	}
}

void SearchContact(const struct contact* pc)
{
	int i = 0;
	char name[NAME_MAX];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%15s\t%5s\t%8s\t%15s\t%30s\n", "name", "age", "sex", "telephone", "address");
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}

void ModifyContact(struct contact* pc)
{
	int i = 0;
	char name[NAME_MAX];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("请输入新的名字:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入新的年龄:>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入新的性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入新的号码:>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);

		printf("修改成功\n");
	}
}

void DestoryContact(struct contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

void SortContact(struct contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，排序失败\n");
	}
	else
	{

		qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_name);
		printf("排序成功\n");
	}

}