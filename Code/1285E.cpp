#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int n;
int cnt[maxn];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		vector<pair<int, int> > v;
		for(int i = 1; i <= n; ++i) {
			int l, r; 
			scanf("%d%d", &l, &r);
			v.emplace_back(l, -i);
			v.emplace_back(r, i);
			cnt[i] = 0;
		}	
		sort(v.begin(), v.end());
		v.emplace_back(0, 0);
		set<int> s;
		int ans = 0;
		for(int i = 0; i < (int)v.size() - 1; ++i) {
			if(v[i].second < 0) {
				s.insert(-v[i].second);
			} else {
				s.erase(v[i].second);
			}
			if(s.empty()) {
				++ans;
			}
			if(s.size() == 1) {
				if(v[i].second > 0 && v[i + 1].second < 0 && v[i + 1].first > v[i].first) {
					++cnt[*s.begin()];
				} 
				if(v[i].second < 0 && v[i + 1].second > 0) {
					--cnt[*s.begin()];
				}	
			}
		}
		int t = -1;
		for(int i = 1; i <= n; ++i) {
			t = max(t, cnt[i]);
		}
		printf("%d\n", ans + t);
	}
	return 0;
}
