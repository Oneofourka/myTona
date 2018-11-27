#include <iostream>
#include <string>
#include <conio.h> //for getche
#include <vector>

using namespace std;

void main()
{
	string str;
	cout << "Enter string " << endl;
	cin >> str;

	char symbol;
	cout << endl << "Enter symbol " << endl;
	symbol = _getche();	//getche is only needed for entering one symbol and exiting then from entering
	cout << endl << endl;

	vector <string> myVector;
	size_t i0 = 0;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (symbol == str[i])
			if (i0 == i)
			{
				++i0;
				continue;
			}
			else
			{
				myVector.push_back(str.substr(i0, i - i0));
				i0 = i + 1;
			}
		else if (i == str.size() - 1 && i0 != 0)
			myVector.push_back(str.substr(i0, str.size() - i0));
	}
	if (myVector.size() == 0)
		if (i0 == 0)
			cout << "In the string won't find the symbol" << endl;
		else
			cout << "The all line is filled this symbol" << endl;
	else
	{
		cout << "Substrings : " << endl;
		for (string i : myVector)
			cout << i << endl;
	}
	cout << endl;
//	cout << "size = " << myVector.size() << endl;
	myVector.clear();
}
