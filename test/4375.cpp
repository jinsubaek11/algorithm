#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)

int n;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		int cnt = 1, ret = 1;
		while (cnt % n != 0)
		{
			cnt = cnt * 10 + 1;
			cnt %= n;
			ret++;
		}

		cout << ret << endl;
	}

	return 0;
}