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

//��ʼ��ͨѶ¼
void InitContact(struct contact* pc);
//�����ϵ��
void AddContact(struct contact* pc);
//��ӡͨѶ¼
void ShowContact(struct contact* pc);
//ɾ����ϵ��
void DeleteContact(struct contact* pc);
//������ϵ��
void SearchContact(struct contact* pc);
