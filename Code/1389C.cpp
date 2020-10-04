#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		string s;
		cin >> s;

		int n = s.size();

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			a[i] = s[i] - '0';
		}

		vector<int> cnt(10);
		for(int i : a) {
			cnt[i] += 1;
		}

		int ans = n;
		ans = min(ans, n - *max_element(cnt.begin(), cnt.end()));

		for(int x = 0; x < 10; ++x) {
			for(int y = 0; y < 10; ++y) {
				int cur = x;
				int last = y;
				int tot = 0;
				for(int i = 0; i < n; ++i) {
					if(a[i] == cur) {
						tot += 1;
						swap(cur, last);
					} 
				}
				if(cur == y) {
					tot -= 1;
				}
				ans = min(ans, n - tot);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
