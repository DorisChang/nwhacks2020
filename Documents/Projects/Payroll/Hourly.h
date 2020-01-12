#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

#ifndef HOURLY_H
#define HOURLY_H

class Hourly :public Employee
{
public:
	Hourly();
	~Hourly();
	void processPayroll(int);
	string employeeCategory();
	string printPayroll();


protected:
	double hours;
	double hourlyRate;
	double overtimePay;

};

#endif