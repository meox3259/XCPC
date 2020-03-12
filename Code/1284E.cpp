#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5005;
int n;
int x[maxn], y[maxn];
struct Vec {
	int x, y;
	Vec() = default;
	Vec(int _x, int _y) : x(_x), y(_y) {}
	ll friend operator ^ (const Vec &a, const Vec &b) {
		return 1LL * a.x * b.y - 1LL * a.y * b.x;
	}
	bool friend operator < (const Vec &a, const Vec &b) {
		if(1LL * a.y * b.y < 0) {
			return a.y > b.y;
		}
		return (a ^ b) > 0;
	}
} st[maxn];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		 scanf("%d%d", &x[i], &y[i]);
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		int top = 0;
		for(int j = 1; j <= n; ++j) {
			if(j != i) {
				st[++top] = Vec(x[j] - x[i], y[j] - y[i]);
			}
		}
		sort(st + 1, st + top + 1);
		for(int j = 1; j < n; ++j) {
			st[++top] = st[j];
		}
		int pos = 1;
		for(int j = 1; j < n; ++j) {
			pos = max(pos, j);
			while(pos + 1 <= top && (st[j] ^ st[pos + 1]) > 0) {
				++pos;
			}
			ll c = pos - j;
			ans += c * (c - 1) * (c - 2) / 6LL;
		}
	}
	printf("%lld\n", 1LL * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24LL - ans);
	return 0;
}
