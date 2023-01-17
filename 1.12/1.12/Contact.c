#include "Contact.h"
////初始化结构体
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
// //初始化结构体
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	PoPinfo* ptr = (PoPinfo*)calloc(FIFIST, sizeof(PoPinfo));//动态开辟空间，并初始化为0
	if (ptr == NULL)//每次动态开辟完空间都要检查一下，防止开辟失败
	{
		perror("InitContact:calloc");//开辟失败就将失败的信息打印出来
		return;//结束
	}
	pc->data = ptr;
	pc->capacity = FIFIST;//3个人员
	LoadContact(pc);//将文件信息加载到pc所指向的空间里面去也就是通讯录
}

////添加ADD函数
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	//增加一个人的信息
//	printf("请输入姓名：\n");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入年龄：\n");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入性别：\n");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入地址：\n");
//	scanf("%s", pc->data[pc->sz].addr);
//	printf("请输入电话：\n");
//	scanf("%s", pc->data[pc->sz].tele);
//	pc->sz++;
//}
//添加ADD函数 动态
void Check_capacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//需要增容
		//动态增容，每次增容在原capacity容量下增加 IND个
		PoPinfo* ptr = (PoPinfo*)realloc(pc->data, (pc->capacity + IND) * sizeof(PoPinfo));
		if (ptr == NULL)
		{
			perror("Check_capacity::realloc");
		}
		pc->data = ptr;
		pc->capacity += IND;
		printf("增容成功\n");
	}
}
void AddContact(Contact* pc)
{
	assert(pc);
	//进入函数首先要进行判断是否有容量存储。
	Check_capacity(pc);//增容函数。
	
	//增加一个人的信息
	printf("请输入姓名：\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别：\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入地址：\n");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入电话：\n");
	scanf("%s", pc->data[pc->sz].tele);
	pc->sz++;
}
int FindByName(Contact* pc, char name[])
{
	int i;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
		
	}
	return -1;
}
void DelContact(Contact* pc)//删减函数
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	//删除指定的人;
	//先找到指定的人
	printf("请输入要删除的联系人名字：\n");
	scanf("%s", name);
	int ret=FindByName(pc, name);
	if (ret == -1)
	{
		printf("删除的人不存在\n");
		return;
	}
	else
	{
		int i;
		for (i = ret; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
	return;


}
void SearchContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空无法查询\n");
	}
	char name[NAME_MAX];
	printf("请输入要查找的联系人名字：\n");
	scanf("%s", name);
	int pos=FindByName(pc, name);
	if (pos == -1)
	{
		printf("抱歉，查找的人不存在\n");
		return;
	}
	else
	{//打印查找人的信息
		printf("%s\n", pc->data[pos].name);
		printf("%d\n", pc->data[pos].age);
		printf("%s\n", pc->data[pos].sex);
		printf("%s\n", pc->data[pos].addr);
		printf("%s\n", pc->data[pos].tele);
	}
}
void DisplayContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录中没有人员可显示\n");
		return;
	}
	int i = 0;
	printf("%-10s\t%-4s\t%-4s\t%-10s\t%-12s\n", "姓名", "年龄", "性别", "地址", "电话");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-4d\t%-4s\t%-10s\t%-12s\n",
			                            pc->data[i].name,
										pc->data[i].age,
										pc->data[i].sex,
										pc->data[i].addr,
										pc->data[i].tele);
	}
}
void ModiContact(Contact* pc)//修改联系人操作
{
	assert(pc);
	char name[NAME_MAX];
	printf("请输入要修改联系人名字：\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("抱歉，该联系人不存在\n");
		return;
	}
	else
	{
		printf("请输入姓名：\n");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄：\n");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别：\n");
		scanf("%s", pc->data[pos].sex);
		printf("请输入地址：\n");
		scanf("%s", pc->data[pos].addr);
		printf("请输入电话：\n");
		scanf("%s", pc->data[pos].tele);
		printf("修改完毕\n");
	}
}
void Destroy_contact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	pc = NULL;

}
void Protect_contact(Contact* pc)
{
	//写数据之前要
	//打开文件
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)//检查一下是否文件打开失败
	{
		perror("Protect_contact::fopen");//如果失败将失败信息返回
		
	}
	{
		//写数据,将pc所指向的data的人员信息写入pf开辟的文件里面去，空间大小为sizeof(PoPinfo),一次传一个数据。
		int i = 0;
		for (i = 0; i < pc->sz; i++)
		{
			fwrite(pc->data + i, sizeof(PoPinfo), 1, pf);
		}
		fclose(pf);
		pf = NULL;
		printf("保存数据成功\n");
	}

}
void LoadContact(Contact* pc)
{
	//将文件信息加载到通讯录里面
	//读数据
	//1..打开文件
	FILE* pf = fopen("contact.txt", "rb");//以rb的方式打开文件
	if (pf == NULL)//判断一下是否打开文件成功
	{
		perror("LoadContatc::fopen");
	}
	else
	{
		//2.读数据了
		//因为一开始不知道文件里面有多少数据呀，我们得把文件里面的数据全部拿出来
		//但因为一开始的通讯录容纳量有限制，所以一旦文件里面的数据超过一开始给定的容纳量就需要
		//增容。
		PoPinfo tmp = { 0 };
		int i = 0;
		while (fread(&tmp, sizeof(PoPinfo), 1, pf))
		{
			//首先考虑扩容问题；
			Check_capacity(pc);
			pc->data[i] = tmp;//将读取的数据放入通讯录里
			pc->sz++;//放进去一个sz加1
			i++;
		}
		fclose(pf);//关闭文件
		pf = NULL;
	}
}