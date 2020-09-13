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

		int zero = 0;
		int one = 0;
		for(int i : a) {
			if(i == 0) {
				zero += 1;
			} else {
				one += 1;
			}
		}

		if(one <= zero) {
			cout << zero << '\n';
			for(int i = 0; i < zero; ++i) {
				cout << 0 << " \n"[i == zero - 1];
			}
		} else {
			vector<int> ans;
			for(int i = 0; i < one; ++i) {
				ans.emplace_back(1);
				if(ans.size() % 2 == 0 && ans.size() >= n / 2) {
					break;
				}
			}
			cout << ans.size() << '\n';
			int m = ans.size();
			for(int i = 0; i < m; ++i) {
				cout << 1 << " \n"[i == m - 1];
			}
		}
	}

	return 0;
}
