#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, t;
	cin >> n >> t;
	vector<int> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	set<int> s;
	s.emplace(a[0]);
	int mx = 0, cnt = 0;
	for(int i = 1; i < n; ++i) {
		if(a[i] - *s.begin() > mx) {
			mx = a[i] - *s.begin();
			cnt = 1;
		} else if(a[i] - *s.begin() == mx) {
			++cnt;
		}
		s.emplace(a[i]);
	}
	cout << cnt << '\n';
	return 0;
}
