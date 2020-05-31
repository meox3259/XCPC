#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if(n % 2 == 1) {
		int l = a[(n + 1) / 2 - 1];
		int r = b[(n + 1) / 2 - 1];
		cout << r - l + 1 << '\n';
	} else {
		int l = a[n / 2 - 1] + a[n / 2];
		int r = b[n / 2 - 1] + b[n / 2];
		cout << r - l + 1 << '\n';
	}

	return 0;
}
