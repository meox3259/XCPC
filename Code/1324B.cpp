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

		vector<int> a;
		vector<vector<int> > p;
		a.resize(n);
		p.resize(n);

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			
			p[x - 1].emplace_back(i);
		}

		bool f = false;

		for(int i = 0; i < n; ++i) {
			if(p[i].size() > 2) {
				f = true;
			}

			if(p[i].size() == 2 && abs(p[i][0] - p[i][1]) > 1) {
				f = true;
			}
		}

		if(f) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}

	}

	return 0;
}
