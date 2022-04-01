#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main() {
	Database employeeDB;	//데이터베이스. 이곳에 직원 정보 저장.
	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			doDemote(employeeDB);
			break;
		case 5:
			employeeDB.displayAll();
			break;
		case 6:
			doHire(employeeDB);
			break;
		case 7:
			doHire(employeeDB);
			break;
		}
	}
	return 0;
}
int displayMenu() {
	int selection;
	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1)Hire a new Employee" << endl;
	cout << "2)Fire a new Employee" << endl;
	cout << "3)Promote an Employee" << endl;
	cout << "4)Demote an Employee" << endl;
	cout << "5)List all Employee" << endl;
	cout << "6)List all current Employee" << endl;
	cout << "7)List all former Employee" << endl;
	cout << "0)Quit" << endl;
	cout << endl << endl;
	cout << "--->";
	cin >> selection;
	return selection;
}
void doHire(Database& db) {
	string firstName;
	string lastName;
	cout << "First Name : ";
	cin >> firstName;

	cout << "Last Name : ";
	cin >> lastName;

	db.addEmployee(firstName, lastName);
}
void doFire(Database& db) {
	int employeeNumber;
	cout << "Employee number :";
	cin >> employeeNumber;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employe" << employeeNumber << "Terminatd." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to terminate  employee: " << exception.what() << endl;
	}
}
void doPromote(Database& db) {
	int employeeNumber;
	int raiseAmount;

	cout << "Employee number  : ";
	cin >> employeeNumber;

	cout << "raise Amount :";
	cin >> raiseAmount;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to promote employee: " << exception.what() << endl;
	}
}
void doDemote(Database& db) {
	int employeeNumber;
	int demeritAmount;

	cout << "Employee number  : ";
	cin >> employeeNumber;

	cout << "raise Amount :";
	cin >> demeritAmount;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(demeritAmount);
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to promote employee: " << exception.what() << endl;
	}
}

