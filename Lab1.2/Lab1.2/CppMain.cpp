#include "CppHeader.h"

using namespace std;

int main()
{
	string Path = "AllCustomers.txt";
	string SecPath = "SecondCustomers.txt";
	string AnotherPath = "AnotherCustomers.txt";

	edit_or_create(Path);
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
