#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	vector<int> c(n, 0);
	vector<int> f(26, 0);
	for(int i = 0; i < n; ++i) {
		c[i] = 1;
		for(int j = s[i] - 'a' + 1; j < 26; ++j) {
			c[i] = max(c[i], f[j] + 1);
		}
		f[s[i] - 'a'] = c[i];
	}
	cout << *max_element(c.begin(), c.end()) << '\n';
	for(int i = 0; i < n; ++i) {
		cout << c[i] << ' ';
	}
	cout << '\n';
	return 0;
}
