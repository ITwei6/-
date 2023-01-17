#define _CRT_SECURE_NO_WARNINGS
#pragma once
#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADD_MAX 30
#define TELE_MAX 12
#define FIFIST 3
#define IND 2
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct PoPinfo
{
	char name[NAME_MAX];
	int  age;
	char sex[SEX_MAX];
	char addr[ADD_MAX];
	char tele[TELE_MAX];
}PoPinfo;
//静态
//typedef struct Contact
//{
//	PoPinfo data[MAX];//通讯录里人员的信息
//	int sz;//当前已经放的信息的个数。
//}Contact;
//动态
typedef struct Contact
{
	PoPinfo *data;//指向通讯录里人员信息的空间
	int sz;//当前已经放的信息的个数。
	int capacity;//第一次存放人员的最大存储量
}Contact;
void InitContact(Contact* pc);//初始化通讯录
void Destroy_contact(Contact* pc);//销毁通讯录空间
void AddContact(Contact* pc);//添加联系人信息
void DelContact(Contact* pc);//删减联系人信息
void SearchContact(Contact* pc);//查询联系人信息
void DisplayContact(Contact* pc);//显示联系人信息
void ModiContact(Contact* pc);//修改联系人信息
void Protect_contact(Contact* pc);//将通讯录信息存储到文件里面去
void LoadContact(Contact* pc);//将文件信息加载到通讯录里面去