#include <iostream>
#include <vector>

using namespace std;

int n, l, r, sum, cnt, m[52][52];
bool  visited[52][52];
vector<pair<int, int>> v;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void DFS(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= n || nx < 0 || ny < 0) continue;
		if (visited[ny][nx] == true) continue;
		if (abs(m[ny][nx] - m[y][x]) < l || abs(m[ny][nx] - m[y][x]) > r) continue;
		
		v.push_back({ ny, nx });
		sum += m[ny][nx];
		visited[ny][nx] = true;
		DFS(ny, nx);	
	}
}

int main()
{
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
		}
	}

	while (true)
	{
		bool flag = false;
		fill(&visited[0][0], &visited[0][0] + 52 * 52, false);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] == true) continue;

				v.clear();
				v.push_back({ i,j });
				visited[i][j] = true;
				sum = m[i][j];
				DFS(i, j);

				if (v.size() == 1) continue;

				for (pair<int, int> b : v)
				{
					m[b.first][b.second] = sum / v.size();
				}

				flag = true;
			}
		}

		if (flag == false) break;
		cnt++;

	}

	cout << cnt << endl;

	return 0;
}