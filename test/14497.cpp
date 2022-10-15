#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, x2, y2, cnt;
char classroom[302][302];
short visited[302][302];
pair<int, int> hero, thief;
queue<pair<int, int>> q;
bool findflag = false;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main()
{
	cin >> N >> M;
	cin >> y >> x >> y2 >> x2;

	hero = { y - 1, x - 1 };
	thief = { y2 - 1, x2 - 1 };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> classroom[i][j];
		}
	}

	q.push(hero);
	visited[hero.first][hero.second] = 1;

	while (classroom[thief.first][thief.second] != '0')
	{
		cnt++;
		queue<pair<int, int>> temp;

		while (q.size())
		{
			int y = q.front().first;
			int x = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = dy[i] + y;
				int nx = dx[i] + x;

				if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx]) continue;
				
				visited[ny][nx] = cnt;

				if (classroom[ny][nx] != '0')
				{
					classroom[ny][nx] = '0';
					temp.push({ ny, nx });
				}
				else
				{
					q.push({ ny, nx });
				}
			}
		}

		q = temp;
	}

	cout << visited[thief.first][thief.second] << std::endl;

	return 0;
}