#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include "Salary.h"
using namespace std;

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

class Executive: public Salary
{
public:
	Executive();
	~Executive();

	void processPayroll(int);
	string employeeCategory();
	string printPayroll();


};

#endif