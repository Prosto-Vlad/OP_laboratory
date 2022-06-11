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
	Vector() { cordX = 0; cordY = 0; };
	Vector(int, int);
	Vector(string);
	Vector operator-(Vector);
	Vector operator*(double);

	int getX();
	int getY();
	double findLenght();
	void print();
};

string stringInput();
bool isRightNumber(string);
