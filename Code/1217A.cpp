#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = c - max((b - a + c + 2) / 2, 0) + 1;
		cout << max(ans, 0) << '\n';
	}
	return 0;
}
