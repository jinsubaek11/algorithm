#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, ret, d = 0;
int visited[51][51];
char _map[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

int BFS(int y, int x)
{
	memset(visited, 0, sizeof(visited));
	q.push({ y, x });
	visited[y][x] = 1;

	int ret = 0;

	while (q.size() > 0)
	{
		pair<int, int> coord = q.front();
		y = coord.first;
		x = coord.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] > 0) continue;
			if (_map[ny][nx] == 'W') continue;

			visited[ny][nx] = visited[y][x] + 1;
			ret = max(ret, visited[ny][nx]);
			q.push({ ny, nx });
		}
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> _map[y][x];
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (_map[y][x] == 'L')
			{
				ret = max(ret, BFS(y, x));
			}
		}
	}

	cout << ret - 1 << endl;
	
	return 0;
}