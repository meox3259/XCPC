#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int delta = 1e9 + 5;
struct Circle {
	int x, y, r, id;
	bool del;
	Circle() = default;
	Circle(int _x, int _y, int _r, int _id, bool _del) : x(_x), y(_y), r(_r), id(_id), del(_del) {}
	bool friend operator < (const Circle &a, const Circle &b) {
		return a.r == b.r ? a.id < b.id : a.r > b.r;
	}
} a[maxn];
int n;
int ans[maxn];
bool check(Circle a, Circle b) {
	return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y) <= 1LL * (a.r + b.r) * (a.r + b.r);
}
map<pair<int, int>, int> Hash;
vector<int> p[maxn];
void build(int r_max) {
	int tot = 0;
	Hash.clear();
	for(int i = 0; i < n; ++i) {
		p[i].clear();
	}
	for(int i = 0; i < n; ++i) {
		if(!a[i].del) {
			int x = (a[i].x + delta) / r_max;
			int y = (a[i].y + delta) / r_max;
			pair<int, int> tmp = make_pair(x, y);
			if(Hash.find(tmp) == Hash.end()) {
				Hash[tmp] = ++tot;
			} 
			p[Hash[tmp]].push_back(i);
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r);		
		a[i].id = i;
	}
	sort(a, a + n);
	int cur_r = a[0].r;
	build(cur_r);
	for(int i = 0; i < n; ++i) {
		if(!a[i].del) {
			a[i].del = 1;
			ans[a[i].id] = a[i].id;
			if(a[i].r * 2 <= cur_r) {
				cur_r = a[i].r;
				build(cur_r);
			}
			int x = (a[i].x + delta) / cur_r;
			int y = (a[i].y + delta) / cur_r;
			for(int dx = -2; dx <= 2; ++dx) {
				for(int dy = -2; dy <= 2; ++dy) {
					int cur_x = x + dx, cur_y = y + dy;
					pair<int, int> tmp = make_pair(cur_x, cur_y);
					if(Hash.find(tmp) != Hash.end()) {
						int h = Hash[tmp];
						for(int j = 0; j < p[h].size(); ++j) {
							Circle &c = a[p[h][j]];
							if(!c.del) {
								if(check(c, a[i])) {
									c.del = 1;
									ans[c.id] = a[i].id;
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		printf("%d ", ans[i] + 1);
	}
	return 0;
}
