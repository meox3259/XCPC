#include <bits/stdc++.h>
using namespace std;
class CliqueParty {
	public:
		int maxsize(vector <int> a, int k) {
			int n = a.size(), ans = 1;
			sort(a.begin(), a.end());
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					vector<vector<int> > dp(n + 5, vector<int>(n + 5, -0x3f3f3f3f));
					dp[i][i] = 1;
					for(int x = i + 1; x < j; ++x) {
						if(1LL * k * (a[x] - a[i]) >= a[j] - a[i] && 1LL * k * (a[j] - a[x]) >= a[j] - a[i]) {
							dp[x][x] = 1;
						}
						for(int y = i; y < x; ++y) {
							if(1LL * k * (a[x] - a[y]) >= a[j] - a[i] && 
							   1LL * k * (a[x] - a[i]) >= a[j] - a[i] && 1LL * k * (a[j] - a[x]) >= a[j] - a[i]) {
								dp[x][x] = max(dp[x][x], dp[x - 1][y] + 1);
							}
							dp[x][y] = dp[x - 1][y];
						}
					}
					for(int x = i; x <= j; ++x) {
						ans = max(ans, dp[j - 1][x] + 1);
					}
				}
			}
			return ans;
		}
}; /*
int main() {
	CliqueParty A;
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	cout << A.maxsize(a, k);
	return 0;
}*/

