#include <iostream>
using namespace std;

int n, m, j, p, l, r, cnt;

int main()
{
	cin >> n >> m >> j;

	 l = 1;

	for (int i = 0; i < j; i++)
	{
		cin >> p;
		 r = l + m - 1;

		if (l <= p && p <= r) continue;
		else 
		{
			if (p < l)
			{
				cnt += (l - p);
				l = p;
			}
			else
			{
				cnt += (p - r);
				l += (p - r);
			}
		}
	}

	cout << cnt << endl;

	return 0;
}