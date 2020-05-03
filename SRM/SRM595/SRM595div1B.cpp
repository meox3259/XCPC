#include <bits/stdc++.h>

using namespace std;

class LittleElephantAndRGB {
	public:
	long long getNumber(vector <string> list, int g) {
		string s = "";
		for(string t : list) {
			s += t;
		}

		int n = s.size();
		vector<vector<int> > sum(n, vector<int> (n + 1, 0));

		for(int i = 0; i < n; ++i) {
			int cur = 0;
			int mx = 0;
			bool ok = true;
			int pre = 0;
			for(int j = i; j >= 0; --j) {
				if(s[j] != 'G') {
					if(ok) {
						pre = cur;
					}
					ok = false;
					cur = 0;
				} else {
					++cur;
				}
				mx = max(mx, cur);
				if(ok) {
					++sum[i][cur];
				} else if(mx >= g) {
					++sum[i][mx];
				} else {
					++sum[i][pre];
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = n - 1; j >= 0; --j) {
				sum[i][j] += sum[i][j + 1];
			}
		}
		for(int i = 0; i + 1 < n; ++i) {
			for(int j = 0; j <= n; ++j) {
				sum[i + 1][j] += sum[i][j];
			}
		}
		long long ans = 0;
		for(int i = 1; i < n; ++i) {
			int cur = 0;
			int mx = 0;
			bool ok = true;
			int pre = 0;
			for(int j = i; j < n; ++j) {
				if(s[j] != 'G') {
					if(ok) {
						pre = cur;
					}
					cur = 0;
					ok = false;
				} else {
					++cur;
				}
				mx = max(mx, cur);
				if(ok) {
					ans += sum[i - 1][max(0, g - cur)];
				} else if(mx >= g) {
					ans += sum[i - 1][0];
				} else {
					ans += sum[i - 1][max(0, g - pre)];
				}
			}
		}
		return ans;
	}
};
