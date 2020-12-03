#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = a[n - 1] - a[0];
	priority_queue<int> q;
	for (int i = 0; i + 1 < n; ++i) {
		q.emplace(a[i + 1] - a[i]);
	}

	for (int i = 0; i < k - 1; ++i) {
		ans -= q.top();
		q.pop();
	}

	cout << ans << '\n';

	return 0;
}
