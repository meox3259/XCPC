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

		int l = -1;
		int r = n;

		for(int i = 0; i < n; ++i) {
			if(a[i] < i) {
				break;
			}

			l = i;
		}

		for(int i = n - 1; i >= 0; --i) {
			if(a[i] < n - 1 - i) {
				break;
			}

			r = i;
		}

		if(r <= l) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}
