#include <iostream>
#include "FunctionHeader.h"

using namespace std;

int main()
{
	string Path = "AllCustomers.txt";
	string SecPath = "SecondCustomers.txt";
	string AnotherPath = "AnotherCustomers.txt";
	int choice;

	Customer cust = customer_fill();

	cout << cust.name_and_secondname << endl;
	cout << "Last visit: ";
	date_out(cust.lastVisit);
	cout << "Next visit: ";
	date_out(cust.NextVisit);
}

