#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const ll inf = 1e17;
int n = 1;
ll ax, ay, bx, by, sx, sy, t;
ll x[maxn], y[maxn];
ll dp[105][105][105];
int main() {
	cin >> x[1] >> y[1] >> ax >> ay >> bx >> by;
	cin >> sx >> sy >> t;
	for(;;) {
		x[n + 1] = x[n] * ax + bx;
		y[n + 1] = y[n] * ay + by;
		if(x[n + 1] > inf || y[n + 1] > inf) {
			break;
		} 
		++n;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			for(int k = i; k <= j; ++k) {
				ll d = 0, t1 = 0, t2 = 0;
				d += abs(sx - x[k]) + abs(sy - y[k]);
				for(int l = k; l < j; ++l) {
					t1 += abs(x[l] - x[l + 1]) + abs(y[l] - y[l + 1]);
				}
				if(k > i) {
					t1 += abs(x[j] - x[k - 1]) + abs(y[j] - y[k - 1]); 
				}
				for(int l = i; l < k - 1; ++l) {
					t1 += abs(x[l] - x[l + 1]) + abs(y[l] - y[l + 1]);
				}
				for(int l = i; l < k; ++l) {
					t2 += abs(x[l] - x[l + 1]) + abs(y[l] - y[l + 1]);
				}
				if(k + 1 <= j) {
					t2 += abs(x[i] - x[k + 1]) + abs(y[i] - y[k + 1]);
				}
				for(int l = k + 1; l < j; ++l) {
					t2 += abs(x[l] - x[l + 1]) + abs(y[l] - y[l + 1]);
				}
				if(d + min(t1, t2) <= t) {
					ans = max(ans, j - i + 1);
				}
			}	
		}
	}
	cout << ans << endl;
	return 0;
}
