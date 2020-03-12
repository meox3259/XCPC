#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> a;
		a.resize(2 * n);
		for(int i = 0; i < 2 * n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		cout << a[n] - a[n - 1] << '\n';
	}
	return 0;
}
