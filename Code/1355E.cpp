#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b, m;
	cin >> n >> a >> b >> m;

	vector<int> h(n);
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	long long ans = 1000000000000000000;
	long long l = 0;
	long long r = *max_element(h.begin(), h.end()) + 1;

	auto calc = [&] (long long last) {
		long long pre = 0;
		long long suf = 0;
		for(int i : h) {
			if(i < last) {
				pre += last - i;
			} else {
				suf += i - last;
			}
		}

		long long A = pre * a + suf * b;
		long long t = min(pre, suf);
		long long B = t * m + (pre - t) * a + (suf - t) * b;
		return min(A, B);
	};

	while(r - l > 2) {
		long long lmid = (l + l + r) / 3;
		long long rmid = (l + r + r) / 3;
		if(calc(lmid) < calc(rmid)) {
			r = rmid;
		} else {
			l = lmid;
		}
	}

	for(long long i = l; i <= r; ++i) {
		ans = min(ans, calc(i));
	}

	cout << ans << '\n';

	return 0;
}
