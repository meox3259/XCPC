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
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		for(int i = 0; i < n; ++i) {
			if(a[i] < 0) {
				a[i] = -a[i];
			}
			if(i % 2 == 0) {
				cout << a[i] << ' ';
			} else {
				cout << -a[i] << ' ';
			}
		}

		cout << '\n';
	}
	
	return 0;
}
