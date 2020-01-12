#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

#ifndef SALARY_H
#define SALARY_H

class Salary: public Employee
{
public:
	Salary();
	~Salary();

	void processPayroll(int);
	string employeeCategory();
	string printPayroll();

protected:
	double salaryPay;
};

#endif // SALARY_H