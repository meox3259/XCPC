#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> pri;	
	vector<bool> vis(N);
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) {
			pri.emplace_back(i);
		}
		for (int j = i; j < N; j += i) {
			vis[j] = true;
		}
	}

	int T;
	cin >> T;

	while (T --) {
		int d;
		cin >> d;

		long long ans = 1;
		int cur = 1;
		for (int i = 0; i < 2; ++i) {
			int v = *lower_bound(pri.begin(), pri.end(), cur + d);
			ans = ans * v;
			cur = v;
		}

		cout << ans << '\n';
	}

	return 0;
}
