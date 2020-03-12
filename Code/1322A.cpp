#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> pre;
	pre.resize(n + 1);
	for(int i = 0; i < n; ++i) {
		pre[i + 1] = pre[i] + (s[i] == ')' ? -1 : 1);
	}
	if(pre[n] != 0) {
		cout << -1 << '\n';
		return 0;
	}
	int ans = 0;
	int mn = 0;
	for(int i = 1, j = 0; i <= n; ++i) {
		if(pre[i] == 0) {
			if(mn < 0) {
				ans += i - j;
			}
			mn = 0;
			j = i;
		}
		mn = min(mn, pre[i]);
	}
	cout << ans << '\n';
	return 0;
}
