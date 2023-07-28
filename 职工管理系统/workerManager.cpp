#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空 
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//文件存在 读取文件初始化系统
	int num = this->getEmpNum();
	cout << "职工人数" << num << endl;
	this->m_EmpNum = num;
	//空间开辟
	this->m_EmpArray= new Worker*[this->m_EmpNum] ;
	this->InitEmp();
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << this->m_EmpArray[i]->m_Id << this->m_EmpArray[i]->m_Name << this->m_EmpArray[i]->m_DeptId << endl;
	}
}
void WorkerManager::ShowMenu()
{
	cout << "*****************************************" << endl;
	cout << "*********     职工管理系统    ***********" << endl;
	cout << "*********    0.退出管理系统   ***********" << endl;
	cout << "*********    1.添加职工信息   ***********" << endl;
	cout << "*********    2.显示职工信息   ***********" << endl;
	cout << "*********    3.删除离职职工   ***********" << endl;
	cout << "*********    4.修改职工信息   ***********" << endl;
	cout << "*********    5.查找职工信息   ***********" << endl;
	cout << "*********    6.按照编号排序   ***********" << endl;
	cout << "*********    7.清空所有文档   ***********" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem()
{
	cout << "退出系统" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::AddEmp()
{
	cout << "输入添加职工数量:" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace=new Worker* [newSize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "第" << i + 1 << "新职工编号" << endl;
			cin >> id;
			cout << "第" << i + 1 << "新职工姓名" << endl;
			cin >> name;
			

			cout << "第" << i + 1 << "新职工职业" << endl;
			cout << "1.普通职工  2.经理  3.老板" << endl;
			cin >> dSelect;
			while (true)
			{
				if (dSelect >= 1 && dSelect <= 3)
				{
					Worker* w = NULL;
					switch (dSelect)
					{
					case 1:
						w = new Employee(id, 1, name);
						break;
					case 2:
						w = new Manager(id, 2, name);
						break;
					case 3:
						w = new Boss(id, 3, name);
						break;
					default:
						break;
					}
					newSpace[this->m_EmpNum + i] = w;
					break;
				}
				else
				{
					cout << "重写" << endl;
					cin >> dSelect;
				}
			}
		
			
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "添加成功" <<addNum<< endl;
		this->Save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");

}
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}
void WorkerManager::InitEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* w = NULL;
		if (did == 1)
		{
			w = new Employee(id, did, name);
		}
		else if (did == 2)
		{
			w = new Manager(id, did, name);

		}
		else
		{
			w = new Boss(id, did, name);

		}
		this->m_EmpArray[index] = w;
		index++;
	}
	ifs.close();
}
void WorkerManager::ShowEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()
{
}
