
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, p, k;
int a[maxn], sum[maxn];
map<int, int> s[maxn];
int query(int pos) {
	if(k <= 1000) {
		return s[pos / k][pos % k];
	} else {
		int ret = 0;
		for(int i = pos; i >= k; i -= k) {
			ret += a[i];
		}
		return ret;
	}
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &p, &k);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i) {
			sum[i] = 0;
		}
		for(int i = 1; i <= n; ++i) s[i].clear();
		if(k <= 1000) {
			for(int i = 0; i <= n / k; ++i) {
				for(int j = 0; j < k; ++j) {
					s[i][j] = 0;
				}
			}
		}
		for(int i = 1; i <= n; ++i) {
			sum[i] = sum[i - 1] + a[i];
			if(k <= 1000 && i / k > 0) {
				s[i / k][i % k] += a[i];
			}
		}
		for(int i = 2; i <= n / k; ++i) {
			for(int j = 0; j < k; ++j) {
				s[i][j] += s[i - 1][j];
			}
		}
		if(a[1] > p) {
			puts("0");
			continue;
		}
		int ans = 0;
		for(int i = n; i; --i) {
			int S = 0;			
			if(query(i) + sum[i % k] <= p) {
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
