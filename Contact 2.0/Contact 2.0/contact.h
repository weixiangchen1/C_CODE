#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEAULT_SZ 3
#define MAX 1000
#define NAME_MAX 30
#define SEX_MAX 30
#define TELE_MAX 30
#define ADDR_MAX 30

struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};

//静态的版本
//struct contact
//{
//	struct PeoInfo data[MAX];
//	int sz;
//};

//动态的版本
struct contact
{
	struct PeoInfo* data;
	int sz;//通讯录的当前有效容量
	int capacity;//通讯录的最大容量
};

//初始化通讯录
void InitContact(struct contact* pc);
//添加联系人
void AddContact(struct contact* pc);
//打印通讯录
void ShowContact(const struct contact* pc);
//删除联系人
void DeleteContact(struct contact* pc);
//查找联系人
void SearchContact(const struct contact* pc);
//修改指定联系人
void ModifyContact(struct contact* pc);
//排序联系人
void SortContact(struct contact* pc);
//销毁通讯录
void DestoryContact(struct contact* pc);