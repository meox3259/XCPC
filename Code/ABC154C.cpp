#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	map<int, int> mp;
	int ans = 1;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if(mp.count(x)) {
			ans = 0;
		}
		mp[x] = 1;
	}
	if(ans) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
	return 0;
}
