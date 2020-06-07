#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long ans = *max_element(a.begin(), a.end());
	
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			ans = max(ans, a[i] | a[j]);
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			for(int k = j + 1; k < n; ++k) {
				ans = max(ans, a[i] | a[j] | a[k]);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
