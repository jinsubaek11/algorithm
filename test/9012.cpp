#include <bits/stdc++.h>
using namespace std;

int t;
string s;

bool Check(string s)
{
	stack<char> st;

	for (int j = 0; j < s.size(); j++)
	{
		if (s[j] == '(')
		{
			st.push(s[j]);
		}
		else
		{
			if (!st.empty())
			{
				st.pop();
			}
			else
			{
				return false;
			}
		}
	}

	return st.empty();
}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> s;
		

		if (Check(s))
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}

	return  0;
}