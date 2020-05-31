#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	long double s = 1.;

	vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if(*min_element(a.begin(), a.end()) == 0) {
		cout << 0 << '\n';
		exit(0);
	}

	long long ans = 1;
	bool ok = true;

	for(int i = 0; i < n; ++i) {
		s = s * a[i];
		ans = ans * a[i];
		if(s > 1e18) {
			ok = false;
		}
	}

	if(!ok) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}
