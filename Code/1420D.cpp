#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

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

	int n, k;
	cin >> n >> k;

	Comb C(n, P);

	vector<pair<int, int> > seg;
	for(int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		seg.emplace_back(l, -1);
		seg.emplace_back(r, 1);
	}

	sort(seg.begin(), seg.end());
	int cur = 0;
	long long ans = 0;
	for(auto [p, f] : seg) {
		if(f == -1) {
			cur += 1;	
		} else {
			ans = (ans + C.C(cur - 1, k - 1)) % P;
			cur -= 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
