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

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<int> l(n);
		for(int i = 0; i < n; ++i) {
			cin >> l[i];
		}

		vector<int> v;
		for(int i = 0; i < n; ++i) {
			if(!l[i]) {
				v.emplace_back(a[i]);
			}
		}

		sort(v.begin(), v.end());

		for(int i = 0; i < n; ++i) {
			if(!l[i]) {
				a[i] = v.back();
				v.pop_back();
			}
		}

		long long sum = 0;
		int ans = -1;
		for(int i = 0; i < n; ++i) {
			sum += a[i];
			if(sum < 0) {
				ans = i;
			}
		}

		for(int i = 0; i < n; ++i) {
			cout << a[i] << " \n"[i == n - 1];
		}
	}

	return 0;
}
