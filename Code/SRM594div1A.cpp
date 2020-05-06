#include <bits/stdc++.h>

using namespace std;

template <typename T>
void chkmax(T &a, T b) {
	if(a < b) {
		a = b;
	}
}

class AstronomicalRecords {
	public:
	int minimalPlanets(vector <int> A, vector <int> B) {
		auto solve = [&] (const vector<int> &x, const vector<int> &y) {
			int n = x.size();
			int m = y.size();
			vector<vector<int> > dp(n + 1, vector<int> (m + 1, 0));

			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j) {
					if(1LL * x[i] * y[0] == 1LL * y[j] * x[0]) {
						chkmax(dp[i + 1][j + 1], dp[i][j] + 1);
					}
					chkmax(dp[i + 1][j], dp[i][j]);
					chkmax(dp[i][j + 1], dp[i][j]);
				}
			}

			int ret = 0;
			for(int i = 0; i <= n; ++i) {
				for(int j = 0; j <= m; ++j) {
					ret = max(ret, dp[i][j]);
				}
			}

			return ret;
		};

		int n = A.size();
		int m = B.size();
		int ret = n + m;

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				vector<int> x;
				vector<int> y;
				for(int k = i; k < n; ++k) {
					x.emplace_back(A[k]);
				}
				for(int k = j; k < m; ++k) {
					y.emplace_back(B[k]);
				}

				int tmp = 0;
				tmp += n - i + m - j - solve(x, y);
				
				x.clear();
				y.clear();

				for(int k = 0; k <= i; ++k) {
					x.emplace_back(A[k]);
				}
				for(int k = 0; k <= j; ++k) {
					y.emplace_back(B[k]);
				}

				reverse(x.begin(), x.end());
				reverse(y.begin(), y.end());

				tmp += i + 1 + j + 1 - solve(x, y);
				tmp -= 1;

				ret = min(ret, tmp);
			}
		}
		return ret;
	}	
};
