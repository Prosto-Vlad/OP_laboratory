#include "FunctionHeader.h"

Vector::Vector(int x, int y)
{
	cordX = x;
	cordY = y;
}

Vector::Vector(string str)
{
	int indx , test = str.length();
	indx = str.find(',');
	cordX = atoi(str.substr(0, indx).c_str());
	cordY = atoi(str.substr(indx+1).c_str());
}

Vector Vector::operator-(Vector vec2)
{
	Vector temp;
	temp.cordX = cordX - vec2.cordX;
	temp.cordY = cordY - vec2.cordY;

	return temp;
}

Vector Vector::operator*(double num)
{
	Vector temp;
	temp.cordX = cordX * num;
	temp.cordY = cordY * num;
	return temp;
}

void Vector::print()
{
	cout << '(' << cordX << ',' << cordY << ')' << endl;
}

int Vector::getX()
{
	return cordX;
}

int Vector::getY()
{
	return cordX;
}

int Vector::findLenght()
{
	double lenght = sqrt(pow(cordX, 2) + pow(cordY, 2));
	return lenght;
}

string stringInput()
{
	string str;
	getline(cin, str);
	while (count(str.begin(), str.end(), ',') != 1 || !isRightNumber(str))
	{
		cout << "Error of data type! Try again." << endl;
		getline(cin, str);
	}

	return str;
}

bool isRightNumber(string str)
{
	bool chek = true;
	for (int i = 0; i < str.find(','); i++)
	{
		if (str[i] == '-' && i == 0) continue;
		if (!isdigit(str[i]))
		{
			chek = false;
		}
	}
	for (int i = str.find(',') + 1; i < str.length(); i++)
	{
		if (str[i] == '-' && i == str.find(',') + 1) continue;
		if (!isdigit(str[i]))
		{
			chek = false;
		}
	}
	return chek;
}
