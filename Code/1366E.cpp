#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
const int maxn = 200005;
const int inf = 1000000001;

int mn[maxn * 4];

vector<int> a;
vector<int> b;

int query(int l, int r, int x, int a, int b) {
	if(l > b || r < a) {
		return inf;
	}
	if(l >= a && r <= b) {
		return mn[x];
	}
	int mid = l + r >> 1;
	return min(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
}

void build(int l, int r, int x) {
	if(l == r) {
		mn[x] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, x << 1);
	build(mid + 1, r, x << 1 | 1);
	mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	a.resize(n + 1);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	n += 1;
	a[n - 1] = inf;

	build(0, n - 1, 1);

	b.resize(m + 1);

	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	m += 1;
	b[m - 1] = inf;

	if(*min_element(a.begin(), a.end()) < b[0]) {
		cout << 0 << '\n';
		exit(0);
	}

	map<int, int> pos;

	for(int i = 0; i < n; ++i) {
		pos[a[i]] = max(pos[a[i]], i);
	}

	for(int i = 0; i + 1 < m; ++i) {
		if(pos.count(b[i]) == 0) {
			cout << 0 << '\n';
			exit(0);
		}
		if(pos[b[i]] > pos[b[i + 1]]) {
			cout << 0 << '\n';
			exit(0);
		}
	}

	long long ans = 1;

	for(int i = 0; i + 1 < m; ++i) {
		int l = pos[b[i]];
		int r = pos[b[i + 1]];
		long long cnt = 0;
		for(int j = l; j < r; ++j) {
			int lm = query(0, n - 1, 1, l, j);
			int rm = query(0, n - 1, 1, j + 1, r);
			if(lm == b[i] && rm == b[i + 1]) {
				cnt += 1;
			}
		}
		ans = ans * cnt % P;
	}

	cout << ans << '\n';

	return 0;
}
