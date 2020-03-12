#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		vector<int> t;
		vector<int> l;
		vector<int> h;
		t.resize(n);
		l.resize(n);
		h.resize(n);
		for(int i = 0; i < n; ++i) {
			cin >> t[i] >> l[i] >> h[i];
		}
		bool f = 1;
		int low = m, high = m;
		for(int i = 0; i < n; ++i) {
			low = max(low - (t[i] - (i ? t[i - 1] : 0)), l[i]);
			high = min(high + (t[i] - (i ? t[i - 1] : 0)), h[i]);
			if(high < l[i] || low > h[i]) {
				cout << "NO" << '\n';
				f = 0;
				break;
			}
		}
		if(f) {
			cout << "YES" << '\n';
		}
	}
	return 0;
}
