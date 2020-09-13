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

	int q;
	cin >> q;

	long long down = 0;
	long long up = 0;
	for(int i = 0; i + 1 < n; ++i) {
		if(a[i] < a[i + 1]) {
			up += a[i + 1] - a[i];
		} else {
			down += a[i] - a[i + 1];
		}
	}

	vector<long long> dif(n);
	for(int i = 0; i < n - 1; ++i) {
		dif[i + 1] = a[i + 1] - a[i];
	}

	long long a0 = a[0];

	auto calc = [&] (long long x, long long y) {
		long long tmp = abs(-x + y) / 2;
		long long ret = 1000000000000000000;
		if(x < y) {
			tmp = -tmp;
		}
		for(long long i = tmp - 2; i <= tmp + 2; ++i) {
			ret = min(ret, max(x - i, i + y));
		}
		return ret;
	};

	cout << calc(a0, up) << '\n';

	while(q--) {
		int l, r, x;
		cin >> l >> r >> x;

		if(l == 1) {
			a0 += x;
		}	
		
		if(l >= 2) {
			if(dif[l - 1] >= 0) {
				up -= dif[l - 1];
			} else {
				down += dif[l - 1];
			}
			dif[l - 1] += x;
			if(dif[l - 1] >= 0) {
				up += dif[l - 1];
			} else {
				down -= dif[l - 1];
			}
		}

		if(r < n) {
			if(dif[r] >= 0) {
				up -= dif[r];
			} else {
				down += dif[r];
			}
			dif[r] -= x;
			if(dif[r] >= 0) {
				up += dif[r];
			} else {
				down -= dif[r];
			}
		}

		cout << calc(a0, up) << '\n';
	}

	return 0;
}
