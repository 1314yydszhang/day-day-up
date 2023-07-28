#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Employee :public Worker
{
public:
	Employee(int id ,int did,string name);
	virtual void showInfo();
	virtual string getDeptName();
	virtual string getDeptDuty();
};