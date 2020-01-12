#include <iostream>
#include "Employee.h"
#include "Hourly.h"
#include "Temporary.h"
#include "Salary.h"
#include "Executive.h"
#include "Sales.h"

using namespace std;

int main()
{
	Hourly myHourlyWorker;
	Temporary myTempWorker;
	Salary mySalaryWorker;
	Executive myExecutiveWorker;
	Sales mySalesWorker;

	Employee* p;

	int nwk = 52;
	myHourlyWorker.processPayroll(nwk);
	myTempWorker.processPayroll(nwk);
	mySalaryWorker.processPayroll(nwk);
	myExecutiveWorker.processPayroll(nwk);
	mySalesWorker.processPayroll(nwk);
	
	cout << myHourlyWorker.printPayroll() << endl;
	cout << myTempWorker.printPayroll() << endl;
	cout << mySalaryWorker.printPayroll() << endl;
	cout << myExecutiveWorker.printPayroll() << endl;
	cout << mySalesWorker.printPayroll() << endl;

	p = &myHourlyWorker;
	cout << p->printPayroll() << endl;

	p = &myTempWorker;
	cout << p->printPayroll() << endl;

	p = &mySalaryWorker;
	cout << p->printPayroll() << endl;

	p = &myExecutiveWorker;
	cout << p->printPayroll() << endl;

	p = &mySalesWorker;
	cout << p->printPayroll() << endl;

	system("pause");
	return 0;
}