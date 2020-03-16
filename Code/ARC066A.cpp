#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	long long ans = 1;

	int cnt = 0;

	for(int i = n - 1; i > 0; i -= 2) {
		while(!a.empty() && a.back() >= i) {
			++cnt;
			a.pop_back();
		}

		ans = ans * cnt * (cnt - 1) % P;

		cnt -= 2;
	}
	
	cout << ans << '\n';

	return 0;
}
