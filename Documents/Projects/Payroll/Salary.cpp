#include "Salary.h"

Salary::Salary()
{
	employeeId = 0;
	employeeName = "Frank Richardson";
	totalPay = 0.0;
	regularPay = 0.0;
	bonusPay = 0.0;
}


Salary::~Salary()
{
}

void Salary::processPayroll(int payperiod)
{	
	if (payperiod < 1 && payperiod > 52)
		totalPay = -1;

	if (salaryPay < 575.00)
		totalPay = -1;

	if (payperiod > 0 && payperiod < 52)
	{
		salaryPay = regularPay;
		bonusPay = 0.0;
		totalPay = regularPay + bonusPay;
	}

	else if (payperiod == 52)
	{
		bonusPay = regularPay * 52 * .05;
		totalPay = regularPay + bonusPay;
	}
}

string Salary::employeeCategory()
{
	return "Salary";
}

string Salary::printPayroll()
{
	Salary a;
	string one = "Total Pay -";
	string two = "Regular Pay -";
	string three = "Year Bonus -";
	string space1 = "     ";
	string space2 = "          ";
	string line1 = to_string(a.employeeId) + space1 + a.employeeName + space1 + a.employeeCategory() + " \n";
	string line2 = space1 + one + space2 + to_string(a.totalPay) + " \n";
	string line3 = space1 + two + space2 + to_string(a.regularPay) + " \n";
	string line4 = space1 + three + space2 + to_string(a.bonusPay) + " \n";

	string table = line1 + line2 + line3 + line4;

	return table;
}
