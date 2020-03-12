#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node {
	int x, y, w;
	node() = default;
	node(int _x, int _y, int _w) : x(_x), y(_y), w(_w) {}
	bool friend operator < (const node &a, const node &b) {
		return a.w > b.w;
	}
};
int n, h, w;
int fa[maxn * 2], sz[maxn * 2];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> h >> w;
	vector<node> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].w;
		a[i].y += h; 
	}
	sort(a.begin(), a.end());
	for(int i = 1; i <= h + w; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		int x = find(a[i].x), y = find(a[i].y);
		if(x != y) {
			fa[x] = y;
			sz[y] += sz[x];
		}
		if(sz[y]) {
			--sz[y];
			ans += a[i].w;
		}
	}
	cout << ans << '\n';
	return 0;
}
