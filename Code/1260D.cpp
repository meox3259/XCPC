#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k, t;
	cin >> m >> n >> k > >t;
	vector<int> a;
	vector<int> l;
	vector<int> r;
	vector<int> d;
	a.resize(m);
	l.resize(k);
	r.resize(k);
	d.resize(k);
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < k; ++i) {
		cin >> l[i] >> r[i] >> d[i];
	}
	sort(a.begin(), a.end(), greater<int> ());
	
	return 0;
}
