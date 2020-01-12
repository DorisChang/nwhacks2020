#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

 class Employee
{
public:
	Employee();
	~Employee();
	virtual void processPayroll (int) = 0;
	virtual string printPayroll () = 0;
	virtual string employeeCategory () = 0;

protected:
	int employeeId;
	string employeeName;
	double totalPay;
	double regularPay;
	double bonusPay;

friend class EmployeeFactory;

};

#endif