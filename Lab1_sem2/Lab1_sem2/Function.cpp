#include "Function.h"


void edit_file(string path)
{
	ofstream text;
	text.open(path, ios::app);
	if (!text)
	{
		cout << "Error";
	}
	else
	{
		string line;
		text_out(path);
		cout << "Write the new strings. To finish enter ctrl+z\n";
		cin.ignore();
		while (getline(cin, line, '\26'))
		{
			text << line;
		}
	}
	text.close();
}

void create_file(string path)
{
	ofstream text(path);
	if (!text)
	{
		cout << "Error";
	}
	else
	{
		string line;
		cout << "Write the text. To finish enter ctrl+z" << endl;
		cin.ignore();
		while (getline(cin, line, '\26'))
		{
			text << line;
		}
	}
	text.close();
}

void text_out(string path)
{
	ifstream text(path);
	if (!text)
	{
		cout << "Error";
	}
	else
	{
		string line;
		while (!text.eof())
		{
			getline(text, line);
			cout << line << endl;
		}
	}
	text.close();
}

void text_sort(string path, vector<string>& str)
{
	ifstream text(path);
	if (!text)
	{
		cout << "Error";
	}
	else
	{
		string line;
		while (!text.eof())
		{
			getline(text, line);
			str.push_back(line);
		}

		empty_delete(str);

		string temp = "";
		for (int i = 0; i < str.size() - 1; i++)
		{
			for (int j = 0; j < str.size() - 1; j++)
			{
				if (str[j].length() - count(str[j].begin(), str[j].end(), ' ') > str[j + 1].length() - count(str[j+1].begin(), str[j+1].end(), ' '))
				{
					temp = str[j];
					str[j] = str[j + 1];
					str[j + 1] = temp;
				}
			}
		}
	}
	text.close();
}

void empty_delete(vector<string>& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i].length() - count(str[i].begin(), str[i].end(), ' ') == 0)
		{
			str.erase(str.begin() + i);
		}
	}
}

void count_sym(string path, string pathNew, vector<string> str)
{
	ofstream newFile(pathNew);
	string line = "";
	for (int i = 0; i < str.size(); i++)
	{
		newFile << str[i] << " - " << to_string(str[i].size() - count(str[i].begin(), str[i].end(), ' ')) << '\n';
	}
	newFile.close();
}

