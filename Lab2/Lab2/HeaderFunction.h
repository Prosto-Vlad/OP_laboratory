#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int X;
	int Y;
};

class Line
{
private:
	int a;
	int b;
	int c;
public:
	Line();
	Line(int, int, int);
	int GetA();
	int GetB();
	int GetC();
	bool isPointOnLine(Point);
};

vector<Line> createArray(int);
vector <int> findLineWithPoint(vector<Line> , Point );
Point enterPointCoordinates();
void printLineArray(vector<Line>);
void printArray(vector<int>);