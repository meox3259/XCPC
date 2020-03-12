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
		vector<int> a(n);
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		bool f = sum & 1;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < i; ++j) {
				int tmp = sum - a[j] + a[i];
				if(tmp & 1) {
					f = 1;
				}
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
