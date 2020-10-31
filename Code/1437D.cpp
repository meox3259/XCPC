#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int ans = 1;
		int cur = 1;
		int nxt = 0;
		for(int i = 1; i + 1 < n; ++i) {
			nxt += 1;
			if(a[i + 1] < a[i]) {
				cur -= 1;
			}
			if(cur == 0) {
				ans += 1;
				cur = nxt;
				nxt = 0;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
