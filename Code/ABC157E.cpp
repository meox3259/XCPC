#include <bits/stdc++.h>
using namespace std;
class fenwick {
	vector<int> t;
	public:
		fenwick() {
			t.resize(500001);
		}
		void add(int p, int v) {
			for(; p < (int)t.size(); p += p & -p) {
				t[p] += v;
			}
		}
		int query(int p) {
			int ret = 0;
			if(p < 0) {
				return 0;
			}
			for(; p; p -= p & -p) {
				ret += t[p];
			}
			return ret;
		}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q;
	string s;
	cin >> n >> s >> q;
	vector<fenwick> A;
	A.resize(26);
	for(int i = 0; i < n; ++i) {
		A[s[i] - 'a'].add(i + 1, 1);
	}
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int i;
			char c;
			cin >> i >> c;
			A[s[i - 1] - 'a'].add(i, -1);
			A[c - 'a'].add(i, 1);
			s[i - 1] = c;
		}
		if(type == 2) {
			int l, r;
			cin >> l >> r;
			int ans = 0;
			for(int i = 0; i < 26; ++i) {
				if(A[i].query(r) - A[i].query(l - 1) > 0) {
					++ans;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
