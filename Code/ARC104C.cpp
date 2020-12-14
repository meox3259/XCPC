#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	vector<int> cnt(n + n + 1);
	for (int i : a) {
		if (i != -1) {
			cnt[i] ++;
		}
	}
	for (int i : b) {
		if (i != -1) {
			cnt[i] ++;
		}
	}

	if (*max_element(cnt.begin(), cnt.end()) >= 2) {
		cout << "No" << '\n';
		exit(0);
	}

	vector<int> pos(n + n + 1, -1);
	for (int i = 0; i < n; ++i) {
		if (a[i] != -1) {
			pos[a[i]] = i;
		}
		if (b[i] != -1) {
			pos[b[i]] = i;
		}
	}

	vector<int> dp(n + n + 1);
	dp[0] = 1;
	for (int i = 0; i < n + n; ++i) {
		for (int j = 1; i + j + j <= n + n; ++j) {
			bool ok = true;
			for (int d = 1; d <= j; ++d) {
				if (pos[i + d] != -1 && pos[i + j + d] != -1 && pos[i + d] != pos[i + j + d]) {
					ok = false;
				}
				if (pos[i + d] != -1 && b[pos[i + d]] == i + d) {
					ok = false;
				}
				if (pos[i + j + d] != -1 && a[pos[i + j + d]] == i + j + d) {
					ok = false;
				}
			}
			if (ok) {
				dp[i + j + j] |= dp[i];	
			}
		}	
	}

	if (dp[n + n]) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}
