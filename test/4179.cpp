#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 987654321;
int r, c, x, y, ret;
pair<int, int> pos;
queue<pair<int, int>> q;
char _map[1004][1004];
int visited[1004][1004], fire[1004][1004];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> _map[i][j];
			if (_map[i][j] == 'J') pos = { i, j };
			if (_map[i][j] == 'F')
			{
				fire[i][j] = 1;
				q.push({ i, j });
			}
		}
	}

	while (q.size() > 0)
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (_map[ny][nx] == '#' || fire[ny][nx] != INF) continue;

			q.push({ ny, nx });
			fire[ny][nx] = fire[y][x] + 1;
		}
	}

	visited[pos.first][pos.second] = 1;
	q.push(pos);
	while (q.size() > 0)
	{
		tie(y, x) = q.front();
		q.pop();

		if (y == 0 || y == r - 1 || x == 0 || x == c - 1)
		{
			ret = visited[y][x];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (_map[ny][nx] == '#' || visited[ny][nx] > 0) continue;
			if (visited[y][x] + 1 >= fire[ny][nx]) continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
	
	if (ret != 0) cout << ret << '\n';
	else cout << "IMPOSSIBLE"; 

	return 0;
}