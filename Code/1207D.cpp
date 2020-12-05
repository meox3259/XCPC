#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

long long power(long long x, long long t) {
	long long ret = 1;
	for (; t; t >>= 1, x = x * x % P) {
		if (t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}

long long inv(long long x) {
	return power(x, P - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		--a[i]; --b[i];
	}

	vector<pair<int, int> > s;
	for (int i = 0; i < n; ++i) {
		s.emplace_back(a[i], b[i]);
	}

	vector<long long> fac(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % P;
	}

	long long ans = 0;

	long long di = 1;
	vector<int> ci(n);
	for (int i : a) {
		ci[i] ++;
	}

	for (int i : ci) {
		di = di * fac[i] % P;
	}

	long long dj = 1;
	vector<int> cj(n);
	for (int i : b) {
		cj[i] ++;
	}

	for (int i : cj) {
		dj = dj * fac[i] % P;
	}

	map<pair<int, int>, int> ck;
	for (auto o : s) {
		ck[o] ++;
	}

	sort(s.begin(), s.end());

	bool ok = true;

	for (int i = 0; i + 1 < n; ++i) {
		if (s[i].first > s[i + 1].first || s[i].second > s[i + 1].second) {
			ok = false;
		}
	}

	ans = (di + dj) % P;

	if (ok) {
		long long dk = 1;
		map<pair<int, int>, int> ck;
		for (auto o : s) {
			ck[o] ++;
		}
		for (auto o : ck) {
			dk = dk * fac[o.second] % P;
		}
		ans = (ans - dk + P) % P;
	}

	cout << (fac[n] - ans + P) % P << '\n';

	return 0;
}
