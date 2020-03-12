#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n >> s + 1;
		map<pair<int, int>, int> mp;
		int a = 0, b = 0;
		mp[{0, 0}] = 0;
		int cur = n + 2, l = 0, r = 0;
		for(int i = 1; i <= n; ++i) {
			a += s[i] == 'R';
			a -= s[i] == 'L';
			b += s[i] == 'U';
			b -= s[i] == 'D';
			if(mp.find({a, b}) != mp.end()) {
				int p = mp[{a, b}];
				if(i - p < cur) {
					cur = i - p;
					l = p + 1;
					r = i;
				}
			}
			mp[{a, b}] = i;
		}
		if(cur <= n) {
			cout << l << ' ' << r << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
	return 0;
}
