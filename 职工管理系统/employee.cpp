#include "employee.h"


Employee::Employee(int id, int did, string name)
{
	this->m_Id = id;
	this->m_DeptId = did;
	this->m_Name = name;
}

void Employee::showInfo()
{
	cout << "职工编号:" << this->m_Id << "\t职工名字:" << this->m_Name << "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:" << this->getDeptDuty() << endl;
}

string Employee::getDeptName()
{
	return string("普通员工");
}

string Employee::getDeptDuty()
{
	return string("完成经理的任务");
}
