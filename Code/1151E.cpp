#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long > a(n + 2);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[n + 1] = n + 1;
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] > a[i + 1]) {
			ans += (a[i] - a[i + 1]) * (n - a[i] + 1);
		}
		if(a[i] < a[i + 1]) {
			ans += a[i] * (a[i + 1] - a[i]);
		}
	}
	cout << ans;
	return 0;
}
