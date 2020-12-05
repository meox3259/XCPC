#include <bits/stdc++.h>

using namespace std;

const string b = "110";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	if (s == "1") {
		cout << 20000000000 << '\n';
		exit(0);
	}

	string t = "";
	while (t.size() <= n + n) {
		t += b;
	}

	for (int p = 0; p < 3; ++p) {
		if (t.substr(p, n) == s) {
			long long ans = 10000000000;
			cout << ans - (n + p - 1) / 3 << '\n';
			exit(0);
		}
	}

	cout << 0 << '\n';

	return 0;
}
