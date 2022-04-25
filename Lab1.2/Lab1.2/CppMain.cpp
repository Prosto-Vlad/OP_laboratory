#include "CppHeader.h"

using namespace std;

int main()
{
	string Path = "AllCustomers.txt";
	string SecPath = "SecondCustomers.txt";
	string AnotherPath = "AnotherCustomers.txt";

	int choice;
	cout << "You want to edit or overwrite the file?\n1 - edit\n2 - owerwrite\n";
	cin >> choice;

	while (choice < 1 && choice > 2)
	{
		cout << "You enter the wrong number! Please enter 1 or 2";
		cin >> choice;
	}
	if (choice == 1) edit_file(Path);
	else create_file(Path);

	out_file_data(Path);
	cout << endl;

	delet_old_customers(Path);
	cout << "Customers list without old customers" << endl;
	out_file_data(Path);
	cout << endl;

	make_second_customers_list(Path, SecPath, AnotherPath);
	cout << "Second customers list" << endl;
	out_file_data(SecPath);
	cout << endl;

	cout << "Another customers list" << endl;
	out_file_data(AnotherPath);
	cout << endl;
}
