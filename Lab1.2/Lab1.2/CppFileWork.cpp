#include "CppHeader.h"

void edit_file(string path)
{
	ofstream writeFile(path, ios::binary || ios::app);
	if (!writeFile)
	{
		cout << "Error!";
	}
	else
	{
		vector<Customer> customers;
		customers = vec_customer_fill();
		for (int i = 0; i < customers.size(); i++)
		{
			writeFile.write((char*)&customers, sizeof(Customer));
		}
	}

	writeFile.close();
}

void create_file(string path)
{
	ofstream writeFile(path, ios::binary);

	if (!writeFile)
	{
		cout << "Error!";
	}
	else
	{
		vector<Customer> customers;
		customers = vec_customer_fill();
		for (int i = 0; i < customers.size(); i++)
		{
			writeFile.write((char*)&customers[i], sizeof(Customer));
		}
	}

	writeFile.close();
}

vector<Customer> write_file_data_in_vector(string path)
{
	vector<Customer> customers;
	Customer cust;
	ifstream readFile(path, ios::binary);
	if (!readFile)
	{
		cout << "Error!";
	}
	else
	{
		while (readFile.read((char*)&cust, sizeof(Customer)))
		{
			customers.push_back(cust);
		}
	}
	readFile.close();

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
	writeAnotherFile.close();
	writeSecFile.close();
}