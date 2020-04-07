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

		vector<int> p;
		p.resize(n);

		for(int i = 0; i < n; ++i) {
			int v;
			cin >> v;

			p[v - 1] = i;
		}

		int l = n;
		int r = -1;

		for(int i = 0; i < n; ++i) {
			l = min(l, p[i]);
			r = max(r, p[i]);
		
			cout << (r - l == i);
		}

		cout << '\n';
	}

	return 0;
}
