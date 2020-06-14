#include <bits/stdc++.h>

using namespace std;

const int m = 200000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, Q;
	cin >> n >> Q;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	vector<multiset<int> > s(m);

	for(int i = 0; i < n; ++i) {
		b[i] -= 1;
		s[b[i]].emplace(a[i]);
	}

	multiset<int> q;

	for(int i = 0; i < m; ++i) {
		if(!s[i].empty()) {
			q.emplace(*s[i].rbegin());
		}
	}

	for(int _ = 0; _ < Q; ++_) {
		int c, d;
		cin >> c >> d;
		--c; --d;
		q.erase(q.find(*s[b[c]].rbegin()));
		s[b[c]].erase(s[b[c]].find(a[c]));
		if(!s[b[c]].empty()) {
			q.emplace(*s[b[c]].rbegin());
		}
		b[c] = d;
		if(!s[b[c]].empty()) {
			q.erase(q.find(*s[b[c]].rbegin()));
		}
		s[b[c]].emplace(a[c]);
		q.emplace(*s[b[c]].rbegin());
		cout << *q.begin() << '\n';
	}

	return 0;
}
