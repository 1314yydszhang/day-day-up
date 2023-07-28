#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
void test1()
{
	//抽象类一般用new  要delete
	Worker* w = NULL;
	w = new Employee(1, 1, "1");
	w->showInfo();
	delete w;
	w = new Manager(1, 1, "1");
	w->showInfo();
	delete w;
	w = new Boss(1, 1, "1");
	w->showInfo();
	delete w;
}
void main()
{
	//test1();
	//实例化
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.ShowMenu();
		cout << "选择" << endl;
		cin >> choice;
		switch (choice)

		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.AddEmp();
			break;
		case 2:
			wm.ShowEmp();
		default:
			system("cls");
			break;
		}
	}
	system("pause");//按任意键继续
}