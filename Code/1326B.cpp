#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> b;
	b.resize(n);

	for(int &i : b) {
		cin >> i;
	}

	int a = b[0];

	cout << a;

	for(int i = 1; i < n; ++i) {
		cout << ' ' << a + b[i];

		a = max(a, a + b[i]);
	}

	cout << '\n';

	return 0;
}
