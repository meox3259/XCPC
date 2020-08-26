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

		vector<int> one;

		int cnt = 0;
		s += '0';
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '1') {
				cnt += 1;
			} else if(cnt > 0) {
				one.emplace_back(cnt);
				cnt = 0;
			}
		}

		sort(one.begin(), one.end(), greater<int> ());

		int ans = 0;
		for(int i = 0; i < one.size(); i += 2) {
			ans += one[i];
		}

		cout << ans << '\n';
	}

	return 0;
}
