#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

class seg {
	vector<int> t;

	public:
	seg(int n) {
		t.resize(4 * n + 5);
	}

	void build(int l, int r, int x, vector<int>& pre, vector<int>& suf) {
		if(l == r) {
			t[x] = suf[l] + pre[l] - 1;
			return;
		}

		int mid = l + r >> 1;

		build(l, mid, x << 1, pre, suf);
		build(mid + 1, r, x << 1 | 1, pre, suf);

		t[x] = max(t[x << 1], t[x << 1 | 1]);
	}

	int query(int l, int r, int x, int a, int b) {
		if(l > b || r < a) {
			return -inf;
		}

		if(l >= a && r <= b) {
			return t[x];
		}

		int mid = l + r >> 1;

		return max(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, c;
	cin >> n >> k >> c;

	string s;
	cin >> s;

	if(k == 1) {
		int cnt = 0;

		for(auto x : s) {
			if(x == 'o') {
				++cnt;
			}
		}

		if(cnt == 1) {
			for(int i = 0; i < n; ++i) {
				if(s[i] == 'o') {
					cout << i + 1 << '\n';
					return 0;
				}
			}
		}

	}

	if(c == 0) {
		int cnt = 0;

		for(auto x : s) {
			if(x == 'o') {
				++cnt;
			}
		}

		if(cnt == k) {
			for(int i = 0; i < n; ++i) {
				if(s[i] == 'o') {
					cout << i + 1 << '\n';
				}
			}
		}

		return 0;
	}

	vector<int> pre;
	pre.resize(n, -inf);

	vector<int> dp;
	dp.resize(n, -inf);

	for(int i = 0; i < n; ++i) {
		if(s[i] == 'o') {
			pre[i] = 1;
			if(i - c - 1 >= 0) {
				pre[i] = max(pre[i], dp[i - c - 1] + 1);
			}
		}
		
		dp[i] = pre[i];

		if(i > 0) {
			dp[i] = max(dp[i], dp[i - 1]);	
		}
	}

	dp.assign(n, -inf);

	vector<int> suf;
	suf.resize(n);

	for(int i = n - 1; i >= 0; --i) {
		if(s[i] == 'o') {
			suf[i] = 1;
			if(i + c + 1 < n) {
				suf[i] = max(suf[i], dp[i + c + 1] + 1);
			}
		}

		dp[i] = suf[i];

		if(i < n - 1) {
			dp[i] = max(dp[i], dp[i + 1]);
		}
	}

	int mx = 0;

	for(int i = 0; i < n; ++i) {
		mx = max(suf[i] + pre[i] - 1, mx);
	}

	if(mx < k) {
		return 0;
	}


	seg seg(n);

	seg.build(0, n - 1, 1, pre, suf);

	for(int i = 0; i < n; ++i) {
		int l = seg.query(0, n - 1, 1, max(0, i - c), i - 1);
		int r = seg.query(0, n - 1, 1, i + 1, min(n - 1, i + c));

		if(k > 1 && max(l, r) < k && s[i] == 'o') {
			cout << i + 1 << '\n';
		}
	}

	return 0;
}
