#include "manager.h"

Manager::Manager(int id, int did, string name)
{
	this->m_Id = id;
	this->m_DeptId = did;
	this->m_Name = name;
}

void Manager::showInfo()
{
	cout << "ְ�����:" << this->m_Id << "\tְ������:" << this->m_Name << "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:" << this->getDeptDuty() << endl;
}

string Manager::getDeptName()
{
	return string("����");
}

string Manager::getDeptDuty()
{
	return string("����ϰ�����");
}
