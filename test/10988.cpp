#include <bits/stdc++.h>
using namespace std;
string str;
int mid;

int main() {

	cin >> str;
	int mid = floorf(str.length() / 2);

	for (int i = 0; i <=mid; i++) {
		if (str[i] == str[str.length() - 1-i] ) {
			if (i == mid) {
				cout << 1 << "\n";
				break;
			}
			continue;
		}
		else {
			cout << 0 << "\n";
			break;
		}
	}

	return 0;
}