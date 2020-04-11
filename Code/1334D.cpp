#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		long long l, r;
		cin >> n >> l >> r;

		long long sum = 0;

		int a = -1;
		int b = -1;
		long long sa = 0;
		long long sb = 0;

		for(int i = n - 1; i >= 1; --i) {
			if(sum < l && l <= sum + 2 * i) {
				a = i;
				sa = sum;
				break;
			}

			sum += 2 * i;
		}

		sum = 0;

		for(int i = n - 1; i >= 1; --i) {
			if(sum < r && r <= sum + 2 * i) {
				b = i;
				sb = sum;
				break;
			}

			sum += 2 * i;
		}

		long long pa = l - sa;
		long long pb = r - sb;

		vector<int> ans;

		int L = n - a;
		int R = n - b;

		if(b == -1) {
			R = n - 1;
		}

		if(a == -1) {
			L = n - 1;
		}

		for(int i = L; i <= R; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				ans.emplace_back(i);
				ans.emplace_back(j);
			}
		}

		if(b == -1) {
			ans.emplace_back(1);
		}

		if(a == -1 && b == -1) {
			cout << 1 << '\n';

			continue;
		}

		for(int i = l - sa - 1; i <= r - sa - 1; ++i) {
			cout << ans[i] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
