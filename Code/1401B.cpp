#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		vector<int> a(3);
		vector<int> b(3);
		for(int i = 0; i < 3; ++i) {
			cin >> a[i];
		}
		for(int i = 0; i < 3; ++i) {
			cin >> b[i];
		}
		long long ans = 0;
		int d;
		d = min(a[2], b[1]);
		ans += d * 2;
		a[2] -= d;
		b[1] -= d;
		d = min(a[2], b[2]);
		a[2] -= d;
		b[2] -= d;
		d = min(a[0], b[2]);
		a[0] -= d;
		b[2] -= d;
		d = min(a[0], b[1]);
		a[0] -= d;
		b[1] -= d;
		d = min(a[1], b[1]);
		a[1] -= d;
		b[1] -= d;
		d = min(a[1], b[0]);
		a[1] -= d;
		b[0] -= d;
		ans -= min(a[1], b[2]) * 2;
		cout << ans << '\n';
	}

	return 0;
}
