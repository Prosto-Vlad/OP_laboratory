#include "FunctionHeader.h"

Customer customer_fill()
{
	Customer cust;
	cout << "Write name and second name of castomer" << endl;
	getline(cin, cust.name_and_secondname);
	cout << "Write date of last visit like dd.mm.yyyy" << endl;
	cust.lastVisit = date_fill();
	cout << "Write date of next visit like dd.mm.yyyy" << endl;
	cust.NextVisit = date_fill();
	return cust;
}

Date date_fill()
{
	Date date;
	cin >> date.day;
	cin.ignore();
	cin >> date.month;
	cin.ignore();
	cin >> date.year;
	cin.ignore();
	while (date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 0)
	{
		cout << "You write incorect date! Please, check your date and write again." << endl;
		cin >> date.day;
		cin.ignore();
		cin >> date.month;
		cin.ignore();
		cin >> date.year;
		cin.ignore();
	}
	return date;
}

void date_out(Date date)
{
	if (date.day >= 1 && date.day < 10) cout << '0' << date.day << '.';
	else cout << date.day << '.';
	if (date.month >= 1 && date.month < 10) cout << '0' << date.month << '.';
	else cout << date.month << '.';
	cout << date.year << endl;
}

void edit_or_create(string path)
{
	int choice;
	cout << "You want to edit or overwrite the file?\n1 - edit\n2 - owerwrite\n";
	cin >> choice;

	while (choice < 1 && choice > 2)
	{
		cout << "You enter the wrong number! Please enter 1 or 2";
		cin >> choice;
	}
	if (choice == 1) edit_file(path);
	else create_file(path);
}

void edit_file(string path)
{

}

void create_file(string path)
{
	vector<Customer> customers;

	ofstream outFile(path, ios::binary);

	if (!outFile)
	{
		cout << "Error!";
	}
	else
	{
		
	}
}

vector<Customer> vec_customer_fill(vector<Customer> cust)
{
	int count_cust;
	cout << "How many customers?";
	cin >> count_cust;
}