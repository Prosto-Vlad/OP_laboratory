#include "HeaderFunction.h"

int main()
{
	Point point = enterPointCoordinates();
	int size;
	cout << "How many lines you want?" << endl;
	cin >> size;
	vector<Line> array = createArray(size);
	printLineArray(array);
	vector<int> numbOfLines = findLineWithPoint(array, point);
	cout << "Line numbers" << endl;
	printArray(numbOfLines);
	return 0;
}