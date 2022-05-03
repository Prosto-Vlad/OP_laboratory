#include <iostream>
#include "Function.h"

using namespace std;

int main()
{
	string path = ("Text.txt");
	string pathNew = ("NewText.txt");
	vector<string> str;
	int choice;

	cout << "You want to edit or overwrite the file?\n1 - edit\n2 - owerwrite\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		edit_file(path);
		break;
	case 2:
		create_file(path);
		break;
	default:
		cout << "You enter the wrong number!";
		return 0;
	}

	text_sort(path, str);
	count_sym(path,  pathNew, str);

	cout << "New text:\n";
	text_out(pathNew);
}

