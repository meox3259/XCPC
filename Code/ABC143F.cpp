#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> cnt;
	cnt.resize(n);

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		++cnt[x - 1];
	}

	sort(cnt.begin(), cnt.end());

	vector<int> pre;
	pre.resize(n + 1);

	for(int i = 0; i < n; ++i) {
		pre[i + 1] = pre[i] + cnt[i];
	}

	int ans = n;
	int i = n;

	for(int k = 1; k <= n; ++k) {
		while(1) {
			bool ok = [&] (int x) {
				while(i >= 1 && cnt[i - 1] >= x) {
					--i;
				}

				int sum = pre[i] + (n - i) * x;

				return (sum >= k * x);
			} (ans);

			if(ok) {
				break;
			}

			--ans;
		}

		cout << ans << '\n';
	}

	return 0;

}
