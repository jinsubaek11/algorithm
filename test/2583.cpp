#include <bits/stdc++.h>
using namespace std;

int m, n, k, g[101][101],v[101][101], x1, x2, y3, y4;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int DFS(int y, int x)
{
	int ret = 1;
	g[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (g[ny][nx] ==1) continue;

		ret += DFS(ny, nx);
	}

	return ret;
}

int main()
{
	cin >> m >> n >> k;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> rv;

	for (int i = 0; i < k; ++i)
	{
		cin >> x1 >> y3 >> x2 >> y4;
		for (int x = x1; x < x2; ++x)
		{
			for (int y = y3; y < y4; ++y)
			{
				if (g[y][x] == 1) continue;

				g[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (g[i][j] ==1) continue;
			int s = DFS(i, j);
			rv.push_back(s);
		}
	}

	sort(rv.begin(), rv.end());
	cout << rv.size() << "\n";
	for (int ret : rv) cout << ret << "\n";
 
	return 0;
}