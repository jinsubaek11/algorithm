#include <iostream>
#include <vector>

using namespace std;

int n, ret = -987654321;
string s;
vector<int> num;
vector<char> sign;

int calc(char sign, int a, int b)
{
	if (sign == '+') return a + b;
	if (sign == '-') return a - b;
	if (sign == '*') return a * b;
}

void solve(int index, int val)
{
	if (index == num.size() - 1)
	{
		ret = max(ret, val);
		return;
	}

	solve(index + 1, calc(sign[index], val, num[index + 1]));

	if (index + 2 <= num.size() - 1)
	{
		int nextVal = calc(sign[index + 1], num[index + 1], num[index + 2]);
		solve(index + 2, calc(sign[index], val, nextVal));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (!(i & 1))
		{
			num.push_back(s[i] - '0');
		}
		else
		{
			sign.push_back(s[i]);
		}
	}

	solve(0, num[0]);

	cout << ret;

	return 0;
}