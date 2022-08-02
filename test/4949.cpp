#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		string str;
		getline(cin, str);
		if (str == ".") break;

		stack<char> s;
		bool flag = false;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
			{
				s.push(str[i]);
			}
			else 
			{
				if (s.empty())
				{
					if (str[i] == ')' || str[i] == ']')
					{
						flag = true;
						break;
					}
				}
				else
				{
					if (s.top() == '(')
					{
						if (str[i] == ')')
						{
							s.pop();
						}
						else if (str[i] == ']')
						{
							flag = true;
							break;
						}
					}
					else if (s.top() == '[')
					{
						if (str[i] == ']')
						{
							s.pop();
						}
						else if (str[i] == ')')
						{
							flag = true;
							break;
						}
					}
				}
			}
		}
		
		if (!flag && s.empty())
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}

	}

	return 0;
}