#include "HeaderFunction.h"

int main()
{
	int m, n;
	cout << "Enter size of int array" << endl;
	cin >> m;
	cout << "Enter size of real array" << endl;
	cin >> n;

	vector<TIntNumber> massInt = makeIntVec(m);
	vector <TRealNumber> massReal = makeRealVec(n);
	cout << "Intenger array" << endl;
	printVec(massInt);
	cout << "Real array" << endl;
	printVec(massReal);

	cout << "Sum of fist intenger = " << findFirstNumSum(massInt) << endl;
	cout << "Sum of fist real = " << findLastNumSum(massReal) << endl;
}