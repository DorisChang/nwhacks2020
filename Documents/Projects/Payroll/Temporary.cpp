#include "Temporary.h"

Temporary::Temporary()
{
	employeeId = 0;
	employeeName = "Frank Richardson";
	totalPay = 0.0;
	regularPay = 0.0;
	bonusPay = 0.0;
}

Temporary::~Temporary()
{
}

void Temporary::processPayroll(int payperiod)
{
	int count = 0;
	if (payperiod < 0 || payperiod > 52)
	{
		totalPay = -1;
	}
	if (hours >= 20)
	{
		count++;

		if (hourlyRate < 12.00)
		{
			hourlyRate = 12.00;
		}
	}

	if (payperiod == 52)
	{
		bonusPay = count * 10.00;
		if (bonusPay > 500.00)
		{
			bonusPay = 500.00;
		}
	}

	totalPay = regularPay + bonusPay;
	regularPay = hourlyRate * hours;
}

string Temporary::employeeCategory()
{
	return "Temporary";
}

string Temporary::printPayroll()
{
	Temporary a;
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
