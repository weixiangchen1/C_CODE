#pragma once
#include <stdio.h>
#include <string.h>
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

struct contact
{
	struct PeoInfo data[MAX];
	int sz;
};

//初始化通讯录
void InitContact(struct contact* pc);
//添加联系人
void AddContact(struct contact* pc);
//打印通讯录
void ShowContact(struct contact* pc);
//删除联系人
void DeleteContact(struct contact* pc);
//查找联系人
void SearchContact(struct contact* pc);
