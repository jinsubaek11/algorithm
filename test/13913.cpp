#include <bits/stdc++.h>
using namespace std;

int MAX = 100000;
int n, k, ret;
int visited[100004], path[100004];
queue<int> q;
vector<int> v;

int main()
{
	cin >> n >> k;

	memset(visited, 0, sizeof(visited));

	q.push(n);
	visited[n] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == k)
		{
			ret = visited[k];
			break;
		}

		vector<int> directions = {
			now + 1, now - 1, 2 * now
		};

		for (int next : directions)
		{
			if (next < 0 || next > MAX) continue;

			if (!visited[next])
			{
				q.push(next);
				visited[next] = visited[now] + 1;
				path[next] = now;
			}
		}
	}

	for (int i = k; i != n; i = path[i])
	{
		v.push_back(i);
	}

	cout << ret - 1 << endl;

	v.push_back(n);
	reverse(v.begin(), v.end());

	for (int i : v)
	{
		cout << i << " ";
	}

	return 0;
}