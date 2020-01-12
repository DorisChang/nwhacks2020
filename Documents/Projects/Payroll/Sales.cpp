#include "Sales.h"

Sales::Sales()
{
	employeeId = 0;
	employeeName = "Frank Richardson";
	totalPay = 0.0;
	regularPay = 0.0;
	bonusPay = 0.0;
	commissionPay = 0.0;
	drawPay = 0.0;
	drawAdjustment = 0.0;
	drawAccount = 0.0;
}

Sales::~Sales()
{
}

void Sales::processPayroll(int payperiod)
{

	if (payperiod < 0 || payperiod > 52)
	{
		totalPay = -1;
	}

	commissionPay = lastQsales / 13;

	if (commissionPay < 1000.00)
	{
		regularPay = 1000.00;
		drawPay = 1000.00 - commissionPay;
		drawAccount = drawAccount - drawPay;
		drawAdjustment = 0 - drawPay;
	}


	if (commissionPay >= 1000.00)
	{
		double surplus = commissionPay - 1000.00;
		if (drawAccount < 0)
		{
			if (surplus > 0 - drawAccount)
			{
				regularPay = commissionPay+drawAccount;
				drawPay = drawAccount;
				drawAccount = 0;
				drawAdjustment = 0 - drawPay;
			}
			else
			{
				regularPay = 1000.00;
				drawPay = 0 - surplus;
				drawAccount = drawAccount + surplus;
				drawAdjustment = 0 - drawPay;
			}
			
		}
		else regularPay = commissionPay;
	}

	if (regularPay > 1000)
	{
		double surplus = regularPay - 1000.00;
		double percentage = commissionPay * 0.1;
		if (percentage > surplus)
		{
			regularPay = 1000.00;
			drawPay = drawPay - surplus;
			drawAccount = drawAccount + surplus;
			drawAdjustment = 0 - drawPay;
		}

		else
		{
			regularPay = regularPay - percentage;
			drawPay = drawPay - percentage;
			drawAccount = drawAccount + percentage;
			drawAdjustment = 0 - drawPay;
		}
	}


	if (payperiod % 13 == 0)
	{
		if (payperiod == 52)
		{
			bonusPay = (lastQsales - lastQgoal) * 0.05;
			totalPay = regularPay + bonusPay;
		}
		else
		{
			bonusPay = (lastQsales - lastQgoal) * 0.03;
			totalPay = regularPay + bonusPay;
		}
		
	}
	else 
		{ 
			bonusPay = 0.0;
			totalPay = regularPay + bonusPay;
		}

}

string Sales::employeeCategory()
{
	return "Sales";
}

string Sales::printPayroll()
{
	Sales a;
	string one = "Total Pay -";
	string two = "Commission -";
	string three = "Draw Pay -";
	string four = "Bonus -";
	string five = "Draw Account -";
	string six = "Draw Adjust -";
	string space1 = "     ";
	string space2 = "          ";
	string line1 = to_string(a.employeeId) + space1 + a.employeeName + space1 + a.employeeCategory() + " \n";
	string line2 = space1 + one + space2 + to_string(a.totalPay) + " \n";
	string line3 = space1 + two + space2 + to_string(a.commissionPay) + " \n";
	string line4 = space1 + three + space2 + to_string(a.drawPay) + " \n";
	string line5 = space1 + four + space2 +to_string(a.bonusPay) + " \n";
	string line6 = space1 + five + space2 + to_string(a.drawAccount) + " \n";
	string line7 = space1 + six + space2 + to_string(a.drawAdjustment) + " \n";

	string table = line1 + line2 + line3 + line4 + line5 + line6 +line7;

	return table;
}