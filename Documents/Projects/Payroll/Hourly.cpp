#include "Hourly.h"

Hourly::Hourly()
{
	employeeId = 0;
	employeeName = "Frank Richardson";
	totalPay = 0.0;
	regularPay = 0.0;
	bonusPay = 0.0;
	overtimePay = 0.0;
}

Hourly::~Hourly ()
{
}

void Hourly::processPayroll(int payperiod)
{
	if (payperiod < 0 || payperiod > 52)
	{
		totalPay = -1;
	}

	if (hourlyRate <12.00)
	{
		hourlyRate = -1;
	}

	if (hours > 80)
	{
		totalPay = -1;
	}
	else if (hours > 40.00 && hours <= 80.00)
	{
		regularPay = 40.00 * hourlyRate;
		overtimePay = (hours - 40.00) * hourlyRate * 1.5;
	}
	else
	{
		regularPay = hours * hourlyRate;
		overtimePay = 0.0;
	}

	if (payperiod != 52)
	{
		bonusPay = 0.0;
	}
	else
	{
		bonusPay = 500.00;
	}

	totalPay = regularPay + overtimePay + bonusPay;
}

string Hourly::employeeCategory()
{
	return "Hourly";
}

string Hourly::printPayroll()
{
	Hourly a;
	string one = "Total Pay -";
	string two = "Regular Pay -";
	string three = "Overtime Pay -";
	string four = "Year Bonus -";
	string space1 = "     ";
	string space2 = "          ";
	string line1 = to_string(a.employeeId) + space1 + a.employeeName + space1 + a.employeeCategory() + " \n";
	string line2 = space1 + one + space2 + to_string(a.totalPay) + " \n";
	string line3 = space1 + two + space2 + to_string(a.regularPay) + " \n";
	string line4 = space1 + three + space2 + to_string(a.overtimePay) + "\n";
	string line5 = space1 + four + space2 + to_string(a.bonusPay) + " \n";
	string table = line1 + line2 + line3 + line4 + line5;

	return table;
}


