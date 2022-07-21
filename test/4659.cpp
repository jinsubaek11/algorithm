#include <iostream>
#include <cstring>
using namespace std;

int cnt[30], lcnt, vcnt;
string password;

bool IsVowel(int idx)
{
	return (idx == 0 || idx == 4 || idx == 8 || idx == 14 || idx == 20);
}

int main()
{
	while (true)
	{
		cin >> password;

		if (password == "end") break;

		memset(cnt, 0, sizeof(cnt));
		lcnt = vcnt = 0;
		bool flag = 0;

		for (int i = 0; i < password.size(); i++)
		{
			int idx = password[i] - 'a';
			cnt[idx]++;

			if (IsVowel(idx))
			{
				vcnt++;
				lcnt = 0;
			}
			else 
			{
				lcnt++;
				vcnt = 0;
			}

			if (vcnt == 3 || lcnt == 3) flag = 1;			
			if (i < password.size() && (password[i] == password[i + 1]) && (idx != 4 && idx != 14)) flag = 1;
		}
		if (!cnt[0] && !cnt[4] && !cnt[8] && !cnt[14] && !cnt[20]) flag = 1;

		if (flag)
			cout << "<" << password << ">" << " is not acceptable." << endl;
		else	
			cout << "<" << password << ">" << " is acceptable." << endl;
	}

	return 0;
}