#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int n, c;
int x[maxn];
bool check(int d) {
	int cnt = 1, last = 1;
	for(int i = 2; i <= n; ++i) {
		if(x[i] - last >= d) {
			last = x[i];
			++cnt;
		}
	}
	return cnt >= c;
}
int main() {
	scanf("%d%d", &n, &c);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
	}
	sort(x + 1, x + n + 1);
	int l = 0, r = x[n] + 1, ans = 0;
	while(r - l > 1) {
		int mid = l + r >> 1;
		if(check(mid)) {
			l = ans = mid;
		} else {
			r = mid;
		}
	}
	printf("%d\n", ans);
	return 0;
}
