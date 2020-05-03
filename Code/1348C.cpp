#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> cnt(26);
		for(char c : s) {
			++cnt[c - 'a'];
		}
		string ans = "";
		bool ok = false;
		int tot = n;
		for(int i = 0; i < 26; ++i) {
			if(cnt[i] > 0) {
				if(cnt[i] < k) {
					ok = true;
					sort(s.begin(), s.end());
					cout << s[k - 1] << '\n';
				} else {
					cnt[i] -= k;
					tot -= k;
					ans += (char)('a' + i);
				}
				break;
			}
		}
		if(ok) {
			continue;
		}
		for(int i = 0; i < 26; ++i) {
			if(cnt[i] > 0) {
				if(cnt[i] == tot) {
					ans += string((tot + k - 1) / k, (char)('a' + i));
					break;
				} else {
					for(int j = i; j < 26; ++j) {
						ans += string(cnt[j], (char)('a' + j));
					}
					break;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
