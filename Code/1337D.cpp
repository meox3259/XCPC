#include <bits/stdc++.h>

using namespace std;

const long long inf = 8000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int x, y, z;
		cin >> x >> y >> z;

		vector<int> r;
		r.resize(x);

		for(int &i : r) {
			cin >> i;
		}

		vector<int> g;
		g.resize(y);

		for(int &i : g) {
			cin >> i;
		}

		vector<int> b;
		b.resize(z);

		for(int &i : b) {
			cin >> i;
		}

		sort(r.begin(), r.end());
		sort(g.begin(), g.end());
		sort(b.begin(), b.end());

		auto sqr = [&] (long long x) {
			return x * x;
		};

		auto solve = [&] (const vector<int> &a, const vector<int> &b, const vector<int> &c) {
			long long ret = inf;

			for(int i = 0; i < b.size(); ++i) {
				long long B = b[i];
				auto ita = upper_bound(a.begin(), a.end(), B);
				if(ita != a.begin()) {
					--ita;
				}
				long long A = *ita;
				auto itc = lower_bound(c.begin(), c.end(), B);
				if(itc == c.end()) {
					--itc;
				}
				long long C = *itc;
				ret = min(ret, sqr(A - B) + sqr(B - C) + sqr(C - A));
			}

			return ret;
		};

		long long ans = inf;
		ans = min(ans, solve(r, g, b));
		ans = min(ans, solve(r, b, g));
		ans = min(ans, solve(g, r, b));
		ans = min(ans, solve(g, b, r));
		ans = min(ans, solve(b, r, g));
		ans = min(ans, solve(b, g, r));

		cout << ans << '\n';
	}

	return 0;
}
