#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;

int t, a[MAX][MAX], visited[MAX][MAX], ret, n, m, k, x, y;

const int dy[4] = {-1,0,1,0};
const int dx[4] = { 0,1,0,-1 };

void DFS(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n || a[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;

		DFS(ny, nx);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;

	while (t--)
	{
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (a[y][x] == 1 && !visited[y][x])
				{

					DFS(y, x);
					ret++;
				}
			}
		}

		cout << ret << "\n";
	}

	return 0;
}