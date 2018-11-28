#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void main()
{
	vector<string> myVector;

	string article = "input.txt";

	fstream fs;

	fs.open(article, fstream::in);

	if (!fs.is_open())
	{
		cout << "Error opening file" << endl;
		return;
	}
	else
	{
		while (!fs.eof())
		{
			string str;
			getline(fs, str);
			if (str != "\0")
				myVector.push_back(str);
		}
	}
	fs.close();

	article = "output.txt";
	fs.open(article, fstream::out | fstream::trunc);

	if (!fs.is_open())
	{
		cout << "Error opening file" << endl;
		return;
	}
	else
	{
		for (string str : myVector)
		{
			bool check = false;
			for (size_t i = 0; i < str.size(); ++i)
			{
				if (str[i] != ' ' && !isdigit(str[i]))
				{
					fs << str[i];
					check = true;
				}
			}
			if (str != myVector[myVector.size() - 1] && check)
				fs << "\n";			
		}
	}
	fs.close();
}