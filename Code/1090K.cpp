#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<int, string>, vector<int> > mp;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		string s, t; cin >> s >> t;
		int S = 0;
		for(auto c : t) S |= 1 << (c - 'a');
		while(s.size() && (S & (1 << (s.back() - 'a'))))
			s.pop_back();
		mp[make_pair(S, s)].push_back(i);
	}
	printf("%d\n", mp.size());
	for(auto x : mp) {
		printf("%d ", x.second.size());
		for(auto t : x.second) printf("%d ", t);
		puts("");
	}
	return 0;
}
