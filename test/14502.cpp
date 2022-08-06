#include <bits/stdc++.h>
using namespace std;

int mp[9][9], visited[9][9], n, m;
vector<pair<int, int>> v;

int dy[4] = {1,0,-1, 0};
int dx[4] = {0,1,0,-1};

void dfs(int y, int x)
{
	if (mp[y][x] == 1  || visited[y][x]) return;
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		dfs(ny, nx);
	}
}

int solve()
{
	::memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mp[i][j] == 2)
			{
				dfs(i, j);
			}
		}
	}

	int ret = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j] && mp[i][j] == 0)
			{
				ret++;
			 }
		}
	}

	return ret;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mp[i][j];
			if (mp[i][j] == 0)
				v.push_back({ i,j });
		}
	}

	int ret = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			for (int k = 0; k < j; ++k)
			{
				mp[v[i].first][v[i].second] = mp[v[j].first][v[j].second] = mp[v[k].first][v[k].second] = 1;
				ret = max(ret, solve());
				mp[v[i].first][v[i].second] = mp[v[j].first][v[j].second] = mp[v[k].first][v[k].second] = 0;

			}
		}
	}

	cout << ret;


	return 0;
}