#include <bits/stdc++.h>
using namespace std;

int r, c, k, v[26][26];
char m[26][26];
string s;

int dy[4] = { -1, 0, 1,0 };
int dx[4] = { 0,1,0,-1 };

int go(int y, int x)
{
	if (x == c - 1 && y == 0)
	{
		if (v[y][x] == k) {
			return 1;
		}
		return 0;
	}

	int ret = 0;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || nx >= c || ny >= r) continue;
		if (v[ny][nx] ||  m[ny][nx] == 'T') continue;

		v[ny][nx] = v[y][x] + 1;
		ret += go(ny, nx);
		v[ny][nx] = 0;
	}

	return ret;
}

int main()
{

	cin >> r >> c >> k;

	for (int i = 0; i < r; ++i)
	{
	cin >> s;
		for (int j = 0; j < c; ++j)
		{
			m[i][j] = s[ j];
		}
	}

	v[r - 1][0] = 1;
	int ret = go(r - 1, 0);

	cout << ret << endl;
	return 0;
}