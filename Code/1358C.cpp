#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		long long d = y2 - y1 + 1;
		long long c = x2 - x1;
		cout << d * c - c + 1 << '\n';
	}
	
	return 0;
}
