#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int tot = 0;
	// 1 2 3 4 5 6
	// // 6 : 3 + 5 = 8
	for(int i = 1; i <= n; ++i) {
		tot += (i - 1) / 2;
	}
	if(tot < m) {
		cout << -1 << '\n';
		return 0;
	}
	tot = 0;
	vector<int> ans;
	ans.resize(n + 1);
	int mx = 0;
	for(int i = 1; i <= n; ++i) {
		if(tot == m) {
			ans[i] = n + i * 100005;
		} else if(tot + (i - 1) / 2 >= m) {
			int t = m - tot;
			tot = m;
			ans[i] = i + 2 * ((i - 1) / 2 - t);
			mx = max(mx, ans[i]);
		} else {
			ans[i] = i;
			tot += (i - 1) / 2;
			mx = max(mx, ans[i]);
		}
	}
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}
