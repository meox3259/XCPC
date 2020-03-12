#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	for(auto& c : s) {
		cout << (char)('A' + (c - 'A' + n) % 26);
	}

	cout << '\n';

	return 0;
}
