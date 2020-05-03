#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> h(n);
	for(int &i : h) {
		cin >> i;
	}

	vector<int> ban(n);

	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if(h[a] >= h[b]) {
			ban[b] = 1;
		}
		if(h[a] <= h[b]) {
			ban[a] = 1;
		}
	}

	int ans = 0;
	for(int i : ban) {
		ans += (i == 0);
	}

	cout << ans << '\n';

	return 0;
}
