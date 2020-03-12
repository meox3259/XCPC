#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int p = 1;
	int ans = n;
	for(int i = 0; i < n; ++i) {
		if(a[i] == p) {
			--ans;
			++p;
		}
	}
	if(p == 1) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
	return 0;
}
