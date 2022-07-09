#include<bits/stdc++.h>
using namespace std;

int n;
char a[65][65];
string s;

string quad(int y, int x, int size)
{
	if (size == 1) return string(1, a[y][x]);
	char b = a[y][x];
	string ret = "";

	for (int y1 = y; y1 < y + size; ++y1)
	{
		for (int x1 = x; x1 < x + size; ++x1)
		{
			if (b != a[y1][x1])
			{
				ret += "(";
				ret += quad(y, x, size / 2);
				ret += quad(y, x + size / 2, size / 2);
				ret += quad(y + size/2, x, size / 2);
				ret += quad(y+ size/2, x + size / 2, size / 2);
				ret += ")";

				return ret;
			}
		}
	}

	return string(1, a[y][x]);
}

int main()
{

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = s[j];
		}
	}

	cout << quad(0, 0, n) << endl;

	return 0;
}