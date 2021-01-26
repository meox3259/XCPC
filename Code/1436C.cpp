#include <bits/stdc++.h>

using namespace std;

const int P = 1000000000 + 7;

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
	
	int Fac(int n) {
		return fac[n];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, pos;
	cin >> n >> x >> pos;

	vector<int> a(n);
	iota(a.begin(), a.end(), 1);

	vector<int> big;
	vector<int> small;
	int l = 0;
	int r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (a[mid] <= a[pos]) {
			small.emplace_back(mid);
			l = mid + 1;
		} else {
			big.emplace_back(mid);
			r = mid;
		}
	}

	Comb C(n, P);
	long long ans = 0;
	int s = small.size();
	int t = big.size();

	cout << 1LL * C.C(x - 1, s - 1) * C.Fac(s - 1) % P * C.C(n - x, t) % P * C.Fac(t) % P * C.Fac(n - s - t) % P << '\n';
	
	return 0;
}
