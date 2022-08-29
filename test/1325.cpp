#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, ret;
int dc[10001];
bool visited[10001];
vector<int> v[10001];

int Dfs(int i)
{
	int ret = 1;
	visited[i] = true;

	for (auto child : v[i])
	{
		if (visited[child]) continue;
		
		ret += Dfs(child);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--)
	{
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		dc[i] = Dfs(i);
		ret = max(ret, dc[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (dc[i] == ret)
		{
			cout << i << " ";
		}
	}


	return 0;
}