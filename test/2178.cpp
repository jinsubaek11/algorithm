#include <bits/stdc++.h>
#pragma warning(disable: 4996)
#include <queue>
using namespace std;
const int MAX = 104;
int n, m, a[MAX][MAX], visited[MAX][MAX],x,y;

const int dy[4] = { -1,0,1,0 };
const int dx[4] = {  0,1, 0,-1 };

void BFS(pair<int, int>  here)
{

	queue<pair<int, int>> q;

	q.push(here);
	visited[here.first][here.second] = 1;

	while (!q.empty())
	{
		tie(y,x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}

	cout << visited[n-1][m-1] << endl;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	BFS({0,0});
	return 0;
}