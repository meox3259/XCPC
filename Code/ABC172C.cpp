#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	long long k;
	cin >> n >> m >> k;

	vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long> b(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	int j = -1;
	long long sum = 0;
	while(j + 1 < n) {
		if(sum + a[j + 1] <= k) {
			sum += a[j + 1];
			j += 1;
		} else {
			break;
		}
	}
	int ans = j + 1;
	for(int i = 0; i < m; ++i) {
		sum += b[i];
		while(j >= 0 && sum > k) {
			sum -= a[j];
			j -= 1;
		}
		if(sum <= k) {
			ans = max(ans, i + 1 + j + 1);
		}
	}

	cout << ans << '\n';

	return 0;
}
