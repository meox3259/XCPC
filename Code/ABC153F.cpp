#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, d, a;
pair<int, int> p[maxn];
int main() {
	scanf("%d%d%d", &n, &d, &a);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &p[i].first, &p[i].second);
		p[i].second = (p[i].second + a - 1) / a;
	}
	sort(p + 1, p + n + 1);
	int cnt = 0;
	long long ans = 0;
	for(int i = 1, j = 1; i <= n; ++i) {
		while(p[i].first - p[j].first > 2 * d) {
			cnt -= p[j].second;
			++j;
		}
		ans += max(0, p[i].second - cnt);
		p[i].second = max(0, p[i].second - cnt);
		cnt += p[i].second;
	}
	printf("%lld\n", ans);
	return 0;
}
