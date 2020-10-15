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
		
		string s;
		cin >> s;

		reverse(s.begin(), s.end());
		int ans = 0;

		vector<int> b;

		while(!s.empty()) {
			auto cur = s.back();
			int cnt = 0;
			while(!s.empty() && s.back() == cur) {
				cnt += 1;
				s.pop_back();
			}
			b.emplace_back(cnt);
		}

		int m = b.size();
		reverse(b.begin(), b.end());

		for(int j = m - 1, i = m - 1; j >= 0; --j) {
			i = min(j, i);
			while(i >= 0 && b[i] <= 1) {
				--i;
			}
			if(b[j] > 1) {
				ans += 1;
			} else {
				if(i >= 0 && i < j && b[i] > 1) {
					b[i] -= 1;
					ans += 1;
				} else {
					j -= 1;
					ans += 1;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
