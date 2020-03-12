#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long inf = 1e16;
vector<ll> mx;
vector<ll> tag;
vector<vector<int> > v;
struct data {
	int x, y, k;
	data() = default;
	data(int _x, int _y, int _k) : x(_x), y(_y), k(_k) {}
	bool friend operator < (const data &a, const data &b) {
		return a.y < b.y;
	}
} c[1000005];
void build(int l, int r, int x) {
	if(l == r) {
		mx[x] = v[l].empty() ? -inf : *max_element(v[l].begin(), v[l].end());
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, x << 1);
	build(mid + 1, r, x << 1 | 1);
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
void pushdown(int x) {
	tag[x << 1] += tag[x];
	tag[x << 1 | 1] += tag[x];
	mx[x << 1] += tag[x];
	mx[x << 1 | 1] += tag[x];
	tag[x] = 0;
}
void update(int l, int r, int x, int a, int b, int v) {
	if(l > b || r < a) {
		return;
	}
	if(l >= a && r <= b) {
		tag[x] += v;
		mx[x] += v;
		return;
	}
	pushdown(x);
	int mid = l + r >> 1;
	update(l, mid, x << 1, a, b, v);
	update(mid + 1, r, x << 1 | 1, a, b, v);
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, p, R = 0;
	cin >> n >> m >> p;
	v.resize(1000001);
	for(int i = 0; i < n; ++i) {
		int a, ca;
		cin >> a >> ca;
		v[a].emplace_back(-ca);
		R = max(R, a);
	}
	vector<pair<int, int> > B;
	B.resize(m);
	for(int i = 0; i < m; ++i) {
		cin >> B[i].first >> B[i].second;
	}
	sort(B.begin(), B.end());
	mx.resize(4 * R + 5);
	tag.resize(4 * R + 5);
	build(1, R, 1);
	for(int i = 0; i < p; ++i) {
		cin >> c[i].x >> c[i].y >> c[i].k;
	}
	sort(c, c + p);
	ll ans = -inf;
	for(int i = 0, j = -1; i < m; ++i) {
		auto [b, cb] = B[i];
		while(j + 1 < p && c[j + 1].y < b) {
			++j;
			update(1, R, 1, c[j].x + 1, R, c[j].k);
		}
		ans = max(ans, -cb + mx[1]);
	}
	cout << ans << '\n';
	return 0;
}
