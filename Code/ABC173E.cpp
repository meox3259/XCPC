
#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;
const long long inf = 1000000000000000;

long long power(long long x, long long t) {
	long long ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long t = 1;
	if(n == k) {
		for(int i = 0; i < n; ++i) {
			t = (t * a[i] % P + P) % P;
		}
		cout << t << '\n';
		exit(0);
	}

	bool pos = false;
	bool zero = false;
	for(int i = 0; i < n; ++i) {
		if(a[i] > 0) {
			pos = true;
		}
		if(a[i] == 0) {
			zero = true;
		}
	}

	sort(a.begin(), a.end(), [&] (long long i, long long j) {
		return abs(i) > abs(j);
	});

	if(!pos) {
		if(k % 2 == 1) {
			sort(a.begin(), a.end(), [&] (long long i, long long j) {
				return i > j;
			});
		} else {
			sort(a.begin(), a.end());
		}

		long long ans = 1;
		for(int i = 0; i < k; ++i) {
			ans = (ans * a[i] % P + P) % P;
		}
		
		cout << ans << '\n';
		exit(0);
	}

	long long ans = 1;
	int minus = 0;
	for(int i = 0; i < k; ++i) {
		ans = ans * abs(a[i]) % P;
		if(a[i] < 0) {
			minus += 1;
		}
	}

	if(minus % 2 == 0) {
		cout << ans << '\n';
		exit(0);
	}

	long long nxtpos = inf;
	long long nxtneg = inf;
	long long lastpos = inf;
	long long lastneg = inf;
	for(int i = k; i < a.size(); ++i) {
		if(a[i] >= 0) {
			nxtpos = a[i];
			break;
		}
	}
	for(int i = k; i < a.size(); ++i) {
		if(a[i] <= 0) {
			nxtneg = -a[i];
			break;
		}
	}
	for(int i = k - 1; i >= 0; --i) {
		if(a[i] >= 0) {
			lastpos = a[i];
			break;
		}
	}
	for(int i = k - 1; i >= 0; --i) {
		if(a[i] <= 0) {
			lastneg = -a[i];
			break;
		}
	}

	bool X = (nxtpos != inf) && (lastneg != inf);
	bool Y = (nxtneg != inf) && (lastpos != inf);

	if(X && Y) {
		if(nxtpos * lastpos > nxtneg * lastneg) {
			ans = ans * power(lastneg, P - 2) % P * nxtpos % P;
		} else {
			ans = ans * power(lastpos, P - 2) % P * nxtneg % P;
		}
	} else if(X) {
		ans = ans * nxtpos % P * power(lastneg, P - 2) % P;
	} else if(Y) {
		ans = ans * nxtneg % P * power(lastpos, P - 2) % P;
	} else if(zero) {
		ans = 0;
	}

	cout << ans << '\n';

	return 0;
}
