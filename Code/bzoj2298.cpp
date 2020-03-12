#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int dp[maxn];
vector<int> v[maxn];
map<pair<int, int>, int> mp;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		v[n - b].push_back(a);
		++mp[make_pair(a, n - b)];
	}
	for(int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		for(int j = 0; j < v[i].size(); ++j) {
			dp[i] = max(dp[i], dp[v[i][j]] + min(mp[make_pair(v[i][j], i)], i - v[i][j]));
		}
	}
	printf("%d\n", n - dp[n]);
	return 0;
}
