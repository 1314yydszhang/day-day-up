#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>
#define FILENAME "empfile.txt"
class WorkerManager

{
public:
	//���캯��
	WorkerManager();
	void ShowMenu();
	void ExitSystem();
	void AddEmp();
	void Save();
	int m_EmpNum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;
	int getEmpNum();
	void InitEmp();
	void ShowEmp();
	//��������
	~WorkerManager();
};
