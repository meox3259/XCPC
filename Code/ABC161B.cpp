#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a;
	a.resize(n);

	int sum = 0;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];

		sum += a[i];
	}

	int cnt = 0;

	for(int i = 0; i < n; ++i) {
		if(a[i] * 4 * m >= sum) {
			++cnt;
		}
	}

	if(cnt >= m) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}
