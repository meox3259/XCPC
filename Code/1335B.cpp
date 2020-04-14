#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, a, b;
		cin >> n >> a >> b;

		for(int i = 0; i < n; ++i) {
			if(i % a + 1 <= b) {
				cout << (char)('a' + i % a);
			} else {
				cout << 'a';
			}
		}

		cout << '\n';
	}

	return 0;
}
