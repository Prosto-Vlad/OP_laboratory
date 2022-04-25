#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Customer
{
	char secondname[40];
	Date lastVisit;
	Date NextVisit;
};

void edit_file(string);
void create_file(string);
vector<Customer>write_file_data_in_vector(string);
void out_file_data(string);
void delet_old_customers(string);
void make_second_customers_list(string, string, string);

Date date_fill();
void date_out(Date);
Customer customer_fill();
vector<Customer> vec_customer_fill();
void customer_out(Customer);
bool is_old_cust(Customer);
vector<Customer> vector_without_old_customers(string);
bool is_second_cust(Customer);


