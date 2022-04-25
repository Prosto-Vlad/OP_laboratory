#include "CppHeader.h"

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
	ofstream outFile(path, ios::binary || ios::app);
	if (!outFile)
	{
		cout << "Error!";
	}
	else
	{
		vector<Customer> customers;
		customers = vec_customer_fill();
		for (int i = 0; i < customers.size(); i++)
		{
			outFile.write((char*)&customers, sizeof(Customer));
		}
	}

	outFile.close();
}

void create_file(string path)
{
	ofstream outFile(path, ios::binary);

	if (!outFile)
	{
		cout << "Error!";
	}
	else
	{
		vector<Customer> customers;
		customers = vec_customer_fill();
		for (int i = 0; i < customers.size(); i++)
		{
			outFile.write((char*)&customers[i], sizeof(Customer));
		}
	}

	outFile.close();
}

vector<Customer> write_file_data_in_vector(string path)
{
	vector<Customer> customers;
	Customer cust;
	ifstream inFile(path, ios::binary);
	if (!inFile)
	{
		cout << "Error!";
	}
	else
	{
		while (inFile.read((char*)&cust, sizeof(Customer)))
		{
			customers.push_back(cust);
		}
	}
	inFile.close();

	return customers;
}

void out_file_data(string path)
{
	vector<Customer> customers = write_file_data_in_vector(path);
	for (int i = 0; i < customers.size(); i++)
	{
		customer_out(customers[i]);
	}
}

void make_second_customers_list(string path, string secPath, string anotherPath)
{
	ifstream readFile(path, ios::binary);
	ofstream writeSecFile(secPath, ios::binary);
	ofstream writeAnotherFile(anotherPath, ios::binary);

	vector<Customer> customers = write_file_data_in_vector(path);
	for (int i = 0; i < customers.size(); i++)
	{
		if (is_second_cust(customers[i]))
		{
			writeSecFile.write((char*)&customers[i], sizeof(Customer));
		}
		else
		{
			writeAnotherFile.write((char*)&customers[i], sizeof(Customer));
		}
	}
}