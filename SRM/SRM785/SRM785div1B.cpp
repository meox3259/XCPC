#include <bits/stdc++.h>

using namespace std;

class EllysTwoRatings {
	public:
	double getChance(int N, int A, int B) {
		vector<vector<double> > f(N + 1, vector<double> (1001));
		vector<vector<double> > g(N + 1, vector<double> (1001));

		f[0][A] = 1.;
		g[0][B] = 1.;
		for(int i = 0; i < N; ++i) {
			for(int j = 1; j <= 1000; ++j) {
				double div = min(j + 100, 1000) - max(1, j - 100) + 1; 
				int up = min(j + 100, 1000);
				for(int k = max(1, j - 100); k <= up; ++k) {
					f[i + 1][k] += f[i][j] * 1. / div;
					g[i + 1][k] += g[i][j] * 1. / div;
				}
			}
		}

		double ans = 0;
		for(int i = 0; i <= N; ++i) {
			for(int j = 0; j <= 1000; ++j) {
				ans += f[i][j] * g[i][j];
			}
		}
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j <= 1000; ++j) {
				ans += f[i + 1][j] * g[i][j];
			}
		}
		return ans;
	}
};
