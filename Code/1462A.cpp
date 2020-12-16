#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		deque<int> q;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			q.push_back(x);
		}

		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				cout << q.back() << " \n"[i == n - 1];
				q.pop_back();
			} else {
				cout << q.front() << " \n"[i == n - 1];
				q.pop_front();
			}
		}
	}

	return 0;
}
