#include <iostream>
#include <queue>

using namespace std;

int n, ret = 987654321;
int scv[3];
int visited[64][64][64];
int att[6][3] = {
	{ 9, 3, 1 },
	{ 9, 1, 3 }, 
	{ 3, 9, 1 },
	{ 3, 1, 9 },
	{ 1, 3, 9 },
	{ 1, 9, 3 },
};
struct Health { int a; int b; int c; };
queue<Health> q;

int BFS(int f, int s, int t)
{
	visited[f][s][t] = 0;
	q.push({f, s, t});

	while (q.size() > 0)
	{
		Health cur = q.front();
		q.pop();

		if (visited[0][0][0]) break;

		for (int i = 0; i < 6; i++)
		{
			int nf = max(0, cur.a - att[i][0]);
			int ns = max(0, cur.b - att[i][1]);
			int nt = max(0, cur.c - att[i][2]);

			if (visited[nf][ns][nt]) continue;

			visited[nf][ns][nt] = visited[cur.a][cur.b][cur.c] + 1;
			q.push({ nf, ns, nt });
		}
	}

	return visited[0][0][0];
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> scv[i];
	}
	
	cout << BFS(scv[0], scv[1], scv[2]);

	return 0;
}