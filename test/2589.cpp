#include <bits/stdc++.h>
using namespace std;
#include <queue>

int w, h, d, v[52][52];
char m[52][52];
int dy[] = {-1,0,1,0};
int dx[] = { 0,1,0,-1 };

void BFS(int y, int x)
{
	memset(v, 0, sizeof(v));
	v[y][x] = 1;
	queue<pair<int, int>> q;

	q.push({ y,x });

	while (q.empty() == false)
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (v[ny][nx]) continue;
			if (m[ny][nx] == 'W') continue;

			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
			d = max(d, v[ny][nx]);
		}

	}
}

int main()
{
	cin >> w >> h;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (m[i][j] == 'L')
				BFS(i, j);
		}
	}

	cout << d - 1 << endl;

	return 0;
}