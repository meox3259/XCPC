#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		long long k;
		cin >> n >> k;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int last = *max_element(a.begin(), a.end());
		while(k--) {
			for(int i = 0; i < n; ++i) {
				a[i] = last - a[i];
			}
			int cur = *max_element(a.begin(), a.end());
			if(cur == last) {
				break;
			}
			last = cur;
		}

		if(k % 2 == 1) {
			int mx = *max_element(a.begin(), a.end());
			for(int i = 0; i < n; ++i) {
				a[i] = mx - a[i];
			}
		}

		for(int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
