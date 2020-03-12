#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, k;
int End[maxn];
int main() {
	scanf("%d%d", &n, &k);
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		v.emplace_back(l, -i);
		v.emplace_back(r, i);
		End[i] = r;
	}
	sort(v.begin(), v.end());
	set<pair<int, int> > s;
	vector<int> ans;
	for(int i = 0; i < v.size(); ++i) {
		if(v[i].second < 0) {
			s.insert(make_pair(End[-v[i].second], -v[i].second));
			while(s.size() > k) {
				ans.emplace_back((*s.rbegin()).second);
				s.erase(*s.rbegin());
			}
		} else {
			if(s.find(v[i]) != s.end()) {
				s.erase(v[i]);
			}
		}
	}
	printf("%d\n", ans.size());
	for(auto x : ans) {
		printf("%d ", x);
	}
	return 0;
}
