#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, r, s, p;
	cin >> n >> k >> r >> s >> p;
	string t;
	cin >> t;
	long long ans = 0;
	vector<int> mark;
	mark.resize(n);
	for(int i = 0; i < n; ++i) {
		if(i - k < 0 || mark[i - k] == 0 || t[i] != t[i - k]) {
			mark[i] = 1;
			if(t[i] == 'p') {
				ans += s;
			}
			if(t[i] == 'r') {
				ans += p;
			}
			if(t[i] == 's') {
				ans += r;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
