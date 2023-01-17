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
//��̬
//typedef struct Contact
//{
//	PoPinfo data[MAX];//ͨѶ¼����Ա����Ϣ
//	int sz;//��ǰ�Ѿ��ŵ���Ϣ�ĸ�����
//}Contact;
//��̬
typedef struct Contact
{
	PoPinfo *data;//ָ��ͨѶ¼����Ա��Ϣ�Ŀռ�
	int sz;//��ǰ�Ѿ��ŵ���Ϣ�ĸ�����
	int capacity;//��һ�δ����Ա�����洢��
}Contact;
void InitContact(Contact* pc);//��ʼ��ͨѶ¼
void Destroy_contact(Contact* pc);//����ͨѶ¼�ռ�
void AddContact(Contact* pc);//�����ϵ����Ϣ
void DelContact(Contact* pc);//ɾ����ϵ����Ϣ
void SearchContact(Contact* pc);//��ѯ��ϵ����Ϣ
void DisplayContact(Contact* pc);//��ʾ��ϵ����Ϣ
void ModiContact(Contact* pc);//�޸���ϵ����Ϣ
void Protect_contact(Contact* pc);//��ͨѶ¼��Ϣ�洢���ļ�����ȥ
void LoadContact(Contact* pc);//���ļ���Ϣ���ص�ͨѶ¼����ȥ