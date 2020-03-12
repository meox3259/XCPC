#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	sum = -a[0] + a[n - 1];
	for(int i = 1; i < n - 1; ++i) {
		sum += abs(a[i]);
	}
	int x = a[0], y = a[n - 1];
	cout << sum << '\n';
	for(int i = 1; i < n - 1; ++i) {
		if(a[i] > 0) {
			cout << x << ' ' << a[i] << '\n';
			x -= a[i];
		} else {
			cout << y << ' ' << a[i] << '\n';
			y -= a[i];
		}
	}
	cout << y << ' ' << x << '\n';
	return 0;
}
