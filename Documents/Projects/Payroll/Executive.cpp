#include "Executive.h"


Executive::Executive()
{
	employeeId = 0;
	employeeName = "Frank Richardson";
	totalPay = 0.0;
	regularPay = 0.0;
	bonusPay = 0.0;
}


Executive::~Executive()
{

}

void Executive::processPayroll(int payperiod)
{
	if (payperiod < 1 && payperiod > 52)
		totalPay = -1;

	if (salaryPay < 575.00)
		totalPay = -1;

	if (payperiod % 13 == 0)
	{
		if (payperiod == 52)
		{
			bonusPay = salaryPay * 52 * .05;
			totalPay = salaryPay + bonusPay;
		}
		else
		{
			bonusPay = salaryPay * 52 * .01;
			totalPay = salaryPay + bonusPay;
		}
	}
}

string Executive::employeeCategory()
{
	return "Executive";
}

string Executive::printPayroll()
{
	Executive a;
	string one = "Total Pay -";
	string two = "Regular Pay -";
	string three = "Bonus -";
	string space1 = "     ";
	string space2 = "          ";
	string line1 = to_string(a.employeeId) + space1 + a.employeeName + space1 + a.employeeCategory() + " \n";
	string line2 = space1 + one + space2 + to_string(a.totalPay) + " \n";
	string line3 = space1 + two + space2 + to_string(a.regularPay) + " \n";
	string line4 = space1 + three + space2 + to_string(a.bonusPay) + " \n"; //

	string table = line1 + line2 + line3 + line4;

	return table;
}
