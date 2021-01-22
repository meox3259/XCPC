#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long> pre(n + 1);
	for (int i = 0; i < n; ++i) {
		pre[i + 1] = pre[i] + a[i];
	}

	long long ans = inf;
	for (int i = 2; i < n - 1; ++i) {
		int l = 1;
		int r = i;
		while (r - l > 2) {
			int lmid = (l + l + r) / 3;
			int rmid = (l + r + r) / 3;
			long long lv = abs(pre[i] - pre[lmid] - pre[lmid]);
			long long rv = abs(pre[i] - pre[rmid] - pre[rmid]);
			if (lv > rv) {
				l = lmid;
			} else {
				r = rmid;
			}
		}

		int p1 = l;
		long long v1 = abs(pre[i] - pre[p1] - pre[p1]);
		for (int j = l; j <= r; ++j) {
			long long cur = abs(pre[i] - pre[j] - pre[j]);
			if (cur < v1) {
				p1 = j;
				v1 = cur;
			}
		}

		l = i + 1;
		r = n;
		while (r - l > 2) {
			int lmid = (l + l + r) / 3;
			int rmid = (l + r + r) / 3;
			long long lv = abs((pre[lmid] - pre[i]) - (pre[n] - pre[lmid]));
			long long rv = abs((pre[rmid] - pre[i]) - (pre[n] - pre[rmid]));
			if (lv > rv) {
				l = lmid;
			} else {
				r = rmid;
			}
		}

		int p2 = l;
		long long v2 = abs((pre[l] - pre[i]) - (pre[n] - pre[l]));
		for (int j = l; j <= r; ++j) {
			long long cur = abs((pre[j] - pre[i]) - (pre[n] - pre[j]));
			if (cur < v2) {
				p2 = j;
				v2 = cur;
			}
		}

		vector<long long > tmp;
		tmp.emplace_back(pre[p1]);
		tmp.emplace_back(pre[i] - pre[p1]);
		tmp.emplace_back(pre[p2] - pre[i]);
		tmp.emplace_back(pre[n] - pre[p2]);
		sort(tmp.begin(), tmp.end());
		ans = min(ans, tmp[3] - tmp[0]);
	}

	cout << ans << '\n';

	return 0;
}
