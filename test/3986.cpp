#include <bits/stdc++.h>
using namespace std;
int n, cnt, i;
char m;
string word;

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> word;
		stack<char> stk;

		for (char a: word)
		{
			if (stk.size() && stk.top() == a)
			{
				stk.pop();
			}
			else {
				stk.push(a);
			}
		}

		if (stk.size() == 0) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}