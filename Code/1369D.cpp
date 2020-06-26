#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	int m = 2000001;
	vector<long long> a(m);
	for(int i = 3; i < m; ++i) {
		a[i] = (a[i - 1] + a[i - 2] * 2 + (i % 3 == 0 ? 4 : 0)) % P;
	}

	while(T--) {
		int n;
		cin >> n;
		cout << a[n] << '\n';
	}

	return 0;
}
