#include <bits/stdc++.h>

using namespace std;

const int N = 400005;

int a[N];
int b[N];
long long pre[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for(int i = 1; i <= m; ++i) {
		cin >> b[i];
	}

	sort(a + 1, a + n + 1);

	for(int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + ((i & 1) ? -a[i] : a[i]);
	}

	long long ans = 1000000000000000000;
	for(int i = 1; i <= m; ++i) {
		int v = b[i];
		int p = lower_bound(a + 1, a + n + 1, v) - a;	
		if(p == n + 1) {
			ans = min(ans, v + pre[n]);
		} else {
			if(v < a[p]) {
				p -= 1;
			}
			if(p == 0) {
				ans = min(ans, -pre[n] - v);
			} else {
				if(p & 1) {
					ans = min(ans, v + pre[p] - (pre[n] - pre[p]));
				} else {
					ans = min(ans, pre[p] - v - (pre[n] - pre[p]));
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
