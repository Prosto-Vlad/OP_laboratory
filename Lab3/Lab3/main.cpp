#include "FunctionHeader.h"

int main()
{
	string str;

	cout << "Endter first vector coordinates in this format - X,Y" << endl;
	str = stringInput();
	Vector V1(str);

	cout << "Endter second vector coordinates in this format - X,Y" << endl;
	str = stringInput();
	Vector V2(str);

	V1 = V1 * 2;
	cout << "V1";
	V1.print();

	cout << "V2";
	V2.print();

	Vector V3 = V1 - V2;
	cout << "V3";
	V3.print();

	cout << "Lenght V3 = ";
	cout << V3.findLenght();
}