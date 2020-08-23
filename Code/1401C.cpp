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

		vector<int> b(n);
		for(int i = 0; i < n; ++i) {
			b[i] = a[i];
		}

		bool ok = true;
		sort(b.begin(), b.end());
		int mn = *min_element(b.begin(), b.end());
		for(int i = 0; i < n; ++i) {
			if(a[i] != b[i] && __gcd(a[i], mn) != mn) {
				ok = false;
			}	
		}

		if(ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
