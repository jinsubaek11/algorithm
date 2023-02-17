#include <iostream>

using namespace std;

int n;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num = i;
		int sum = 0;

		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}

		if (sum + i == n)
		{
			cout << i << endl;
			break;
		}
	}

	cout << 0 << endl;

	return 0;
}