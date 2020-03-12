#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, P = 1e9 + 7;
int n;
int x[maxn], inv[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	inv[1] = 1;
	for(int i = 2; i <= n; ++i) {
		inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
	}
	for(int i = 2; i <= n; ++i) {
		inv[i] = (inv[i] + inv[i - 1]) % P;
	}
	int ans = 0;
	for(int i = 1; i < n; ++i) {
		ans = (ans + 1LL * inv[i] % P * (x[i + 1] - x[i]) % P) % P;
	}
	for(int i = 1; i < n; ++i) {
		ans = 1LL * ans * i % P;
	}
	cout << ans << '\n';
	return 0;
}
