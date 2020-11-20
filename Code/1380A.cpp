#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<int> p(n);
		for(int i = 0; i < n; ++i) {
			cin >> p[i];
		}

		for(int i = 0; i < n; ++i) {
			p[i] -= 1;
		}

		deque<int> q;
		for(int i : p) {
			q.push_back(i);
		}

		vector<int> id(n);
		for(int i = 0; i < n; ++i) {
			id[p[i]] = i;
		}

		bool ok = false;
		for(int v = n - 1; v >= 2; --v) {
			if(v != q.front() && v != q.back()) {
				cout << "YES" << '\n';
				cout << id[q.front()] + 1 << ' ' << id[v] + 1 << ' ' << id[q.back()] + 1 << '\n';
				ok = true;
				break;
			} else {
				if(v == q.front()) {
					q.pop_front();
				} else {
					q.pop_back();
				}
			}
		}

		if(!ok) {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
