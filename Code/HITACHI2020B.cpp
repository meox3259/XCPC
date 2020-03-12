#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, m;
	cin >> A >> B >> m;
	vector<int> a;
	vector<int> b;
	a.resize(A);
	b.resize(B);
	for(int i = 0; i < A; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < B; ++i) {
		cin >> b[i];
	}
	int ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
	for(int i = 0; i < m; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		--x;
		--y;
		ans = min(ans, a[x] + b[y] - c);
	}
	cout << ans << '\n';
	return 0;
}
