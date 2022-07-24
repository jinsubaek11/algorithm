#include <iostream>
using namespace std;

int h, w,cnt,  m[104][104];
string s;

int main()
{
	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		cin >> s;
		for (int j = 0; j < w; j++)
		{
			if (s[j] == 'c') m[i][j] = 0;
			else m[i][j] = -1;
		}
	}

	for (int i = 0; i < h; i++)
	{
		bool flag = false;
		cnt = 2;
		for (int j = 0; j < w; j++)
		{
			if (m[i][j] == 0 && m[i][j + 1] == -1)
			{
				flag = true;
			}
			if (flag)
			{
				if (m[i][j + 1] == 0)
				{
					flag = false;
					cnt = 2;
				}
				else
				{
					m[i][j + 1] += cnt;
					cnt++;
				}
			}
		}
	}


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}