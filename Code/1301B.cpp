#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> a;
		a.resize(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int mn = 1e9 + 1, mx = -1;
		for(int i = 0; i < n; ++i) {
			if(a[i] != -1) {
				if((i && a[i - 1] == -1) || (i < n - 1 && a[i + 1] == -1)) {
					mx = max(a[i], mx);
					mn = min(a[i], mn);
				}
			}
		}
		int m;
		if(mx == -1) {
			m = 1;
		} else {
			m = (mx + mn) / 2;
		}
		for(int i = 0; i < n; ++i) {
			if(a[i] == -1) {
				a[i] = m;
			}
		}
		int k = 0;
		for(int i = 1; i < n; ++i) {
			k = max(k, abs(a[i] - a[i - 1]));
		}
		cout << k << ' ' << m << '\n';
	}
	return 0;
}
