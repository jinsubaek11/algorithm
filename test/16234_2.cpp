#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int n, l, r, x, y, cnt = 0, ret = 0;
int _map[51][51], _nextMap[51][51];
bool visited[51][51];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;

void UpdateNumber()
{
	int sum = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j])
			{
				sum += _map[i][j];
				count++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j])
			{
				_nextMap[i][j] = sum / count;
			}
		}
	}

	cnt++;
}

void BFS(int y, int x)
{
	memset(visited, 0, sizeof(visited));
	
	q.push({ y, x });
	visited[y][x] = true;

	bool hasChange = false;

	while (q.size() > 0)
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[ny][nx]) continue;

			int v = abs(_map[y][x] - _map[ny][nx]);
			if (v < l || v > r) continue;

			hasChange = true;
			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}

	if (hasChange)
	{
		UpdateNumber();
	}
}

int main()
{
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> _map[i][j];
			_nextMap[i][j] = _map[i][j];
		}
	}

	while (true)
	{
		cnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				BFS(i, j);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				_map[i][j] = _nextMap[i][j];
			}
		}

		if (cnt <= 0) break;
	
		ret++;
	}

	cout << ret;

	return 0;
}