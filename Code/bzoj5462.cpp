#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5, maxm = maxn * 28, inf = 1e9 + 5;
int n, k, q;
int ans[maxn];
namespace seg {
	struct Heap {
		priority_queue<int, vector<int>, greater<int> > elements, del;
		void push(int x) {
			elements.push(x);
		}
		void pop(int x) {
			del.push(x);
		}
		int top() {
			while(!elements.empty() && !del.empty() && elements.top() == del.top()) {
				elements.pop();
				del.pop();
			}
			return elements.size() ? elements.top() : inf;
		}
	} q[maxn];
	int root, Pool, tot;
	int mn[maxm], lc[maxm], rc[maxm];
	map<int, int> id;
	void update(int l, int r, int &x, int pos, int val, int f) {
		if(!x) {
			x = ++Pool;
		}
		if(l == r) {
			if(id.find(l) == id.end()) {
				id[l] = ++tot;
			}
			int cur = id[l]; 
			if(f == -1) {
				q[cur].pop(val);
			} else {
				q[cur].push(val);
			}
			mn[x] = q[cur].top();
			return;
		}
		int mid = l + r >> 1;
		if(pos <= mid) {
			update(l, mid, lc[x], pos, val, f);
		} else {
			update(mid + 1, r, rc[x], pos, val, f);
		}
		mn[x] = min(mn[lc[x]], mn[rc[x]]);
	}
	int query(int l, int r, int x, int a, int b) {
		if(l > b || r < a || !x) {
			return inf;
		} 
		if(l >= a && r <= b) {
			return mn[x];
		}
		int mid = l + r >> 1;
		return min(query(l, mid, lc[x], a, b), query(mid + 1, r, rc[x], a, b));
	}
} 
struct data {
	int pos, type, t, f;
	data() = default;
	data(int _pos, int _type, int _t, int _f) : pos(_pos), type(_type), t(_t), f(_f) {}
	bool friend operator < (const data &a, const data &b) {
		return a.t == b.t ? a.f < b.f : a.t < b.t;
	}
};
multiset<int> s[maxn];
int main() {
	using seg::root;
	scanf("%d%d%d", &n, &k, &q);
	vector<data> events;
	for(int i = 1; i <= n; ++i) {
		int x, t, a, b;
		scanf("%d%d%d%d", &x, &t, &a, &b);
		events.push_back(data(x, t, a, 0));
		events.push_back(data(x, t, b + 1, -1));
	}
	for(int i = 1; i <= q; ++i) {
		int l, y; scanf("%d%d", &l, &y);
		events.push_back(data(l, i, y, 1));
	}
	memset(seg::mn, 0x3f3f, sizeof(seg::mn));
	sort(events.begin(), events.end());
	for(int i = 1; i <= k; ++i) {
		s[i].insert(inf);
		s[i].insert(-inf);
		seg::update(1, inf, root, inf, -inf, 1);
	}
	for(int i = 0; i < events.size(); ++i) {
		data tmp = events[i];
		if(tmp.f != 1) {
			int type = tmp.type, pos = tmp.pos, f = tmp.f;
			multiset<int> :: iterator it;
			if(f == 0) {
				it = s[type].lower_bound(pos);
				int tmp_p = *it;
				seg::update(1, inf, root, tmp_p, *(--it), -1);
				seg::update(1, inf, root, tmp_p, pos, 1);
				tmp_p = *it;
				it = s[type].insert(pos);
				seg::update(1, inf, root, pos, tmp_p, 1);
			} else {
				it = s[type].find(pos);
				int prev = *(--it);
				++it;
				int next = *(++it);
				--it;
				seg::update(1, inf, root, pos, prev, -1);
				seg::update(1, inf, root, next, pos, -1);
				seg::update(1, inf, root, next, prev, 1);
				s[type].erase(it);
			}
		} else {
			int pos = tmp.pos, type = tmp.type;
			int l = -1, r = inf + 1, answer = -1;
			while(r - l > 1) {
				int mid = l + r >> 1;
				if(seg::query(1, inf, root, min(pos + mid + 1, inf), inf) >= pos - mid) {
					r = answer = mid; 
				} else {
					l = mid;
				}
			}
			ans[type] = answer;
		}
	}
	for(int i = 1; i <= q; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
