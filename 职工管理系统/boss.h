#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Boss :public Worker
{
public:
	Boss(int id, int did, string name);
	virtual void showInfo();
	virtual string getDeptName();
	virtual string getDeptDuty();
};
