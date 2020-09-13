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

		vector<int> pos;
		vector<int> neg;
		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if(x > 0) {
				pos.emplace_back(x);
			} else {
				neg.emplace_back(x);
			}
		}

		long long ans = -9000000000000000000;

		for(int i = 0; i <= 5; ++i) {
			for(int j = 0; j <= 5; ++j) {
				if(i + j == 5 && pos.size() >= i && neg.size() >= j) {
					if(j % 2 == 1) {
						sort(neg.begin(), neg.end(), greater<int> ());
						sort(pos.begin(), pos.end());
					} else {
						sort(neg.begin(), neg.end());
						sort(pos.begin(), pos.end(), greater<int> ());
					}
					long long tmp = 1;
					for(int k = 0; k < i; ++k) {
						tmp = tmp * pos[k];
					}
					for(int k = 0; k < j; ++k) {
						tmp = tmp * neg[k];
					}
					ans = max(ans, tmp);
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
