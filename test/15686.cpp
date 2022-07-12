#include <bits/stdc++.h>
using namespace std;

int n, m, a[52][52], result = 987654321;
vector<vector<int>> chickenList;
vector<pair<int, int>> home, chicken;


void combination(int start, vector<int>& v)
{
	if (v.size() == m)
	{
		chickenList.push_back(v);
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++)
	{
		v.push_back(i);
		combination(i, v);
		v.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) home.push_back({ i,j });
			if (a[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	vector<int> v;
	combination(-1, v);


	for (vector<int> cl : chickenList)
	{
		int ret = 0;
		for (pair<int, int> h : home)
		{
			int md = 987654321;
			for (int k = 0; k < m; k++)
			{
				int d = abs(h.first - chicken[cl[k]].first) + abs(h.second - chicken[cl[k]].second);
				md = min(md, d);
			}

			ret += md;
		}
		result = min(result, ret);
	}

	cout << result << endl;

	return 0;
}