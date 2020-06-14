#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int m = 1000001;

	vector<int> a(n);
	vector<int> cnt(m);
	vector<bool> vis(m);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]] += 1;
	}

	for(int i = 1; i < m; ++i) {
		if(cnt[i] > 0) {
			for(int j = i + i; j < m; j += i) {
				vis[j] = true;
			}
		}
	}

	long long ans = n;

	for(int i : a) {
		if(cnt[i] > 1 || vis[i]) {
			ans -= 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
