#include "boss.h"
Boss::Boss(int id, int did, string name)
{
	this->m_Id = id;
	this->m_DeptId = did;
	this->m_Name = name;
}

void Boss::showInfo()
{
	cout << "ְ�����:" << this->m_Id << "\tְ������:" << this->m_Name << "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:" << this->getDeptDuty() << endl;
}

string Boss::getDeptName()
{
	return string("�ϰ�");
}

string Boss::getDeptDuty()
{
	return string("��ɹ�˾����");
}