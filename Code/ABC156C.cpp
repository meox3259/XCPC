#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> x;
	x.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	int ans = 1e9;
	for(int i = 1; i <= 100; ++i) {
		int tmp = 0;
		for(auto p : x) {
			tmp += (p - i) * (p - i);
		}
		ans = min(ans, tmp);
	}
	cout << ans << '\n';
	return 0;
}
