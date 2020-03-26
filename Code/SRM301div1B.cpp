#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

class EscapingJail {
	public:
		int getMaxDistance(vector <string> chain) {
			int n = chain.size();

			vector<vector<int> > d;
			d.resize(n);

			for(int i = 0; i < n; ++i) {
				d[i].assign(n, inf);
			}

			for(int i = 0; i < n; ++i) {
				d[i][i] = 0;
			}

			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					char c = chain[i][j];
					
					if(isdigit(c)) {
						d[i][j] = c - '0';
					}

					if(islower(c)) {
						d[i][j] = 10 + c - 'a';
					}

					if(isupper(c)) {
						d[i][j] = 36 + c - 'A';
					}
				}
			}

			for(int k = 0; k < n; ++k) {
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < n; ++j) {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}

			int ans = 0;

			for(int i = 0; i < n; ++i) {
				ans = max(ans, *max_element(d[i].begin(), d[i].end()));
			}

			return ans == inf ? -1 : ans;
		}
};
