#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int main() {
	cin >> n >> k >> m;
	int ans = m;
	for(int i = 1; i < n; ++i) {
		int x;
		cin >> x;
		ans += m - x;
	}
	ans = max(ans, 0);
	cout << (ans > k ? -1 : ans) << endl;
	return 0;
}
