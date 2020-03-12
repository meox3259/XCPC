#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
vector<int> vec[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			vec[i].clear();
		}
		for(int i = 1; i <= n; ++i) {
			int m, p;
			scanf("%d%d", &m, &p);
			vec[m].push_back(p);
		}
		priority_queue<int, vector<int>, greater<int> > q;
		int pre = n, cnt = 0;
		long long ans = 0;
		for(int i = n - 1; ~i; --i) {
			pre -= vec[i].size();
			int need = i - pre;
			for(auto x : vec[i]) {
				q.push(x);
			}
			while(cnt < need) {
				++cnt;
				ans += q.top();
				q.pop();
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
