#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if(n % 2 == 1) {
		cout << "YES" << '\n';
		vector<tuple<int, int, int> > opt;
		for(int i = 0; i + 2 < n; i += 2) {
			opt.emplace_back(i, i + 1, i + 2);
		}
		for(int i = 0; i + 2 < n; i += 2) {
			opt.emplace_back(i, i + 1, n - 1);
		}	
		cout << opt.size() << '\n';
		for(auto [x, y, z] : opt) {
			cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
		}
	} else {
		int sum = 0;
		for(int i : a) {
			sum ^= i;
		}
		if(sum != 0) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			vector<tuple<int, int, int> > opt;
			for(int i = 0; i + 2 < n; i += 2) {
				opt.emplace_back(i, i + 1, i + 2);
			}
			for(int i = 0; i + 2 < n; i += 2) {
				opt.emplace_back(i, i + 1, n - 1);
			}	
			cout << opt.size() << '\n';
			for(auto [x, y, z] : opt) {
				cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
			}
		}
	}

	return 0;
}
