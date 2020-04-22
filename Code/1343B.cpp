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

		int m = n / 2;

		if(m & 1) {
			cout << "NO" << '\n';
			continue;
		}

		vector<int> ans;
		ans.resize(n);

		long long sum = 0;

		for(int i = 0; i < m; ++i) {
			ans[i] = i * 2 + 2;
			sum += i * 2 + 2;
		}

		for(int i = m; i < n - 1; ++i) {
			ans[i] = (i - m) * 2 + 1;
			sum -= (i - m) * 2 + 1;
		}
		
		ans[n - 1] = sum;

		cout << "YES" << '\n';

		for(int i : ans) {
			cout << i << ' '; 
		}

		cout << '\n';
	}

	return 0;
}
