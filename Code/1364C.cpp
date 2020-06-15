#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(n, -1);
	for(int i = 1; i < n; ++i) {
		if(a[i] != a[i - 1]) {
			b[i] = a[i - 1];
		}
	}

	vector<bool> vis(1000005);

	for(int i : a) {
		vis[i] = true;
	}

	int cur = 0;
	for(int i = 0; i < n; ++i) {
		if(b[i] == -1) {
			while(vis[cur]) {
				cur += 1;
			}
			b[i] = cur++;
		}
	}

	for(int i : b) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
