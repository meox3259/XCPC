#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		vector<long long> x(4);
		vector<long long> y(4);
		for(int i = 0; i < 4; ++i) {
			cin >> x[i] >> y[i];
		}

		long long l = 0;
		long long r = 2000000001;

		auto calc = [&] (long long d) {
			vector<int> id(4);
			iota(id.begin(), id.end(), 0);
			long long ret = inf;
			do {
				long long sum = 0;	
				vector<long long> xa(4);
				xa[0] = x[id[0]];
				xa[1] = x[id[1]];
				xa[2] = x[id[2]] - d;
				xa[3] = x[id[3]] - d;
				sort(xa.begin(), xa.end());

				vector<long long> ya(4);
				ya[0] = y[id[0]];
				ya[1] = y[id[1]] - d;
				ya[2] = y[id[2]] - d;
				ya[3] = y[id[3]];
				sort(ya.begin(), ya.end());
				sum = xa[3] + xa[2] - xa[1] - xa[0] + ya[3] + ya[2] - ya[1] - ya[0];
				ret = min(ret, sum);
			} while(next_permutation(id.begin(), id.end()));
			return ret;
		};	

		long long ans = inf;
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				ans = min(ans, calc(abs(x[i] - x[j])));
				ans = min(ans, calc(abs(y[i] - y[j])));
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
