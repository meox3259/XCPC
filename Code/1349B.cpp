#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;

		bool ok = false;

		vector<int> a(n);
		set<int> s;

		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			if(a[i] == k) {
				ok = true;
			}
			if(a[i] >= k) {
				s.emplace(i);
			}
		}

		if(!ok) {
			cout << "no" << '\n';
			continue;
		}

		if(n == 1) {
			cout << "yes" << '\n';
			continue;
		}

		bool ok1 = false;

		for(int i = 0; i < n; ++i) {
			if(a[i] >= k) {
				auto it = s.upper_bound(i);
				if(it != s.end() && *it - i <= 2) {
					ok1 = true;
				}
			}
		}
		
		if(!ok1) {
			cout << "no" << '\n';
		} else {
			cout << "yes" << '\n';
		}
	}


	return 0;
}
