#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int n;
ll d[maxn], c[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> d[i] >> c[i];
	}
	ll sum = 0, ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += c[i];
		sum += d[i] * c[i];
	}
	cout << ans - 1 + (sum - 1) / 9 << '\n';
	return 0;
}
