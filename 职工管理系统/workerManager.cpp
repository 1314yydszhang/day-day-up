#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
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
		//�ļ�Ϊ�� 
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//�ļ����� ��ȡ�ļ���ʼ��ϵͳ
	int num = this->getEmpNum();
	cout << "ְ������" << num << endl;
	this->m_EmpNum = num;
	//�ռ俪��
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
	cout << "*********     ְ������ϵͳ    ***********" << endl;
	cout << "*********    0.�˳�����ϵͳ   ***********" << endl;
	cout << "*********    1.���ְ����Ϣ   ***********" << endl;
	cout << "*********    2.��ʾְ����Ϣ   ***********" << endl;
	cout << "*********    3.ɾ����ְְ��   ***********" << endl;
	cout << "*********    4.�޸�ְ����Ϣ   ***********" << endl;
	cout << "*********    5.����ְ����Ϣ   ***********" << endl;
	cout << "*********    6.���ձ������   ***********" << endl;
	cout << "*********    7.��������ĵ�   ***********" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem()
{
	cout << "�˳�ϵͳ" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::AddEmp()
{
	cout << "�������ְ������:" << endl;
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
			cout << "��" << i + 1 << "��ְ�����" << endl;
			cin >> id;
			cout << "��" << i + 1 << "��ְ������" << endl;
			cin >> name;
			

			cout << "��" << i + 1 << "��ְ��ְҵ" << endl;
			cout << "1.��ְͨ��  2.����  3.�ϰ�" << endl;
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
					cout << "��д" << endl;
					cin >> dSelect;
				}
			}
		
			
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "��ӳɹ�" <<addNum<< endl;
		this->Save();
	}
	else
	{
		cout << "��������" << endl;
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
		cout << "�ļ������ڻ�Ϊ��" << endl;
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
