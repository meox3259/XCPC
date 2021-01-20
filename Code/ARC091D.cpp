#include <bits/stdc++.h>

using namespace std;

map<int, int> sg;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> k(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> k[i];
	}

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		function<int(int, int)> sg = [&] (int A, int K) {
			if (A % K == 0) {
				return A / K;
			}
			if (A % K >= A / K + 1) {
				return sg(A - (A % K) / (A / K + 1) * (A / K + 1), K);
			} else {
				return sg(A - (A / K + 1), K);
			}
		};

		sum ^= sg(a[i], k[i]);
	}	

	if (sum == 0) {
		cout << "Aoki" << '\n';
	} else {
		cout << "Takahashi" << '\n';
	}

	return 0;
}
