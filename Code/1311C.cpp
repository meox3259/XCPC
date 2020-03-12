#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		string s;
		cin >> n >> m >> s;
		vector<vector<int> > sum;
		sum.resize(n);
		for(int i = 0; i < n; ++i) {
			sum[i].resize(26);
		}
		for(int i = 0; i < n; ++i) {
			if(i > 0) {
				sum[i] = sum[i - 1];
			}
			++sum[i][s[i] - 'a'];
		}
		vector<long long> ans;
		ans.resize(26);
		for(int i = 0; i < m; ++i) {
			int p;
			cin >> p;
			--p;
			for(int j = 0; j < 26; ++j) {
				ans[j] += sum[p][j];
			}
		}
		for(int j = 0; j < 26; ++j) {
			ans[j] += sum[n - 1][j];
		}
		for(int i = 0; i < 26; ++i) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
