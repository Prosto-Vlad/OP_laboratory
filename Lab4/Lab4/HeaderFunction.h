#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tnumber
{
public:
	virtual int getSumNum() = 0;
	virtual int getFirstNum() = 0;
	virtual int getLastNum() = 0;
};

class TIntNumber : Tnumber
{
private:
	int number;
public:
	TIntNumber(){ number = 0; }
	TIntNumber(int);
	int getSumNum();
	int getFirstNum();
	int getLastNum();
	int getNumber();
};

class TRealNumber : Tnumber
{
private:
	double number;
public:
	TRealNumber() { number = 0; }
	TRealNumber(double);
	int getSumNum();
	int getFirstNum();
	int getLastNum();
	double getNumber();
};

vector<TIntNumber> makeIntVec(int);
vector<TRealNumber> makeRealVec(int);

void printVec(vector<TIntNumber>);
void printVec(vector<TRealNumber>);

int findFirstNumSum(vector<TIntNumber>);
int findLastNumSum(vector<TRealNumber>);
