#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int l, r;
	if(n == 1) {
		l = 0;
		r = 10;
	}
	if(n == 2) {
		l = 10;
		r = 100;
	}
	if(n == 3) {
		l = 100;
		r = 1000;
	}
	vector<int> s;
	vector<int> c;
	s.resize(m);
	c.resize(m);
	for(int i = 0; i < m; ++i) {
		cin >> s[i] >> c[i];
		--s[i];
	}
	for(int i = l; i < r; ++i) {
		vector<int> bit;
		bit.resize(n);
		int t = i;
		for(int j = 0; j < n; ++j) {
			bit[n - j - 1] = t % 10;
			t /= 10;
		}
		bool f = 1;
		for(int j = 0; j < m; ++j) {
			if(bit[s[j]] != c[j]) {
				f = 0;
			}
		}
		if(f == 1) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}
