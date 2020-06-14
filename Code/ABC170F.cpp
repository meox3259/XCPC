#include <bits/stdc++.h>

using namespace std;

const int M = 20000007;
const int inf = 1000000000;

int Pool = 0;

vector<pair<int, int> > G[M];
int lc[M], rc[M];

class SegmentTree {
	public:
	int N;
	int root;

	SegmentTree(int _N) { 
		N = _N;
		root = -1;
	}

	void build(int l, int r, int &x, const vector<int> &a) {
		if(x == -1) {
			x = Pool++;
		}
		if(l == r) {
			G[x].emplace_back(a[l], 1);
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, lc[x], a);
		build(mid + 1, r, rc[x], a);
		G[x].emplace_back(lc[x], 0);
		G[x].emplace_back(rc[x], 0);
	} 

	void update(int l, int r, int x, int a, int b, int cur) {
		if(l > b || r < a) {
			return;
		}
		if(l >= a && r <= b) {
			G[cur].emplace_back(x, 0);
			return;
		}
		int mid = l + r >> 1;
		update(l, mid, lc[x], a, b, cur);
		update(mid + 1, r, rc[x], a, b, cur);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, k;
	cin >> h >> w >> k;

	vector<string> s(h);

	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	--sx; --sy; --tx; --ty;
	
	for(int i = 0; i < h; ++i) {
		cin >> s[i];
	}

	memset(lc, -1, sizeof(lc));
	memset(rc, -1, sizeof(rc));

	vector<SegmentTree> row(h, SegmentTree(w));
	vector<SegmentTree> col(w, SegmentTree(h));

	Pool = h * w;

	auto id = [&] (int i, int j) {
		return i * w + j;
	};	

	for(int i = 0; i < h; ++i) {
		vector<int> a;
		for(int j = 0; j < w; ++j) {
			a.emplace_back(id(i, j));
		}
		row[i].build(0, w - 1, row[i].root, a);
	}

	for(int i = 0; i < w; ++i) {
		vector<int> a;
		for(int j = 0; j < h; ++j) {
			a.emplace_back(id(j, i));
		}
		col[i].build(0, h - 1, col[i].root, a);
	}

	for(int i = 0; i < h; ++i) {
		int last = -1;
		for(int j = 0; j < w; ++j) {
			if(s[i][j] != '@') {
				row[i].update(0, w - 1, row[i].root, max(last + 1, j - k), j, id(i, j));
			} else {
				last = j;
			}
		}
		last = w;
		for(int j = w - 1; j >= 0; --j) {
			if(s[i][j] != '@') {
				row[i].update(0, w - 1, row[i].root, j, min(last - 1, j + k), id(i, j));
			} else {
				last = j;
			}
		}
	}

	for(int i = 0; i < w; ++i) {
		int last = -1;
		for(int j = 0; j < h; ++j) {
			if(s[j][i] != '@') {
				col[i].update(0, h - 1, col[i].root, max(last + 1, j - k), j, id(j, i));
			} else {
				last = j;
			}
		}
		last = h;
		for(int j = h - 1; j >= 0; --j) {
			if(s[j][i] != '@') {
				col[i].update(0, h - 1, col[i].root, j, min(last - 1, j + k), id(j, i));
			} else {
				last = j;
			}
		}
	}

	deque<int> q;
	q.push_front(id(sx, sy));

	vector<int> d(M, inf);
	d[id(sx, sy)] = 0;

	while(!q.empty()) {
		int u = q.front();
		q.pop_front();

		for(auto [v, w] : G[u]) {
			if(w == 0) {
				if(d[v] > d[u]) {
					d[v] = d[u];
					q.push_front(v);
				}
			} else {
				if(d[v] > d[u] + 1) {
					d[v] = d[u] + 1;
					q.push_back(v);
				}
			}
		}
	}

	if(d[id(tx, ty)] == inf) {
		cout << -1 << '\n';
	} else {
		cout << d[id(tx, ty)] << '\n';
	}

	return 0;
}
