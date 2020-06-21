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

	vector<int> ans(n);

	for(int j = 30; j >= 0; --j) {
		vector<int> b(n);
		for(int x = 0; x < 2; ++x) {
			for(int i = 0; i < n; ++i) {
				b[i] = x ^ (a[i] >> j & 1);
			}
			int s = 0;
			for(int i = 0; i < n; ++i) {
				s ^= b[i];
			}
			if(s == x) {
				break;
			}
		}
		for(int i = 0; i < n; ++i) {
			ans[i] += b[i] << j;
		}
	}

	for(int i : ans) {
		cout << i << ' ';
	}

	cout << '\n';

	return 0;
}
