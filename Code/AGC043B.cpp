#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		a[i] = s[i] - '0' - 1;
	}

	bool one = false;

	for(int i = 0; i < n; ++i) {
		if(a[i] == 1) {
			one = true;
		}
	}

	if(one) {
		for(int i = 0; i < n; ++i) {
			a[i] %= 2;
		}
	}

	int ans = 0;

	for(int i = 0; i < n; ++i) {
		if(((n - 1) & i) == i) {
			ans ^= a[i];
		}
	}

	cout << ans << '\n';

	return 0;
}
