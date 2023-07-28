#include "boss.h"
Boss::Boss(int id, int did, string name)
{
	this->m_Id = id;
	this->m_DeptId = did;
	this->m_Name = name;
}

void Boss::showInfo()
{
	cout << "职工编号:" << this->m_Id << "\t职工名字:" << this->m_Name << "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:" << this->getDeptDuty() << endl;
}

string Boss::getDeptName()
{
	return string("老板");
}

string Boss::getDeptDuty()
{
	return string("完成公司任务");
}