#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for(int i = 0; i < n; ++i) {
		c[i] = i + 1;
	}
	int cnt = 0;
	int ans = 0;
	do {
		++cnt;
		if(a == c) {
			ans += cnt;
		}
		if(b == c) {
			ans -= cnt;
		}
	} while(next_permutation(c.begin(), c.end()));
	cout << abs(ans) << '\n';
	return 0;
}
