#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Vector
{
private:
	int cordX;
	int cordY;
public:
	Vector() {};
	Vector(int, int);
	Vector(string);
	Vector operator-(Vector);
	Vector operator*(double);

	int getX();
	int getY();
	int findLenght();
	void print();
};

string stringInput();
bool isRightNumber(string);
