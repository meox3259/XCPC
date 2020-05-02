#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i * 2 <= m; ++i) {
		cout << i << ' ' << m - i + 1 << '\n';
	}

	for(int i = 1; i * 2 <= m + 1; ++i) {
		cout << m + i << ' ' << m * 2 - i + 2 << '\n';
	}

	return 0;
}
