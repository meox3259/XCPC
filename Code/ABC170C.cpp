#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, n;
	cin >> x >> n;

	vector<bool> vis(105);
	for(int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		vis[v] = true;
	}

	for(int i = 0; i <= 100; ++i) {
		if(!vis[x - i]) {
			cout << x - i << '\n';
			exit(0);
		}
		if(!vis[x + i]) {
			cout << x + i << '\n';
			exit(0);
		}
	}

	return 0;
}
