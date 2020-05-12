#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t;
	cin >> n >> m >> t;

	vector<string> s(n);
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	vector<vector<int> > d(n, vector<int> (m, -1));

	queue<int> q;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			bool notsame = true;
			for(int k = 0; k < 4; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];
				if(0 <= x && x < n && 0 <= y && y < m && s[i][j] == s[x][y]) {
					notsame = false;
				}
			}
			if(!notsame) {
				d[i][j] = 0;
				q.emplace(i);
				q.emplace(j);
			}
		}
	}

	while(!q.empty()) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();

		for(int i = 0; i < 4; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if(0 <= xx && xx < n && 0 <= yy && yy < m && d[xx][yy] == -1) {
				d[xx][yy] = d[x][y] + 1;
				q.emplace(xx);
				q.emplace(yy);
			}
		}
	}

	while(t--) {
		int i, j;
		long long p;
		cin >> i >> j >> p;
		--i; --j;

		int v = s[i][j] - '0';

		if(d[i][j] == -1) {
			cout << v << '\n';
		} else {
			if(p < d[i][j]) {
				cout << v << '\n';
			} else {
				long long D = p - d[i][j];
				if(D % 2 == 1) {
					cout << (v ^ 1) << '\n';
				} else {
					cout << v << '\n';
				}
			}
		}
	}

	return 0;
}
