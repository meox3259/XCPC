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
		vector<int> sum;
		sum.resize(n + 1);
		for(int i = 0; i < n; ++i) {
			sum[i + 1] = sum[i] + (s[i] - '0');
		}
		long long ans = 0;
		for(int i = 0; i < n; ++i) {
			int b = 0;
			int c = 0;
			for(int j = 0; j < 31 && i - j >= 0; ++j) {
				b += (s[i - j] - '0') * (1 << j);
				c += (s[i - j] - '0');
				if(s[i - j] == '1' && i + 1 >= b && sum[i + 1] - sum[i + 1 - b] == c) {
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
