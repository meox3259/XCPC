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
		a.resize(n);

		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<int> pri = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

		vector<int> c;
		c.resize(n);

		set<int> s;

		vector<int> id;

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 11; ++j) {
				if(a[i] % pri[j] == 0) {
					c[i] = j + 1;
					s.emplace(j + 1);
					id.emplace_back(j + 1);
					break;
				}
			}
		}
		
		sort(id.begin(), id.end());
		id.erase(unique(id.begin(), id.end()), id.end());

		cout << s.size() << '\n';

		for(auto x : c) {
			cout << lower_bound(id.begin(), id.end(), x) - id.begin() + 1 << ' ';
		}

		cout << '\n';		
	}

	return 0;
}
