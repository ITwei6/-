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
	Contact con;//����һ���ṹ�����con;
	//���Ƚ��г�ʼ������ṹ�����
	InitContact(&con);
	//��Ҫ����ÿ��ͨѶ¼����������Ҫ���ϴε����ݼ��ص�ͨѶ¼
	//�ļ��������Ϣ�ټ��ص�ͨѶ¼����
	int input=0;
	do
	{
		mneun();
		printf("������Ҫѡ��ģ�\n");
		scanf("%d", &input);
		switch (input)
		{//�ڶ�������ADD����,������ϵ��
		case 1:  AddContact(&con);
			break;
			//���������ɾ��������ɾ����ϵ��
		case 2:DelContact(&con);
			break;
		case 3:SearchContact(&con);//Ѱ����ϵ��
			break;
		case 4:ModiContact(&con); //�޸���ϵ����Ϣ
			break;
		case 5:DisplayContact(&con);//��ʾ��ϵ��
			break;
		case 6:
			break;
		case 0:	printf("�˳�ͨѶ¼\n");
			Protect_contact(&con);
			Destroy_contact(&con);//���ٿռ�
			//�˳�֮ǰҪ����Ϣ�洢���ļ���
			
		
			break;
		default:break;
		}
	} while (input);
	return 0;
}