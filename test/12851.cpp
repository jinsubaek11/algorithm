#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int visited[MAX + 4];
long long cnt[MAX + 4];

int main()
{
	int n, k;
	cin >> n >> k;

	if (n == k)
	{
		puts("0");
		puts("1");
		return 0;
	}

	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		vector<int> directions = {
			now - 1, now + 1, 2 * now
		};

		for (int next : directions)
		{
			if (0 <= next && next <= MAX)
			{
				if (!visited[next])
				{
					q.push(next);
					visited[next] = visited[now] + 1;
					cnt[next] += cnt[now];
				}
				else if (visited[next] == visited[now] + 1)
				{
					cnt[next] += cnt[now];
				}
			}
		}
	}

	cout << visited[k] - 1 << endl;
	cout << cnt[k] << endl;

	return 0;
}