#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, x;
		cin >> n >> x;

		vector<int> a;
		a.resize(n);

		for(int &i : a) {
			cin >> i;
		}

		long long sum = 0;

		sort(a.begin(), a.end(), greater<int>());

		int ans = 0;

		for(int i = 0; i < n; ++i) {
			sum += a[i];

			if(1LL * (i + 1) * x <= sum) {
				ans = i + 1;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
