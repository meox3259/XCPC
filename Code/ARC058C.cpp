#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 1e9;
int ban[10];
void dfs(int x, int b) {
	if(b > 1000000) {
		return;
	}
	if(x >= n) {
		ans = min(ans, x);
		return;
	}
	for(int i = 0; i < 10; ++i) {
		if(!ban[i]) {
			dfs(x + i * b, b * 10);
		}
	}
}
int main() {
	cin >> n >> k;
	for(int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		ban[x] = 1;
	}
	dfs(0, 1);
	cout << ans << '\n';
	return 0;
}
