#include "HeaderFunction.h"

Line::Line()
{

}

Line::Line(int numA, int numB, int numC)
{
	a = numA;
	b = numB;
	c = numC;
}

int Line::GetA()
{
	return a;
}

int Line::GetB()
{
	return b;
}

int Line::GetC()
{
	return c;
}

vector<Line> createArray(int size)
{
	vector<Line> array(size);
	int a, b, c;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter numbers a, b and c" << endl;
		cin >> a;
		cin >> b;
		cin >> c;

		array[i] = Line(a, b, c);
	}

	return array;
}

void printLineArray(vector<Line> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		cout << "Line " << i + 1 << ": " << array[i].GetA() << "*x + " << array[i].GetB() << "*y + " << array[i].GetC() << endl;
	}
}

void printArray(vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

vector <int> findLineWithPoint(vector<Line> array, Point point)
{
	vector<int> numbOfLines;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i].isPointOnLine(point))
		{
			numbOfLines.push_back(i + 1);
		}
	}
	return numbOfLines;
}

bool Line::isPointOnLine(Point point)
{
	bool chek = false;

	if (a * point.X + b * point.Y + c == 0)
	{
		chek = true;
	}

	return chek;
}

Point enterPointCoordinates()
{
	Point temp;
	cout << "Enter point`s coordinate x = ";
	cin >> temp.X;
	cout << "Enter point`s coordinate y = ";
	cin >> temp.Y;
	return temp;
}