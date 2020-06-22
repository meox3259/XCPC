#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int l = 0;
	int r = 1000000001;
	int ans = 1000000001;

	auto check = [&] (int v) {
		int last = -2;
		int cnt = 0;
		for(int i = 1; i < n; ++i) {
			if(a[i] <= v && i - last >= 2) {
				cnt += 1;
				last = i;
			}
		}

		if(k % 2 == 0) {
			if(cnt >= k / 2) {
				return true;
			}
		} else {
			if(cnt >= (k + 1) / 2) {
				return true;
			}
			if(cnt == k / 2 && last != n - 1) {
				return true;
			}
		}

		last = -2;
		cnt = 0;
		for(int i = 0; i < n; ++i) {
			if(a[i] <= v && i - last >= 2) {
				cnt += 1;
				last = i;
			}			
		}

		if(k % 2 == 0) {
			if(cnt >= k / 2 + 1) {
				return true;
			}
			if(cnt == k / 2 && last != n - 1) {
				return true;
			}	
		} else {
			if(cnt >= (k + 1) / 2) {
				return true;
			}
		}

		return false;
	};

	while(r - l > 1) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			r = ans = mid;
		} else {
			l = mid;
		}
	}

	cout << ans << '\n';
	
	return 0;
}
