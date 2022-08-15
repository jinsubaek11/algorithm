#include <bits/stdc++.h>
using namespace std;

int n, m, root, r;
vector<int> adj[54];

int Dfs(int here)
{
	int ret = 0;
	int child = 0;

	for (int there : adj[here])
	{
		if (there == r) continue;

		ret += Dfs(there);
		child++;
	}

	if (child == 0) return 1;

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> m;
		if (m == -1) root = i;
		else adj[m].push_back(i);
	}

	cin >> r;

	if (r == root)
	{
		cout << 0 << "\n";
		return 0;
	}

	cout << Dfs(root) << "\n";

	return 0;
}