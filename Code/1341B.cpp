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
	
		vector<int> a;
		a.resize(n);

		for(int &i : a) {
			cin >> i;
		}

		vector<int> peak;
		peak.resize(n);

		vector<int> pre;
		pre.resize(n);

		for(int i = 1; i + 1 < n; ++i) {
			peak[i] = (a[i - 1] < a[i] && a[i] > a[i + 1]);
		}

		for(int i = 0; i + 1 < n; ++i) {
			pre[i + 1] = pre[i] + peak[i + 1];
		}

		int mx = 0;
		int l = 0;

		for(int i = 0; i + k - 1 < n; ++i) {
			int s = pre[i + k - 1] - (i > 0 ? pre[i - 1] : 0) - peak[i] - peak[i + k - 1];

			if(s > mx) {
				mx = s;
				l = i;
			}
		}

		cout << mx + 1 << ' ' << l + 1 << '\n';
	}

	return 0;
}
