#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >>k;

	vector<int> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b;
	b.resize(m);

	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	long long ans = 0;

	auto calc = [&] (vector<int> &a, int d) {
		long long ret = 0;

		int sum = 0;

		for(auto x : a) {
			if(x == 1) {
				++sum;
			} else {
				sum = 0;
			}

			if(sum >= d) {
				++ret;
			}
		}

		return ret;
	};

	for(int i = 1; i * i <= k; ++i) {
		if(k % i == 0) {
			ans += calc(a, i) * calc(b, k / i);

			if(i * i != k) {
				ans += calc(a, k / i) * calc(b, i);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
