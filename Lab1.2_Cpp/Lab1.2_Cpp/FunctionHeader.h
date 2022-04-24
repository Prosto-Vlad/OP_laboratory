#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Customer
{
	string name_and_secondname;
	Date lastVisit;
	Date NextVisit;
};

Customer customer_fill();
Date date_fill();
void date_out(Date);
void edit_or_create(string);
vector<Customer> vec_customer_fill(vector<Customer>);