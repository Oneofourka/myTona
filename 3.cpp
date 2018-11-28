#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main()
{
	vector <string> urls;
	urls.push_back("http://mytona.com/index.html");
	urls.push_back("https://mytona.com:8080/");
	urls.push_back("mytona.com");

	for (string link : urls)
	{
		size_t tempIndex = 0;
		for (size_t i = 0; link[i] != '.' && i < link.size(); ++i)
		{
			if (link.substr(i, 3) == "://")
			{
				cout << "Protocol: " << link.substr(0, i);
				tempIndex = i + 3;
				break;
			}
		}
		if (!tempIndex)
			cout << "Protocol: http";
		size_t i;

		for (i = tempIndex; link[i] != ':' && link[i] != '/' && i < link.size(); ++i);

		cout << " Host: " << link.substr(tempIndex, i - tempIndex);

		tempIndex = i + 1;
		if (tempIndex >= link.size())
			--tempIndex;
		for (i = tempIndex; link[i] != '/' && link[i] != '.' && i < link.size(); ++i);

		if (link[tempIndex - 1] == ':')
			cout << " Port: " << link.substr(tempIndex, i - tempIndex);
		else 
			cout << " Port: 80";
		if (link[i] != '.')
			tempIndex = i + 1;

		if (tempIndex >= link.size())
			--tempIndex;
		for (i = tempIndex; link[i] != '.' && i < link.size(); ++i);
		if (link[i] == '.')
			cout << " Page: " << link.substr(tempIndex - 1, link.size() - tempIndex + 1);
		else
			cout << " Page: /";
		cout << endl;
	}
}