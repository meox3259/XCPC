#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	int L, q;
	cin >> L >> q;
	x.emplace_back(x.back() + L + 1);
	vector<vector<int> > p;
	p.resize(n);
	for(int i = 0; i < n; ++i) {
		p[i].resize(20);
	}
	for(int i = 0; i < n; ++i) {
		auto it = upper_bound(x.begin(), x.end(), x[i] + L);
		p[i][0] = (--it - x.begin()); 
	}
	for(int j = 1; j < 20; ++j) {
		for(int i = 0; i < n; ++i) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
	while(q--) {
		int a, b;
		cin >> a >> b;
		if(a > b) {
			swap(a, b);
		}
		--a;
		--b;
		int ans = 0;
		for(int j = 19; ~j; --j) {
			if(x[p[a][j]] < x[b]) {
				ans += 1 << j;
				a = p[a][j];
			}
		}
		cout << ans + 1 << '\n';
	}
	return 0;
}
