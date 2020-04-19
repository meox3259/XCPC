#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		n -= x;
	}

	if(n < 0) {
		cout << -1 << '\n';
	} else {
		cout << n << '\n';
	}

	return 0;
}
