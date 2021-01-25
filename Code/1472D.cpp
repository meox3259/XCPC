#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int>::max();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		priority_queue<int> odd;
		priority_queue<int> even;
		for (int i : a) {
			if (i % 2 == 0) {
				even.emplace(i);
			} else {
				odd.emplace(i);
			}
		}

		odd.emplace(-inf);
		even.emplace(-inf);

		long long sa = 0;
		long long sb = 0;
		for (int i = 0; i < n; ++i) {
			if (even.top() > odd.top()) {
				if (i % 2 == 0) {
					sa += even.top();
				}
				even.pop();
			} else {
				if (i % 2 == 1) {
					sb += odd.top();
				}
				odd.pop();
			}
		}

		if (sa > sb) {
			cout << "Alice" << '\n';
		} else if (sa == sb) {
			cout << "Tie" << '\n';
		} else {
			cout << "Bob" << '\n';
		}
	}

	return 0;
}
