#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int n, k, ok, turn = 1;
int visited[2][500004];

int main()
{
	cin >> n >> k;

	if (n == k)
	{
		cout << 0 << endl;
		return 0;
	}

	queue<int> q;
	visited[0][n] = 1;
	q.push(n);
	
	while (q.size())
	{
		k += turn;
		if (k > MAX) break;
		if (visited[turn % 2][k])
		{
			ok = true;
			break;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int x = q.front();
			q.pop();

			vector<int> directions = {
				x + 1, x - 1, 2 * x
			};

			for (int next : directions)
			{
				if (next < 0 || next > MAX || visited[turn % 2][next]) continue;
				visited[turn % 2][next] = visited[(turn + 1) % 2][x] + 1;

				if (next == k)
				{
					ok = 1; 
					break;
				}

				q.push(next);
			}

			if (ok) break;
		}

		if (ok) break;
		turn++;
	}

	if (ok) cout << turn << endl;
	else cout << -1 << endl;

	return 0;
}