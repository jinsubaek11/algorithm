#include <bits/stdc++.h>
using namespace std;

int n, m, a[15004], cnt;

int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (m > 200000)
	{
		cout << 0 << "\n";
	}
	else {
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] + a[j] == m) cnt++;
			}
		}

		cout << cnt;
	}


	return 0;
}