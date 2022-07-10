#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{

	cin >> n;
	
	m = 666;

	while (n != 0)
	{
		if (to_string(m).find("666") != string::npos)
		{
			n--;
		}

		m++;
	}

	cout << m - 1;

	return 0;
}