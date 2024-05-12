#include<stdio.h>
#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int number;

typedef struct PCB {
	char Name;//进程名
	int ArriveTime;//到达时间
	int ServerTime;//服务时间,运行时间
	int StartTime;//开始时间
	int FinishTime;//完成时间
	int Turn_Over_Time;//周转时间
	float Weighted_Turn_Over_Time;//带权周转时间
}PCB;

PCB a[1000];
PCB b[1000];

int compareServerTime(struct PCB p, struct PCB q)//比较函数
{
	return p.ServerTime < q.ServerTime;
}
bool compareArriveTime(struct PCB p, struct PCB q)//比较函数
{
	return p.ArriveTime < q.ArriveTime;
}

void SFJ(PCB b[]) 
{
	int i;
    
	b[0].StartTime = b[0].ArriveTime;
	b[0].FinishTime = b[0].ArriveTime + b[0].ServerTime;
	b[0].Turn_Over_Time = b[0].FinishTime - b[0].ArriveTime;  //周转时间 = 完成时间 - 到达时间
	b[0].Weighted_Turn_Over_Time = b[0].Turn_Over_Time / b[0].ServerTime; //带权周转时间 = 周转时间 / 服务时间 

	
	for (i = 1; i < number; i++)
	{
		if (b[i].ArriveTime < b[i - 1].FinishTime)
		{
			sort(b + i, b + number, compareServerTime);//除第一个进程，其余进程根据服务时间排序
			b[i].StartTime = b[i - 1].FinishTime;
			b[i].FinishTime = b[i].StartTime + b[i].ServerTime;  // 完成时间 = 开始时间 + 服务时间
			b[i].Turn_Over_Time = b[i].FinishTime - b[i].ArriveTime;  //周转时间 = 完成时间 - 到达时间
			b[i].Weighted_Turn_Over_Time = b[i].Turn_Over_Time * 1.0 / b[i].ServerTime; //带权周转时间 = 周转时间 * 1.0 / 服务时间
		}
		else {
			sort(b + i, b + number, compareArriveTime);//除第一个进程，其余进程根据到达时间排序
			b[i].StartTime = b[i].ArriveTime;
			b[i].FinishTime = b[i].StartTime + b[i].ServerTime;  // 完成时间 = 开始时间 + 服务时间
			b[i].Turn_Over_Time = b[i].FinishTime - b[i].ArriveTime;  //周转时间 = 完成时间 - 到达时间
			b[i].Weighted_Turn_Over_Time = b[i].Turn_Over_Time * 1.0 / b[i].ServerTime; //带权周转时间 = 周转时间 * 1.0 / 服务时间
		}
		 

	}
	cout << "进程名" << " " << "到达时间" << " " << "服务时间" << " " << "开始时间" << " " << "完成时间" << " " << "周转时间" << " " << "带权周转时间" << endl;
	for (i = 0; i < number; i++)
	{
		cout << " " << b[i].Name << "      " << b[i].ArriveTime << "        " << b[i].ServerTime << "        " << b[i].StartTime << "       " << b[i].FinishTime << "        " << b[i].Turn_Over_Time << "        " << b[i].Weighted_Turn_Over_Time << endl;
	}
}

 main()
{
	int i;
	cout << "请输入进程的数量" << endl;
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
