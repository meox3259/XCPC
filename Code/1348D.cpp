#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long n;
		cin >> n;

		long long num = 1;
		n -= 1;
		vector<long long> ans;
		while(n) {
			if(num * 2 >= n) {
				ans.emplace_back(n - num);
				break;
			}
			long long nxt = min(num * 2, n / 2);
			n -= nxt;
			ans.emplace_back(nxt - num);
			num = nxt;
		}
		cout << ans.size() << '\n';
		for(long long i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}
