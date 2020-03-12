#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
int d[maxn], a[maxn], dp[maxn];
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d", &a[i]);
		++d[a[i]];
	}
	set<pair<int, int> > s;
	for(int i = 1; i <= n; ++i) {
		dp[i] = i;
		if(!d[i]) {
			s.insert(make_pair(i, i));
		}
	}
	vector<pair<int, int> > ans;
	for(int i = n - 1; i; --i) {
		if(s.empty()) {
			puts("-1");
			return 0;
		}
		auto o = *s.begin();
		s.erase(s.begin());
		dp[a[i]] = max(dp[a[i]], o.first);
		ans.emplace_back(a[i], o.second);
		if(!--d[a[i]]) {
			s.insert(make_pair(dp[a[i]], a[i]));
		}
	}
	printf("%d\n", a[1]);
	for(int i = n - 2; ~i; --i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
