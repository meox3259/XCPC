#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, k;
double p[maxn], sum[maxn];
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		double x;
		scanf("%lf", &x);
		sum[i] = sum[i - 1] + x;
	}
	double ans = 0;
	for(int i = k; i <= n; ++i) {
		ans = max(ans, (sum[i] - sum[i - k] + k) / 2.0);
	}
	printf("%.10f\n", ans);
	return 0;
}
