#include <iostream>
#include "employee.h"

using namespace std;

int main()
{
	// create and populate an employee
	Employee HR;
	HR.firstInitial = 'F';
	HR.lastInitial = 'D';
	HR.employeeNumber = 42;
	HR.salary = 80000;
	HR.title = Title::Manager;


	// output the values of an employee
	cout << "Employee: " << HR.firstInitial << HR.lastInitial << endl;
	cout << "Number: " << HR.employeeNumber << endl;
	cout << "Salary:" << HR.salary << endl;

	switch (HR.title)
	{
		case Title::Manager:
			cout << "Engineer" << endl;
			break;
		case Title::SeniorEngineer:
			cout << "Senior Engineer" << endl;
			break;
		case Title::Engineer:
			cout << "Manager" << endl;
			break;
	}
}
