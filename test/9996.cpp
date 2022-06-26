#include <bits/stdc++.h>;
using namespace std;
int n,i;
string pat, word, pre, suf;

int main() {

	cin >> n;
	cin >> pat;

	i = pat.find('*');
	pre = pat.substr(0, i);
	suf = pat.substr(i + 1);

	for (int i = 0; i < n; ++i) {
		cin >> word;

		if (pre.size() + suf.size() > word.size()) {
			cout << "NE\n";
		}
		else {
			if (word.substr(0, pre.size()) == pre && word.substr(word.size() - suf.size()) == suf) {
				cout << "DA\n";
			}
			else {
				cout << "NE\n";
			}
		}
	}

	return 0;
}