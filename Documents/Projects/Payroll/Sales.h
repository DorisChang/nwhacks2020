#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

#ifndef SALES_H
#define SALES_H

class Sales : public Employee
{
public:
	Sales();
	~Sales();

	void processPayroll(int);
	string employeeCategory();
	string printPayroll();

private:
	double commissionPay;
	double drawPay;
	double drawAdjustment;
	double drawAccount;
	double lastQsales;
	double lastQgoal;
	double annualSales;
	double annualGoal;

};

#endif
