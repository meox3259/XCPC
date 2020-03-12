#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, m, x;
		int sum = 0;
		cin >> n >> m;
		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			sum += x;
		}
		cout << min(m, sum) << '\n';
	}
	return 0;
}
