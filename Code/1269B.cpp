#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	vector<int> b;
	b.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(b.begin(), b.end());

	int ans = m;

	for(int i = 0; i < n; ++i) {
		int d = (b[0] + m - a[i]) % m;

		bool ok = true;

		for(int j = 0; j < n; ++j) {
			if((a[(i + j) % n] + d) % m != b[j]) {
				ok = false;
				break;
			}
		}

		if(ok) {
			ans = min(ans, d);
		}
	}
	
	cout << ans << '\n';

	return 0;
}
