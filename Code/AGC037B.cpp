#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	long long ans = 1;
	vector<long long> cnt(9);

	for(char c : s) {
		if(c == 'R') {
			long long x = cnt[5] + cnt[6];
			long long y = cnt[1] + cnt[2];
			if(x > 0) {
				ans = ans * x % P;
				if(cnt[5] > 0) {
					cnt[5] -= 1;
				} else {
					cnt[6] -= 1;
				}
			} else if(y > 0) {
				ans = ans * y % P;
				if(cnt[1] > 0) {
					cnt[1] -= 1;
					cnt[4] += 1;
				} else {
					cnt[2] -= 1;
					cnt[8] += 1;
				}
			} else {
				cnt[0] += 1;
			}
		}
		if(c == 'G') {
			long long x = cnt[7] + cnt[8];
			long long y = cnt[0] + cnt[2];
			if(x > 0) {
				ans = ans * x % P;
				if(cnt[7] > 0) {
					cnt[7] -= 1;
				} else {
					cnt[8] -= 1;
				}
			} else if(y > 0) {
				ans = ans * y % P;
				if(cnt[0] > 0) {
					cnt[0] -= 1;
					cnt[3] += 1;
				} else {
					cnt[2] -= 1;
					cnt[6] += 1;
				}
			} else {
				cnt[1] += 1;
			}
		}
		if(c == 'B') {
			long long x = cnt[3] + cnt[4];
			long long y = cnt[0] + cnt[1];
			if(x > 0) {
				ans = ans * x % P;
				if(cnt[3] > 0) {
					cnt[3] -= 1;
				} else {
					cnt[4] -= 1;
				}
			} else if(y > 0) {
				ans = ans * y % P;
				if(cnt[0] > 0) {
					cnt[0] -= 1;
					cnt[7] += 1;
				} else {
					cnt[1] -= 1;
					cnt[5] += 1;
				}
			} else {
				cnt[2] += 1;
			}
		}
	}

	for(int i = 1; i <= n; ++i) {
		ans = ans * i % P;
	}

	cout << ans << '\n';

	return 0;
}
