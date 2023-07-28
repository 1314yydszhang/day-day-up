#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>
#define FILENAME "empfile.txt"
class WorkerManager

{
public:
	//构造函数
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
	//析构函数
	~WorkerManager();
};
