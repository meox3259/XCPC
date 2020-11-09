#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int mx = 0;
	int ans = 1;
	for(int k = 2; k <= 1000; ++k) {
		int cnt = 0;
		for(int i : a) {
			if(i % k == 0) {
				cnt += 1;
			}
		}
		if(cnt > mx) {
			mx = cnt;
			ans = k;
		}
	}

	cout << ans << '\n';

	return 0;
}
