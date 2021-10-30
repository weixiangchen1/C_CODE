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

//��̬�İ汾
//struct contact
//{
//	struct PeoInfo data[MAX];
//	int sz;
//};

//��̬�İ汾
struct contact
{
	struct PeoInfo* data;
	int sz;//ͨѶ¼�ĵ�ǰ��Ч����
	int capacity;//ͨѶ¼���������
};

//��ʼ��ͨѶ¼
void InitContact(struct contact* pc);
//�����ϵ��
void AddContact(struct contact* pc);
//��ӡͨѶ¼
void ShowContact(const struct contact* pc);
//ɾ����ϵ��
void DeleteContact(struct contact* pc);
//������ϵ��
void SearchContact(const struct contact* pc);
//�޸�ָ����ϵ��
void ModifyContact(struct contact* pc);
//������ϵ��
void SortContact(struct contact* pc);
//����ͨѶ¼
void DestoryContact(struct contact* pc);