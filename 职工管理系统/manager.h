#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Manager :public Worker
{
public:
	Manager(int id, int did, string name);
	virtual void showInfo();
	virtual string getDeptName();
	virtual string getDeptDuty();
};
