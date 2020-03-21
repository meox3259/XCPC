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

		vector<long long> xa;
		xa.resize(n);

		vector<long long> ya;
		ya.resize(n);

		vector<long long> xb;
		xb.resize(n);

		vector<long long> yb;
		yb.resize(n);

		map<tuple<long long, long long, long long, long long>, long long> line;
		map<pair<long long, long long>, long long> same;

		for(int i = 0; i < n; ++i) {
			cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];

			long long dx = xa[i] - xb[i];
			long long dy = yb[i] - ya[i];
			long long dc = xb[i] * ya[i] - xa[i] * yb[i];

			long long d = __gcd(dx, dy);

			dx /= d;
			dy /= d;

			if(dx < 0) {
				dx = -dx;
				dy = -dy;
				d = -d;
			}

			long long D = __gcd(d, dc);

			d /= D;
			dc /= D;

			if(dc < 0) {
				dc = -dc;
				d = -d;
			}

			++line[{dx, dy, dc, d}];
			++same[{dx, dy}];

		}

		long long ans = 0;

		for(auto& p : line) {
			pair<long long, long long> o = {get<0>(p.first), get<1>(p.first)};
			ans += p.second * (n - same[o] + p.second);
		}

		cout << (ans - n) / 2 << '\n';
	}

	return 0;
}
