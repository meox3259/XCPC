#include <bits/stdc++.h>

using namespace std;

class XorCards {
	public:
	long long numberOfWays(vector<long long> number, long long limit) {
		int n = number.size();
		auto gauss_jordan = [&] (int Bound, vector<int> a) {
			vector<vector<int> > g(51, vector<int> (n + 1, 0));
			for(int i = 50; i >= Bound; --i) {
				for(int j = 0; j < n; ++j) {
					if(number[j] >> i & 1) {
						g[i][j] = 1;
					}
				}
				g[i][n] = a[i];
			} 
			int Free = n;
			for(int i = 50; i >= Bound; --i) {
				int p = -1;
				for(int j = 0; j < n; ++j) {
					if(g[i][j] != 0) {
						p = j;
						break;
					}
				}
				if(p == -1) {
					if(g[i][n] == 1) {
						return 0LL;
					} else {
						continue;
					}
				}

				--Free;

				for(int j = i - 1; j >= Bound; --j) {
					if(g[j][p]) {
						for(int k = 0; k <= n; ++k) {
							g[j][k] ^= g[i][k];
						}
					}
				}
			}

			return 1LL << Free;
		};

		long long ans = 0;
	
		vector<int> a(51);

		for(int i = 50; i >= 0; --i) {
			if(limit >> i & 1) {
				ans += gauss_jordan(i, a);
				a[i] = 1;
			}
		}

		ans += gauss_jordan(0, a);

		return ans;
	}
};
