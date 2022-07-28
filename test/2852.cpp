#include <bits/stdc++.h>
using namespace std;

int n,t, w, a, b, sumA, sumB;
string s;

string CalculateTime(int sum)
{
	string m = "00" + to_string(sum / 60);
	string s = "00" + to_string(sum % 60);

	return m.substr(m.size()-2, 2) + ":" + s.substr(s.size()-2,2);
}

int StringToInt(string s)
{
	return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3,2).c_str());
}

void Sum(int& sum, string cur, string prev)
{
	sum += (StringToInt(cur) - StringToInt(prev));
}

int main()
{
	cin >> n;
	
	string prev = "";

	for (int i = 0; i < n; i++)
	{
		cin >> t >> s;

		if (a > b) Sum(sumA, s, prev);
		else if (b > a) Sum(sumB, s, prev);
		t == 1 ? a++ : b++;
		prev = s;
	}

	if (a > b) Sum(sumA, "48:00", prev);
	else if (b > a) Sum(sumB, "48:00", prev);

	cout << CalculateTime(sumA) << endl;
	cout << CalculateTime(sumB) << endl;

	return 0;
}