#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string str, numStr;

vector<string> vs;

bool cmp(string a, string b)
{
	if (a.size() == b.size()) return a < b;
	return  a.size() < b.size();
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		numStr = "";
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] < 58)
			{
				numStr += str[j];

				if (j == str.size() - 1)
				{	
					vs.push_back(numStr);
				}

				if (numStr.front() == '0')
				{
					numStr.erase(numStr.begin());
				}
			}
			else 
			{
				if (numStr.size())
				{
					while (true)
					{
						if (numStr.front() == '0')
						{
							numStr.erase(numStr.begin());
						}
						else
						{
							break;
						}
					}
					if (numStr.size() == 0)
					{
						numStr = "0";
					}

					vs.push_back(numStr);
				}
				numStr = "";
				continue;
			}
		}
	}

	sort(vs.begin(), vs.end(), cmp);

	for (int i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << endl;
	}

	return 0;
}