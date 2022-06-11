#include "HeaderFunction.h"
//TIntNumber
TIntNumber::TIntNumber(int number)
{
	this->number = number;
}
int TIntNumber::getSumNum()
{
	string str = to_string(number);
	int summa = 0;

	for (int i = 0; i < str.length(); i++)
	{
		summa += str[i] - '0'; 
	}

	return summa;
}
int TIntNumber::getFirstNum()
{
	string str = to_string(number);
	if(str[0] == '-') return (str[1] - '0')*(-1);
	else return str[0] - '0';
}
int TIntNumber::getLastNum()
{
	string str = to_string(number);
	return str[str.length() - 1] - '0';
}
int TIntNumber::getNumber()
{
	return number;
}


//TRealNumber
TRealNumber::TRealNumber(double number)
{
	this->number = number;
}
int TRealNumber::getSumNum()
{
	string str = to_string(number);
	int summa = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '.') { summa += str[i] - '0'; }
	}

	return summa;
}
int TRealNumber::getFirstNum()
{
	string str = to_string(number);
	if (str[0] == '-') return (str[1] - '0') * (-1);
	else return str[0] - '0';
}
int TRealNumber::getLastNum()
{
	string str = to_string(number);
	return str[str.length() - 1] - '0';
}
double TRealNumber::getNumber()
{
	return number;
}


//Function
vector<TIntNumber> makeIntVec(int size)
{
	srand(time(NULL));
	vector<TIntNumber> vec;
	for (int i = 0; i < size; i++)
	{
		vec.push_back((rand() % 100 - (-100) + 1) + (-100));
	}
	return vec;
}
vector<TRealNumber> makeRealVec(int size)
{
	srand(time(NULL));
	vector<TRealNumber> vec;
	for (int i = 0; i < size; i++)
	{
		vec.push_back((double)(rand())/RAND_MAX*(100 - (-100) +1) +  (-100));
	}
	return vec;
}

void printVec(vector<TIntNumber> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].getNumber() << " ";
	}
	cout << endl;
}
void printVec(vector<TRealNumber> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].getNumber() << " ";
	}
	cout << endl;
}

int findFirstNumSum(vector<TIntNumber> vec)
{
	int summa = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		summa += vec[i].getFirstNum();
	}
	return summa;
}

int findLastNumSum(vector<TRealNumber> vec)
{
	int summa = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		summa += vec[i].getLastNum();
	}
	return summa;
}