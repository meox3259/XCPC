#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int p = max_element(a.begin(), a.end()) - a.begin();
	bool ok = true;
	for (int i = 0; i + 1 < p; ++i) {
		if (a[i] > a[i + 1]) {
			ok = false;
		}
	}

	for (int i = p; i + 1 < n; ++i) {
		if (a[i] < a[i + 1]) {
			ok = false;
		}
	}

	if (ok) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}

	return 0;
}
