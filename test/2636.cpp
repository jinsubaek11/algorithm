#include <bits/stdc++.h>
using namespace std;

int n, m, mp[104][104], vs[104][104], cnt, cnt2;
vector <pair<int, int>> v;

int dy[] = {1,0,-1,0};
int dx[] = { 0,1,0,-1 };

void Dfs(int y, int x)
{
	vs[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int ny= y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (vs[ny][nx]) continue;
		if (mp[ny][nx])
		{
			vs[ny][nx] = 2;
			v.push_back({ ny, nx });

			continue;
		}

		Dfs(ny, nx);
	}

}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mp[i][j];
		}
	}

	while (true)
	{
		bool flag = false;
		cnt2 = 0;
		v.clear();
		::memset(vs, 0, sizeof(vs));

		Dfs(0, 0);
		
		for (auto p : v)
		{
			cnt2++;
			mp[p.first][p.second] = 0;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (mp[i][j] != 0)
					flag = true;
			}
		}

		cnt++;

		if (!flag) break;
	}

	cout << cnt << "\n" << cnt2;

	return 0;
}