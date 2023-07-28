#include "manager.h"

Manager::Manager(int id, int did, string name)
{
	this->m_Id = id;
	this->m_DeptId = did;
	this->m_Name = name;
}

void Manager::showInfo()
{
	cout << "职工编号:" << this->m_Id << "\t职工名字:" << this->m_Name << "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:" << this->getDeptDuty() << endl;
}

string Manager::getDeptName()
{
	return string("经理");
}

string Manager::getDeptDuty()
{
	return string("完成老板任务");
}
