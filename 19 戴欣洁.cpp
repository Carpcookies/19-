#include<stdio.h>
#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int number;

typedef struct PCB {
	char Name;//������
	int ArriveTime;//����ʱ��
	int ServerTime;//����ʱ��,����ʱ��
	int StartTime;//��ʼʱ��
	int FinishTime;//���ʱ��
	int Turn_Over_Time;//��תʱ��
	float Weighted_Turn_Over_Time;//��Ȩ��תʱ��
}PCB;

PCB a[1000];
PCB b[1000];

int compareServerTime(struct PCB p, struct PCB q)//�ȽϺ���
{
	return p.ServerTime < q.ServerTime;
}
bool compareArriveTime(struct PCB p, struct PCB q)//�ȽϺ���
{
	return p.ArriveTime < q.ArriveTime;
}

void SFJ(PCB b[]) 
{
	int i;
    
	b[0].StartTime = b[0].ArriveTime;
	b[0].FinishTime = b[0].ArriveTime + b[0].ServerTime;
	b[0].Turn_Over_Time = b[0].FinishTime - b[0].ArriveTime;  //��תʱ�� = ���ʱ�� - ����ʱ��
	b[0].Weighted_Turn_Over_Time = b[0].Turn_Over_Time / b[0].ServerTime; //��Ȩ��תʱ�� = ��תʱ�� / ����ʱ�� 

	
	for (i = 1; i < number; i++)
	{
		if (b[i].ArriveTime < b[i - 1].FinishTime)
		{
			sort(b + i, b + number, compareServerTime);//����һ�����̣�������̸��ݷ���ʱ������
			b[i].StartTime = b[i - 1].FinishTime;
			b[i].FinishTime = b[i].StartTime + b[i].ServerTime;  // ���ʱ�� = ��ʼʱ�� + ����ʱ��
			b[i].Turn_Over_Time = b[i].FinishTime - b[i].ArriveTime;  //��תʱ�� = ���ʱ�� - ����ʱ��
			b[i].Weighted_Turn_Over_Time = b[i].Turn_Over_Time * 1.0 / b[i].ServerTime; //��Ȩ��תʱ�� = ��תʱ�� * 1.0 / ����ʱ��
		}
		else {
			sort(b + i, b + number, compareArriveTime);//����һ�����̣�������̸��ݵ���ʱ������
			b[i].StartTime = b[i].ArriveTime;
			b[i].FinishTime = b[i].StartTime + b[i].ServerTime;  // ���ʱ�� = ��ʼʱ�� + ����ʱ��
			b[i].Turn_Over_Time = b[i].FinishTime - b[i].ArriveTime;  //��תʱ�� = ���ʱ�� - ����ʱ��
			b[i].Weighted_Turn_Over_Time = b[i].Turn_Over_Time * 1.0 / b[i].ServerTime; //��Ȩ��תʱ�� = ��תʱ�� * 1.0 / ����ʱ��
		}
		 

	}
	cout << "������" << " " << "����ʱ��" << " " << "����ʱ��" << " " << "��ʼʱ��" << " " << "���ʱ��" << " " << "��תʱ��" << " " << "��Ȩ��תʱ��" << endl;
	for (i = 0; i < number; i++)
	{
		cout << " " << b[i].Name << "      " << b[i].ArriveTime << "        " << b[i].ServerTime << "        " << b[i].StartTime << "       " << b[i].FinishTime << "        " << b[i].Turn_Over_Time << "        " << b[i].Weighted_Turn_Over_Time << endl;
	}
}

 main()
{
	int i;
	cout << "��������̵�����" << endl;
	number = 4;
	b[0].Name = 'a';
	b[0].ArriveTime = 1;
	b[0].ServerTime = 3;

	b[1].Name = 'b';
	b[1].ArriveTime = 3;
	b[1].ServerTime = 6;

	b[2].Name = 'c';
	b[2].ArriveTime = 5;
	b[2].ServerTime = 2;

	b[3].Name = 'd';
	b[3].ArriveTime = 7;
	b[3].ServerTime = 1;

	for (i = 0; i < number; i++)
	{
		a[i] = b[i];
	}

	SFJ(b);
}
