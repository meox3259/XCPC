#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

class Comb {
    vector<int> fac;
    vector<int> inv;
    vector<int> facinv;
    int P;

    public:
    Comb() {}
    Comb(int N, int P) : fac(N + 1), inv(N + 1), facinv(N + 1), P(P) {
        fac[0] = 1;
        for(int i = 1; i <= N; ++i) {
            fac[i] = 1LL * fac[i - 1] * i % P;
        }
        inv[1] = 1;
        for(int i = 2; i <= N; ++i) {
            inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
        }
        facinv[0] = 1;
        for(int i = 1; i <= N; ++i) {
            facinv[i] = 1LL * facinv[i - 1] * inv[i] % P;
        }
    }

    int C(int n, int m) {
        if(n < m) {
            return 0;
        }
        return 1LL * fac[n] * facinv[m] % P * facinv[n - m] % P;
    }

    int Inv(int n) {
        return inv[n];
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, m, k;
		cin >> n;

		m = 3;
		k = 2;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<int> pre(n + 1);
		vector<int> cnt(n + 1);
		for (int i : a) {
			pre[i] ++;
			cnt[i] ++;
		}
		for (int i = 0; i < n; ++i) {
			pre[i + 1] += pre[i];
		}

		Comb C(n, P);
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (cnt[i]) {
				int x = pre[i] - pre[max(0, i - k - 1)];	
				auto C = [&] (long long x) {
					return x * (x - 1) * (x - 2) / 6;
				};
				ans = (ans + C(x) - C(x - cnt[i]));
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
