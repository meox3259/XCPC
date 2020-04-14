#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int> > l;
	l.resize(m);

	vector<int> cnt;
	cnt.resize(n + 1);

	for(int i = 0; i < m; ++i) {
		cin >> l[i].first;
		l[i].second = i;
	}

	vector<int> suf;
	suf.resize(m);

	for(int i = m - 1; i >= 0; --i) {
		suf[i] = n - l[i].first + cnt[l[i].first];
		
		++cnt[l[i].first];

		if(i + 1 < m) {
			suf[i] = min(suf[i], suf[i + 1] - 1);
		}
	}

	int p = 0;

	vector<int> ans;
	ans.resize(m);

	int cur = 1;
	int low = 0;

	for(int i = 0; i < m; ++i) {
		int lim = n + 1;

		if(i + 1 < m) {
			lim = suf[i + 1];
		}

		ans[l[i].second] = min(n - l[i].first + 1, min(cur, lim));

		if(ans[l[i].second] <= low) {
			cout << -1 << '\n';
			return 0;
		}

		low = ans[l[i].second];

		cur = max(cur, ans[l[i].second] + l[i].first);
	}

	if(cur <= n) {
		cout << -1 << '\n';
		return 0;
	} 

	for(int i : ans) {
		cout << i << ' ';
	}

	cout << '\n';

	return 0;
}
