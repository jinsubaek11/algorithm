#include <bits/stdc++.h>;
using namespace std;
int n, k, num, psum[100004], ret = -100004;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> num;
		psum[i+1] = psum[i] + num;
	}

	for (int i = 0; i <= n - k; ++i) {
		ret = max(ret, psum[i+k] - psum[i]);
	}

	cout << ret;

	return 0;
}