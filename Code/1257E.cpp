#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int k1, k2, k3, n;
int a[maxn], b[maxn], c[maxn], s[maxn];
struct BIT {
	int t[maxn];
	BIT() { memset(t, 0, sizeof(t)); }
	void add(int p, int d) {
		for(; p <= n; p += p & -p) {
			t[p] += d;
		}
	}
	int query(int p) {
		int ret = 0;
		for(; p; p -= p & -p) {
			ret += t[p];
		}
		return ret;
	}
} t1, t2;
int main() {
	scanf("%d%d%d", &k1, &k2, &k3);
	n = k1 + k2 + k3;
	for(int i = 1; i <= k1; ++i) {
		scanf("%d", &a[i]);
		t1.add(a[i], 1);
	}
	for(int i = 1; i <= k2; ++i) {
		scanf("%d", &b[i]);
	}
	for(int i = 1; i <= k3; ++i) {
		scanf("%d", &c[i]);
		t2.add(c[i], 1);
	}
	for(int i = 1; i <= n + 1; ++i) {
		s[i] = n - i + 1 - (t2.query(n) - t2.query(i - 1)) - (t1.query(n) - t1.query(i - 1)) + (k3 - (t2.query(n) - t2.query(i - 1)));
	}
	for(int i = n; i; --i) {
		s[i] = min(s[i], s[i + 1]);
	}
	int ans = n;
	for(int i = 0; i <= n; ++i) {
		int tmp = 0;
		tmp += i - t1.query(i) - t2.query(i);
		tmp += k1 - t1.query(i);
		tmp += s[i + 1];
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}
