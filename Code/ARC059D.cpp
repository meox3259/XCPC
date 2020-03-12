#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char S[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> S + 1;
	int n = strlen(S + 1);
	// (sum[r] - sum[l - 1]) * 2 > r - l + 1
	// 2 * sum[r] - r - (2 * sum[l - 1] - (l - 1)) > 0
	for(int j = 0; j < 26; ++j) {
		multiset<pair<int, int> > s;
		vector<int> sum(n + 5, 0);
		for(int i = 1; i <= n; ++i) {
			sum[i] = sum[i - 1] + (S[i] - 'a' == j);
			auto it = s.lower_bound({2 * sum[i] - i, -n});
			if(it != s.begin()) {
				cout << s.begin() -> second + 1 << ' ' << i << '\n';
				return 0;
			}
			s.emplace(2 * sum[i - 1] - (i - 1), i - 1);
		}
	}
	cout << -1 << ' ' << -1 << '\n';
	return 0;
}
