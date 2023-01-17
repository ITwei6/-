#include "Contact.h"
void mneun()
{
	printf("**************************\n");
	printf("****1.add    2.del    ****\n");
	printf("****3.search 4.modify ****\n");
	printf("****5.show   6.sort   ****\n");
	printf("****0exit             ****\n");
	printf("**************************\n");
}
int main()
{
	Contact con;//创建一个结构体变量con;
	//首先进行初始化这个结构体变量
	InitContact(&con);
	//还要考虑每次通讯录运行起来都要把上次的数据加载到通讯录
	//文件里面的信息再加载到通讯录里面
	int input=0;
	do
	{
		mneun();
		printf("请输入要选择的：\n");
		scanf("%d", &input);
		switch (input)
		{//第二步增加ADD函数,增加联系人
		case 1:  AddContact(&con);
			break;
			//第三步添加删减函数，删减联系人
		case 2:DelContact(&con);
			break;
		case 3:SearchContact(&con);//寻找联系人
			break;
		case 4:ModiContact(&con); //修改联系人信息
			break;
		case 5:DisplayContact(&con);//显示联系人
			break;
		case 6:
			break;
		case 0:	printf("退出通讯录\n");
			Protect_contact(&con);
			Destroy_contact(&con);//销毁空间
			//退出之前要将信息存储到文件里
			
		
			break;
		default:break;
		}
	} while (input);
	return 0;
}