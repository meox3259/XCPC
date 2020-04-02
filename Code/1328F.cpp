#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<long long> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	vector<long long> pre;
	pre.resize(n);

	pre[0] = a[0];

	for(int i = 1; i < n; ++i) {
		pre[i] = pre[i - 1] + a[i];
	}

	vector<long long> suf;
	suf.resize(n);

	suf[n - 1] = a[n - 1];

	for(int i = n - 2; i >= 0; --i) {
		suf[i] = suf[i + 1] + a[i];
	}

	long long ans = inf;

	for(int i = 0, j = -1; i < n; i = j + 1) {
		while(j + 1 < n && a[j + 1] == a[i]) {
			++j;
		}

		long long x = 0;

		int need = k - (j - i + 1);

		if(need <= 0) {
			ans = 0;
			break;
		}

		if(i > 0) {
			x += 1LL * i * a[i - 1] - pre[i - 1] + 1LL * min(need, i) * (a[i] - a[i - 1]) + 1LL * (i - min(i, need)) * (a[i] - a[i - 1] - 1);
			need -= i;
		}

		if(need > 0) {
			x += suf[j + 1] - 1LL * (n - j - 1) * a[j + 1];
			x += 1LL * need * (a[j + 1] - a[j]) + 1LL * (n - j - 1 - need) * (a[j + 1] - a[j] - 1);
		}

		ans = min(ans, x);

		long long y = 0;

		need = k - (j - i + 1);

		if(j + 1 < n) {
			y += suf[j + 1] - 1LL * (n - j - 1) * a[j + 1] + 1LL * min(need, n - j - 1) * (a[j + 1] - a[j]) + 1LL * (n - j - 1 - min(need, n - j - 1)) * (a[j + 1] - a[j] - 1);
			need -= n - j - 1;
		}

		if(need > 0) {
			y += 1LL * i * a[i - 1] - pre[i - 1];
			y += 1LL * need * (a[i] - a[i - 1]) + (i - need) * (a[i] - a[i - 1] - 1);
		}

		ans = min(ans, y);
	}

	cout << ans << '\n';

	return 0;
}
