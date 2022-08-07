#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> basket;

void Subset(int arr[], vector<int>& v)
{
		basket.push_back(v);

	if (v.size() == 5)
		return;

	int smallest = v.empty() ? 0 : v.back();
	
	for (int i = smallest; i < 4; ++i)
	{
		v.push_back(arr[i]);
		Subset(arr, v);
		v.pop_back();
	}
}

void Permutation(int arr[], vector<int>& v, bool selected[])
{
	if (v.size() == 4)
	{
		basket.push_back(v);
		return;
	}
	
	for (int i = 0; i < 4; ++i)
	{
		if (selected[arr[i]]) continue;

		selected[arr[i]] = true;
		v.push_back(arr[i]);

		Permutation(arr, v, selected);

		selected[arr[i]] = false;
		v.pop_back();
	}

}

void Combination(int arr[], vector<int>& v, int pickCnt)
{
	if (pickCnt == 0)
	{
		basket.push_back(v);
		return;
	}

	int smallest = v.empty() ? 0 : v.back();

	for (int i = smallest; i < 4; ++i)
	{
		v.push_back(arr[i]);
		Combination(arr, v, pickCnt-1);
		v.pop_back();
	}
}


int main()
{
	int arr[4] = {1,2,3,4};
	bool selected[5];
	::memset(selected, false, 5);
	vector<int> v;
	int pickCnt = 2;

	Subset(arr, v);
	//Permutation(arr, v, selected);
	//Combination(arr, v, pickCnt);

	for (int i = 0; i < basket.size(); ++i)
	{
		for (int j = 0; j < basket[i].size(); ++j)
		{
			cout << basket[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}