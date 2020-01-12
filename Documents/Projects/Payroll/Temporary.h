#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include "Hourly.h"
using namespace std;

#ifndef TEMPORARY_H
#define TEMPORARY_H

class Temporary: public Hourly
{
public:
	Temporary();
	~Temporary();
	void processPayroll(int);
	string employeeCategory();
	string printPayroll();

};

#endif