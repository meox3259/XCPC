#include <bits/stdc++.h>
using namespace std;
const int P = 1'000'000'007;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> c;
	c.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	// i
	// \sum {2 ^ {i - 1} * \sum{C(n - i, j) * 2 ^ {j} * 2 ^ {n - i - j}}}
	// = \sum {2 ^ {n} }
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans = (ans + 1LL * c[i] * (n - i + 1) % P) % P;
	}
	for(int i = 0; i < 2 * n - 2; ++i) {
		ans = ans * 2 % P;
	}
	cout << ans << '\n';
	return 0;
}
