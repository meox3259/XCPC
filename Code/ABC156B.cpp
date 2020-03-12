#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	while(n) {
		++ans;
		n /= k;
	}
	cout << ans << '\n';
	return 0;
}
