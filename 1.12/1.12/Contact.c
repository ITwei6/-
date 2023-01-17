#include "Contact.h"
////��ʼ���ṹ��
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
// //��ʼ���ṹ��
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	PoPinfo* ptr = (PoPinfo*)calloc(FIFIST, sizeof(PoPinfo));//��̬���ٿռ䣬����ʼ��Ϊ0
	if (ptr == NULL)//ÿ�ζ�̬������ռ䶼Ҫ���һ�£���ֹ����ʧ��
	{
		perror("InitContact:calloc");//����ʧ�ܾͽ�ʧ�ܵ���Ϣ��ӡ����
		return;//����
	}
	pc->data = ptr;
	pc->capacity = FIFIST;//3����Ա
	LoadContact(pc);//���ļ���Ϣ���ص�pc��ָ��Ŀռ�����ȥҲ����ͨѶ¼
}

////���ADD����
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	//����һ���˵���Ϣ
//	printf("������������\n");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("���������䣺\n");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("�������Ա�\n");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("�������ַ��\n");
//	scanf("%s", pc->data[pc->sz].addr);
//	printf("������绰��\n");
//	scanf("%s", pc->data[pc->sz].tele);
//	pc->sz++;
//}
//���ADD���� ��̬
void Check_capacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//��Ҫ����
		//��̬���ݣ�ÿ��������ԭcapacity���������� IND��
		PoPinfo* ptr = (PoPinfo*)realloc(pc->data, (pc->capacity + IND) * sizeof(PoPinfo));
		if (ptr == NULL)
		{
			perror("Check_capacity::realloc");
		}
		pc->data = ptr;
		pc->capacity += IND;
		printf("���ݳɹ�\n");
	}
}
void AddContact(Contact* pc)
{
	assert(pc);
	//���뺯������Ҫ�����ж��Ƿ��������洢��
	Check_capacity(pc);//���ݺ�����
	
	//����һ���˵���Ϣ
	printf("������������\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("���������䣺\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("�������ַ��\n");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������绰��\n");
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
void DelContact(Contact* pc)//ɾ������
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	//ɾ��ָ������;
	//���ҵ�ָ������
	printf("������Ҫɾ������ϵ�����֣�\n");
	scanf("%s", name);
	int ret=FindByName(pc, name);
	if (ret == -1)
	{
		printf("ɾ�����˲�����\n");
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
		printf("ɾ���ɹ�\n");
	}
	return;


}
void SearchContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ���޷���ѯ\n");
	}
	char name[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ�����֣�\n");
	scanf("%s", name);
	int pos=FindByName(pc, name);
	if (pos == -1)
	{
		printf("��Ǹ�����ҵ��˲�����\n");
		return;
	}
	else
	{//��ӡ�����˵���Ϣ
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
		printf("ͨѶ¼��û����Ա����ʾ\n");
		return;
	}
	int i = 0;
	printf("%-10s\t%-4s\t%-4s\t%-10s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
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
void ModiContact(Contact* pc)//�޸���ϵ�˲���
{
	assert(pc);
	char name[NAME_MAX];
	printf("������Ҫ�޸���ϵ�����֣�\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("��Ǹ������ϵ�˲�����\n");
		return;
	}
	else
	{
		printf("������������\n");
		scanf("%s", pc->data[pos].name);
		printf("���������䣺\n");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�\n");
		scanf("%s", pc->data[pos].sex);
		printf("�������ַ��\n");
		scanf("%s", pc->data[pos].addr);
		printf("������绰��\n");
		scanf("%s", pc->data[pos].tele);
		printf("�޸����\n");
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
	//д����֮ǰҪ
	//���ļ�
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)//���һ���Ƿ��ļ���ʧ��
	{
		perror("Protect_contact::fopen");//���ʧ�ܽ�ʧ����Ϣ����
		
	}
	{
		//д����,��pc��ָ���data����Ա��Ϣд��pf���ٵ��ļ�����ȥ���ռ��СΪsizeof(PoPinfo),һ�δ�һ�����ݡ�
		int i = 0;
		for (i = 0; i < pc->sz; i++)
		{
			fwrite(pc->data + i, sizeof(PoPinfo), 1, pf);
		}
		fclose(pf);
		pf = NULL;
		printf("�������ݳɹ�\n");
	}

}
void LoadContact(Contact* pc)
{
	//���ļ���Ϣ���ص�ͨѶ¼����
	//������
	//1..���ļ�
	FILE* pf = fopen("contact.txt", "rb");//��rb�ķ�ʽ���ļ�
	if (pf == NULL)//�ж�һ���Ƿ���ļ��ɹ�
	{
		perror("LoadContatc::fopen");
	}
	else
	{
		//2.��������
		//��Ϊһ��ʼ��֪���ļ������ж�������ѽ�����ǵð��ļ����������ȫ���ó���
		//����Ϊһ��ʼ��ͨѶ¼�����������ƣ�����һ���ļ���������ݳ���һ��ʼ����������������Ҫ
		//���ݡ�
		PoPinfo tmp = { 0 };
		int i = 0;
		while (fread(&tmp, sizeof(PoPinfo), 1, pf))
		{
			//���ȿ����������⣻
			Check_capacity(pc);
			pc->data[i] = tmp;//����ȡ�����ݷ���ͨѶ¼��
			pc->sz++;//�Ž�ȥһ��sz��1
			i++;
		}
		fclose(pf);//�ر��ļ�
		pf = NULL;
	}
}