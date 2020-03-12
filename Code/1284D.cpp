#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int sa[maxn], ea[maxn], sb[maxn], eb[maxn];
struct node {
	int t, s, e;
	bool in;
	node() = default;
	node(int _t, int _s, int _e, bool _in) : t(_t), s(_s), e(_e), in(_in) {}
	bool friend operator < (const node &a, const node &b) {
		return a.t == b.t ? a.in < b.in : a.t < b.t;
	}
};
bool check() {
	vector<node> events;
	multiset<int> s, e;
	for(int i = 1; i <= n; ++i) {
		events.push_back(node(sa[i], sb[i], eb[i], 1));
		events.push_back(node(ea[i] + 1, sb[i], eb[i], 0));
	}
	sort(events.begin(), events.end());
	for(int i = 0; i < events.size(); ++i) {
		if(events[i].in) {
			if(!s.empty()) {
				int maxS = *s.rbegin();
				int minE = *e.begin();
				if(maxS > events[i].e || minE < events[i].s) {
					return false;
				}
			}
			s.insert(events[i].s);
			e.insert(events[i].e);
		} else {
			s.erase(s.find(events[i].s));
			e.erase(e.find(events[i].e));
		}
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &sa[i], &ea[i], &sb[i], &eb[i]);
	}
	bool f = check();
	swap(sa, sb);
	swap(ea, eb);
	f &= check();
	puts(f ? "YES" : "NO");
	return 0;
}
