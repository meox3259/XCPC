#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, a, b;
	cin >> k >> a >> b;

	for(int i = a; i <= b; ++i) {
		if(i % k == 0) {
			cout << "OK" << '\n';
			exit(0);
		}
	}

	cout << "NG" << '\n';

	return 0;
}
