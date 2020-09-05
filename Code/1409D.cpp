#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long n;
		int s;
		cin >> n >> s;

		vector<int> st;
		while(n) {
			st.emplace_back(n % 10);
			n /= 10;
		}

		int sum = 0;
		long long ans = 1000000000000000000;

		for(int i : st) {
			sum += i;
		}

		if(sum <= s) {
			cout << 0 << '\n';
		} else {
			long long ten = 1;
			long long pre = 0;
			for(int i = 0; i < st.size(); ++i) {
				pre = pre + st[i] * ten;
				ten = ten * 10;
				sum -= st[i];
				if(sum + 1 <= s) {
					ans = min(ans, ten - pre);
				}
			}

			cout << ans << '\n';
		}
	}

	return 0;
}
