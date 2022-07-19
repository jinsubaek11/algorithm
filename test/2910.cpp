#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, a[1004];
vector<pair<int, int>> v;
map<int, int> m, mo;

bool SortCb(const pair<int, int>& a, const pair<int,int>& b)
{
	if (a.second == b.second)
		return mo[a.first] < mo[b.first];

	return a.second > b.second;
}

int main()
{

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
		if (mo[a[i]] == 0)
			mo[a[i]] = i+1;
	}

	for (auto& it : m)
	{
		v.push_back({ it.first, it.second });
	}

	sort(v.begin(), v.end(), SortCb);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].second; j++)	
			{
				cout << v[i].first << " ";
			}
	}


	return 0;
}