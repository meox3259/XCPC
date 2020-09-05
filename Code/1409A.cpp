#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int a, b;
		cin >> a >> b;
		if(a > b) {
			swap(a, b);
		}
		int d = b - a;
		cout << (d + 9) / 10 << '\n';
	}

	return 0;
}
