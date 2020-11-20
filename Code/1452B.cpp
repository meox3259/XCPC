#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		long long sum = 0;
		for(int i : a) {
			sum += i;
		}

		long long x = max((sum + n - 2) / (n - 1), 1LL * *max_element(a.begin(), a.end()));

		cout << x * (n - 1) - sum << '\n';
	}

	return 0;
}
