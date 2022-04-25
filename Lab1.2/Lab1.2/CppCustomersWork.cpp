#include "CppHeader.h"

Customer customer_fill()
{
	Customer cust;
	cout << "Write name and second name of castomer" << endl;
	cin >> cust.secondname;
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

vector<Customer>  vector_without_old_customers(string path)
{
	ifstream inFile(path, ios::binary);
	vector<Customer> customers;
	customers = write_file_data_in_vector(path);
	if (!inFile)
	{
		cout << "Error!";
	}
	else
	{
		for (int i = 0; i < customers.size(); i++)
		{
			if (is_old_cust(customers[i]))
			{
				customers.erase(customers.begin() + i);
			}
		}
	}
	inFile.close();
	return customers;
}

void delet_old_customers(string path)
{
	vector<Customer> customers = vector_without_old_customers(path);
	ofstream outFile(path, ios::binary);

	if (!outFile)
	{
		cout << "Error!";
	}
	else
	{
		for (int i = 0; i < customers.size(); i++)
		{
			outFile.write((const char*)&customers[i], sizeof(Customer));
		}
	}

	outFile.close();
}

bool is_old_cust(Customer cust)
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	bool chek = false;
	if (cust.NextVisit.year < time.wYear)
	{
		chek = true;
	}
	else
	{
		if (cust.NextVisit.year == time.wYear)
		{
			if (cust.NextVisit.month < time.wMonth)
			{
				chek = true;
			}
			else
			{
				if (cust.NextVisit.month == time.wMonth)
				{
					if (cust.NextVisit.day < time.wDay)
					{
						chek = true;
					}
				}
			}
		}
	}
	return chek;
}

void date_out(Date date)
{
	if (date.day >= 1 && date.day < 10) cout << '0' << date.day << '.';
	else cout << date.day << '.';
	if (date.month >= 1 && date.month < 10) cout << '0' << date.month << '.';
	else cout << date.month << '.';
	cout << date.year;
}

void customer_out(Customer cust)
{
	cout << cust.secondname  << " ";
	date_out(cust.lastVisit);
	cout << " ";
	date_out(cust.NextVisit);
	cout << endl;
}

vector<Customer> vec_customer_fill()
{
	int count_cust;
	cout << "How many customers you want to add?\n";
	cin >> count_cust;

	vector<Customer> customers;
	for (int i = 0; i < count_cust; i++)
	{
		customers.push_back(customer_fill());
	}

	return customers;
}

bool is_second_cust(Customer cust)
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	bool chek = false;
	if (cust.lastVisit.month == time.wMonth)
	{
		if (time.wDay - cust.lastVisit.day <= 10)
		{
			chek = true;
		}
	}
	else
	{
		if (time.wMonth - cust.lastVisit.month == 1)
		{
			if (cust.lastVisit.month == 2)
			{
				if (28 - cust.lastVisit.day + time.wDay <= 10)
				{
					chek = true;
				}
			}
			else if(cust.lastVisit.month == 1 || cust.lastVisit.month == 3 || cust.lastVisit.month == 5 || cust.lastVisit.month == 7 || cust.lastVisit.month == 8 || cust.lastVisit.month == 10 || cust.lastVisit.month == 12)
			{
				if (31 - cust.lastVisit.day + time.wDay <= 10)
				{
					chek = true;
				}
			}
			else
			{
				if (30 - cust.lastVisit.day + time.wDay <= 10)
				{
					chek = true;
				}
			}
		}
	}
	return chek;
}