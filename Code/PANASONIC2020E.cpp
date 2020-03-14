#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> s;
	s.resize(3);
	
	for(int i = 0; i < 3; ++i) {
		cin >> s[i];
	}

	int n = 0;

	for(int i = 0; i < 3; ++i) {
		n = max(n, (int)s[i].size());
	}

	vector<vector<vector<bool> > > can;
	can.resize(3);
	for(int i = 0; i < 3; ++i) {
		can[i].resize(3);
		for(int j = 0; j < 3; ++j) {
			can[i][j].assign(n + 1, true);
		}
	}

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(i != j) {
				for(int k = 0; k < s[i].size(); ++k) {
					for(int p = 0; p < s[j].size() && k + p < s[i].size(); ++p) {
						if(s[i][k + p] != '?' && s[j][p] != '?' && s[i][k + p] != s[j][p]) {
							can[i][j][k] = false;
							break;
						}
					}
				}
			}
		}
	}

	int ans = s[0].size() + s[1].size() + s[2].size();

	function<void(int, int, int)> solve = [&] (int x, int y, int z) {
		for(int i = 0; i <= s[x].size(); ++i) {
			if(can[x][y][i]) {
				for(int j = i; j <= max(i + s[y].size(), s[x].size()); ++j) {
					if(j < s[x].size()) {
						if(can[x][z][j] && (j >= i + s[y].size() || can[y][z][j - i])) {
							ans = min(ans, max((int)s[x].size(), max(i + (int)s[y].size(), j + (int)s[z].size())));
						}
					} else if(can[y][z][j - i]) {
						ans = min(ans, max(i + (int)s[y].size(), j + (int)s[z].size()));
					}
				}			
			}
		}
	};

	solve(0, 1, 2);
	solve(0, 2, 1);
	solve(1, 0, 2);
	solve(1, 2, 0);
	solve(2, 0, 1);
	solve(2, 1, 0);

	cout << ans << '\n';
	return 0;
}
