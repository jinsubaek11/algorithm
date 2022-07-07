#include <bits/stdc++.h>
using namespace std;

int n, m[101][101], v[101][101], ret=1, temp;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int a = 1;
void DFS(int y, int x, int h)
{
	v[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (v[ny][nx] || m[ny][nx] <= h) continue;

		
		DFS(ny, nx, h);
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> m[i][j];
		}
	}

	for (int h = 1; h < 101; ++h)
	{
		fill(&v[0][0], &v[0][0] + 101 * 101, 0);
		temp = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (m[i][j] <= h) continue;
				if (v[i][j]) continue;
				
				DFS(i, j, h);
				temp++;
				
			}
		}
		ret = max(ret, temp);
	}

	cout << ret << "\n";

	return 0;
}