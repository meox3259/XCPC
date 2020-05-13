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

		deque<int> q;

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			q.emplace_back(x);
		}

		int ans = 0;
		int sa = 0;
		int sb = 0;
		int pa = 0;
		int pb = 0;
		int cur = 0;

		while(!q.empty()) {
			if(cur == 0) {
				int sum = 0;
				while(!q.empty() && sum <= pb) {
					sum += q.front();
					q.pop_front();
				}
				++ans;
				sa += sum;
				pa = sum;
			} else {
				int sum = 0;
				while(!q.empty() && sum <= pa) {
					sum += q.back();
					q.pop_back();
				}
				++ans;
				sb += sum;
				pb = sum;
			}

			cur ^= 1;
		}

		cout << ans << ' ' << sa << ' ' << sb << '\n';
	}

	return 0;
}
