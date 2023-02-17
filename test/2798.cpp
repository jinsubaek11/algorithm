#include <iostream>

using namespace std;

int n, m, sub, answer;
int cards[102];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}

	sub = 987654321;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int sum = cards[i] + cards[j] + cards[k];
				if (sum > m) continue;

				if (sub >= m - sum)
				{
					sub = m - sum;
					answer = sum;
				}
			}
		}
	}

	cout << answer << endl;

	return 0;
}