#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
int t[maxn], last[maxn], a[maxn], dp[maxn], l[maxn], r[maxn];
void upd(int p, int d) {
	for(; p <= n; p += p & -p) {
		t[p] = max(t[p], d);
	}
}
int ask(int p) {
	int ret = 0;
	for(; p; p -= p & -p) {
		ret = max(ret, t[p]);
	}
	return ret;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			l[i] = 0;
			r[i] = 0;
			dp[i] = 0;
		}
		vector<int> v;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			v.emplace_back(a[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1; i <= n; ++i) {
			a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		}
		for(int i = 1; i <= n; ++i) {
			if(!l[a[i]]) {
				l[a[i]] = i;
			}
			r[a[i]] = i;
		}
		int ans = 0;
		for(int i = 1; i <= v.size(); ++i) {
			if(l[i] > r[i - 1]) {
				dp[i] = dp[i - 1] + 1;
			} else {
				dp[i] = 1;
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", (int)v.size() - ans);
	}
	return 0;
}
