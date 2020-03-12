#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int x[maxn], y[maxn], cnt[2][2];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	while(1) {
		int s = 0;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; ++i) {
			++cnt[x[i] & 1][y[i] & 1];
		}
		vector<int> ans;
		if(cnt[0][0] + cnt[1][1] > 0 && cnt[0][1] + cnt[1][0] > 0) {
			for(int i = 1; i <= n; ++i) {
				if(x[i] + y[i] & 1) {
					ans.push_back(i);
				}
			}
			printf("%d\n", ans.size());
			for(auto x : ans) {
				printf("%d ", x);
			}
			return 0;
		}
		if(cnt[0][0] + cnt[0][1] > 0 && cnt[1][0] + cnt[1][1] > 0) {
			for(int i = 1; i <= n; ++i) {
				if(x[i] & 1) {
					ans.push_back(i);
				}
			}
			printf("%d\n", ans.size());
			for(auto x : ans) {
				printf("%d ", x);
			}
			return 0;
		}
		for(int i = 1; i <= n; ++i) {
			x[i] >>= 1;
			y[i] >>= 1;
		}
	}
	return 0;
}
