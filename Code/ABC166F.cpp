#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int a, b, c;
	cin >> a >> b >> c;

	vector<string> s(n);
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	int A = 0;
	int B = 0;
	int C = 0;

	vector<char> ans(n, 'D');

	bool ok = true;

	function<void(int, int, int, int)> dfs = [&] (int d, int a, int b, int c) {
		if(a < 0 || b < 0 || c < 0) {
			return;
		}
		if(d == n) {
			cout << "Yes" << '\n';
			for(char c : ans) {
				cout << c << '\n';
			}
			exit(0);
		}
		if(s[d] == "AB") {
			ans[d] = 'A';
			dfs(d + 1, a + 1, b - 1, c);
			ans[d] = 'B';
			dfs(d + 1, a - 1, b + 1, c);
		}
		if(s[d] == "BC") {
			ans[d] = 'B';
			dfs(d + 1, a, b + 1, c - 1);
			ans[d] = 'C';
			dfs(d + 1, a, b - 1, c + 1);
		}
		if(s[d] == "AC") {
			ans[d] = 'A';
			dfs(d + 1, a + 1, b, c - 1);
			ans[d] = 'C';
			dfs(d + 1, a - 1, b, c + 1);
		}
	};

	dfs(0, a, b, c);

	cout << "No" << '\n';

	return 0;
}
