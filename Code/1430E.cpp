#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	string t(s);
	reverse(t.begin(), t.end());

	vector<int> cnt(26);
	long long ans = 0;

	vector<vector<int> > pre(n + 1, vector<int> (26));
	vector<vector<int> > rev(n + 1, vector<int> (26));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 26; ++j) {		
			pre[i + 1] = pre[i];
			pre[i + 1][s[i] - 'a'] += 1;
			rev[i + 1] = rev[i];
			rev[i + 1][t[i] - 'a'] += 1;
		}
	}

	vector<vector<int> > f(26);
	vector<vector<int> > b(26);
	for(int i = 0; i < n; ++i) {
		f[s[i] - 'a'].emplace_back(i);
		b[t[i] - 'a'].emplace_back(i);
	}

	for(int j = 0; j < 26; ++j) {
		for(int i = 0; i < f[j].size(); ++i) {
			for(int k = 0; k < j; ++k) {
				ans += abs(pre[f[j][i] + 1][k] - rev[b[j][i] + 1][k]);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
