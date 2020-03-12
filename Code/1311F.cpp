#include <bits/stdc++.h>
using namespace std;
class fenwick {
	public:
		vector<long long> t;
		void init(int n) {
			t.resize(n + 1);
		}
		void add(int p, long long v) {
			for(; p < (int)t.size(); p += p & -p) {
				t[p] += v;
			}
		}
		long long query(int p) {
			long long ret = 0;
			for(; p; p -= p & -p) {
				ret += t[p];
			}
			return ret;
		}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int, int> > p;
	p.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> p[i].first;
	}
	vector<int> vec;
	for(int i = 0; i < n; ++i) {
		cin >> p[i].second;
		vec.emplace_back(p[i].second);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	sort(p.begin(), p.end());
	fenwick A;
	fenwick B;
	A.init(n);
	B.init(n);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		auto [x, v] = p[i];
		int t = lower_bound(vec.begin(), vec.end(), v) - vec.begin() + 1;
		long long c = B.query(t);
		long long sum = A.query(t);
		ans += c * x - sum;
		B.add(t, 1);
		A.add(t, x);
	}
	cout << ans << '\n';
	return 0;
}
