#include "employee.h"


Employee::Employee(int id, int did, string name)
{
	this->m_Id = id;
	this->m_DeptId = did;
	this->m_Name = name;
}

void Employee::showInfo()
{
	cout << "ְ�����:" << this->m_Id << "\tְ������:" << this->m_Name << "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:" << this->getDeptDuty() << endl;
}

string Employee::getDeptName()
{
	return string("��ͨԱ��");
}

string Employee::getDeptDuty()
{
	return string("��ɾ��������");
}
