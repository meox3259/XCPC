#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, s, k;
		cin >> n >> s >> k;
		map<int, int> vis;
		for(int i = 0; i < k; ++i) {
			int x;
			cin >> x;
			vis[x] = 1;
		}
		int ans = n;
		for(int i = -1000; i <= 1000; ++i) {
			if(i + s > 0 && i + s <= n && vis.count(s + i) == 0) {
				ans = min(ans, abs(i));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
