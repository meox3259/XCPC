#include <bits/stdc++.h>

using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;

	vector<string> s(h);
	for(int i = 0; i < h; ++i) {
		cin >> s[i];
	}

	queue<int> q;
	vector<vector<int> > d(h, vector<int> (w, -1));

	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if(s[i][j] == '#') {
				q.emplace(i);
				q.emplace(j);
				d[i][j] = 0;
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
			if(0 <= xx && xx < h && 0 <= yy && yy < w && d[xx][yy] == -1) {
				d[xx][yy] = d[x][y] + 1;
				q.emplace(xx);
				q.emplace(yy);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			ans = max(ans, d[i][j]);
		}
	}

	cout << ans << '\n';

	return 0;
}
