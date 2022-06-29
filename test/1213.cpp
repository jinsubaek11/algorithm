#include <bits/stdc++.h>
using namespace std;

int cnt[200], flag;
char mid;
string s, ret;

int main()
{
	cin >> s;
	for (char a : s) cnt[a]++;

	for (int i = 'Z'; i >= 'A'; --i)
	{
		if (cnt[i])
		{
			if (cnt[i] & 1)
			{
				mid = (char)i;
				cnt[i]--;
				flag++;
			}
			if (flag == 2) break;

			for (int j = 0; j < cnt[i]; j+=2)
			{
				ret = (char)i + ret;
				ret += (char)i;
			}
		}
	}

	if (mid)
	{
		ret.insert(ret.begin() + ret.size() / 2, mid);
	}
	if (flag == 2)
	{
		cout << "I'm Sorry Hansoo\n";
	}
	else 
	{
		cout << ret << "\n";
	}

	return 0;
}