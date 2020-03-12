#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	vector<vector<int> > a(n + 5, vector<int>(m + 5));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int ans = 0;
	for(int j = 0; j < m; ++j) {
		vector<int> cnt(n, 0);
		for(int i = 0; i < n; ++i) {
			if((a[i][j] - j - 1) % m == 0) {
				int t = (a[i][j] - j - 1) / m;
				if(t >= 0 && t < n) {
					++cnt[(i - t + n) % n];
				}
			}
		}
		int mx = n;
		for(int i = 0; i < n; ++i) {
			mx = min(mx, n - cnt[i] + i);
		}
		ans += mx;
	}
	printf("%d\n", ans);
	return 0;
}
