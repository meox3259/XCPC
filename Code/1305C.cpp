#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	bool f = 0;
	vector<int> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if(n > m + 5) {
		cout << 0 << '\n';
		return 0;
	}
	int ans = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = i - 1; j >= 0; --j) {
			ans = 1LL * ans * abs(a[i] - a[j]) % m; 
		}
	}
	cout << ans << '\n';
	return 0;
}
