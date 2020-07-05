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

	long long ans = 0;
	sort(a.begin(), a.end());

	ans += a.back();
	int cur = n - 2;
	int f = 0;
	for(int i = n - 3; i >= 0; --i) {
		ans += a[cur];
		if(f == 1) {
			cur -= 1;
		}
		f ^= 1;
	}

	cout << ans << '\n';

	return 0;
}
