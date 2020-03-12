#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
long long T;
long long a, b;
int type[maxn];
vector<int> v[maxn];
int main() {
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d%lld%lld%lld", &n, &T, &a, &b);
		vector<long long> vec;
		long long sa = 0, sb = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &type[i]);
			if(type[i] == 0) {
				++sa;
			} else {
				++sb;
			}
		}
		int id = 0;
		map<int, int> mp;
		for(int i = 1; i <= n; ++i) {
			int t;
			scanf("%d", &t);
			if(mp.find(t) == mp.end()) {
				mp[t] = ++id;
			}
			v[mp[t]].push_back(type[i]);
			vec.push_back(t);
		}
		vec.push_back(-T);
		vec.push_back(T + 1);
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		int ta = 0, tb = 0, ans = 0;
		for(int i = 0; i < (int)vec.size() - 1; ++i) {
			int t = vec[i];
			long long tim = vec[i + 1] - 1;
			t = mp[t];
			for(auto x : v[t]) {
				if(x == 0) {
					++ta;
				} else {
					++tb;
				}
			}
			if(1LL * ta * a + 1LL * tb * b <= tim) {
				tim -= 1LL * ta * a + 1LL * tb * b;
				int aa = min(tim / a, sa - ta);
				int bb = min((tim - 1LL * a * aa) / b, sb - tb);
				bb = max(bb, 0);
				ans = max(ans, aa + bb + ta + tb);
			}
		}
		for(int i = 1; i <= id; ++i) {
			v[i].clear();
		}
		printf("%d\n", ans);
	}
	return 0;
}
