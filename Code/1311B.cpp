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
		vector<int> a;
		vector<int> p;
		a.resize(n);
		p.resize(m);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> mx;
		mx.resize(n);
		mx[0] = a[0];
		for(int i = 0; i < n - 1; ++i) {
			mx[i + 1] = max(mx[i], a[i + 1]);
		}
		bool f = 1;
		vector<int> mark;
		mark.resize(n);
		for(int i = 0; i < m; ++i) {
			int p;
			cin >> p;
			--p;
			mark[p] = 1;
		}
		for(int i = 0; i < n; ++i) {
			if(mark[i] == 0) {
				for(int j = i + 1; j < n; ++j) {
					if(a[j] < mx[i]) {
						f = 0;
					}
				}
			}
		}
		if(f == 1) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
