#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(0));
	int n;
	cin >> n;
	vector<long long> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<long long> b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	random_shuffle(b.begin(), b.end());
	long long ans = n;
	map<long long, long long> mp;
	auto calc = [&] (long long x) {
		if(mp.count(x)) {
			return mp[x];
		}
		long long ret = 0;
		for(auto y : a) {
			if(y < x) {
				ret += x - y;
			} else {
				ret += min(x - y % x, y % x);
			}
		}
		return mp[x] = ret;
	};
	function<void(long long)> solve = [&] (long long x) {
		if(x <= 1) {
			return;
		}
		for(long long i = 2; i * i <= x; ++i) {
			if(x % i == 0) {
				ans = min(ans, calc(i));
				while(x % i == 0) {
					x /= i;
				}
			}
		}
		if(x > 1) {
			ans = min(ans, calc(x));
		}
	};

	for(int i = 0; i < 100; ++i) {
		int p = 1LL * rand() * rand() % n; 
		solve(a[p] - 1);
		solve(a[p]);
		solve(a[p] + 1);
	}
	cout << ans << '\n';
	return 0;
}
