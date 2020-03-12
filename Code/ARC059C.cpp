#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1e9;
	for(int i = -100; i <= 100; ++i) {
		int tmp = 0;
		for(int j = 0; j < n; ++j) {
			tmp += (a[j] - i) * (a[j] - i);
		}
		ans = min(ans, tmp);
	}
	cout << ans << '\n';
	return 0;
}
