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

		vector<int> x(n);
		for(int i = 0; i < n; ++i) {
			cin >> x[i];
		}

		vector<int> y(n);
		for(int i = 0; i < n; ++i) {
			cin >> y[i];
		}

		sort(x.begin(), x.end());

		vector<int> pre(n + 1);
		queue<int> q;
		for(int i = 0; i < n; ++i) {
			while(!q.empty() && x[i] - q.front() > k) {
				q.pop();
			}	
			q.emplace(x[i]);
			pre[i + 1] = max((int)q.size(), pre[i]);
		}

		while(!q.empty()) {
			q.pop();
		}

		vector<int> suf(n + 2);
		for(int i = n - 1; i >= 0; --i) {
			while(!q.empty() && q.front() - x[i] > k) {
				q.pop();
			}
			q.emplace(x[i]);
			suf[i + 1] = max(suf[i + 2], (int)q.size());
		}

		int ans = 0;
		for(int i = 0; i <= n; ++i) {
			ans = max(ans, pre[i] + suf[i + 1]);
		}

		cout << ans << '\n';
	}

	return 0;
}
