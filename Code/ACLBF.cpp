#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
const int N = 100005;

class Comb {
	public:
    vector<int> fac;
    vector<int> inv;
    vector<int> facinv;
    int P;

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

namespace poly { //method : use c = multiply(a, b)
    vector<int> rev = {0, 1};
    vector<int> Root = {0, 1};

    const int P = 998244353;
    const int G = 3;

    int power(int x, int t) {
        int ret = 1;
        for(; t; t >>= 1, x = 1LL * x * x % P) {
            if(t & 1) {
                ret = 1LL * ret * x % P;
            }
        }
        return ret;
    }

    void init(int n) {
        if(n <= Root.size()) {
            return;
        }
        rev.resize(n);
        for(int i = 0; i < n; ++i) {
            rev[i] = (rev[i >> 1] | ((i & 1) * n)) >> 1;
        }
        if((int)Root.size() < n) {
            int k = __builtin_ctz(Root.size());
            Root.resize(n);
            while((1 << k) < n) {
                int z = power(G, (P - 1) >> (k + 1));
                for(int i = 1 << (k - 1); i < (1 << k); ++i) {
                    Root[2 * i] = Root[i];
                    Root[2 * i + 1] = 1LL * Root[i] * z % P;
                }
                k += 1;
            }
        }
    }

    void dft(vector<int> &a, int n) {
        init(n);
        int s = __builtin_ctz(rev.size() / n);
        for(int i = 0; i < n; ++i) {
            if(i < rev[i] >> s) {
                swap(a[i], a[rev[i] >> s]);
            }
        }
        for(int k = 1; k < n; k = k * 2) {
            for(int i = 0; i < n; i = i + k * 2) {
                for(int j = 0; j < k; ++j) {
                    int t = 1LL * Root[j + k] * a[i + j + k] % P;
                    a[i + j + k] = (a[i + j] - t + P) % P;
                    a[i + j] = (a[i + j] + t) % P; 
                }
            }
        }
    }

    void idft(vector<int> &a, int n) {
        reverse(a.begin() + 1, a.end());
        dft(a, n);
        int inv = power(n, P - 2);
        for(int i = 0; i < n; ++i) {
            a[i] = 1LL * a[i] * inv % P;
        }
    }

    vector<int> multiply(vector<int> a, vector<int> b) { // return a * b size = sz(a) + sz(b)
        int s = a.size() + b.size() - 1;
        if(s <= 0) {
            return {};
        }
        int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0;
        int n = 1 << L;
        a.resize(n);
        dft(a, n);
        b.resize(n);
        dft(b, n);
        for(int i = 0; i < n; ++i) {
            a[i] = 1LL * a[i] * b[i] % P;
        }
        idft(a, n);
        a.resize(s);
        return a;
    }
}

long long power(long long x, long long t) {
	long long ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}

class Poly {
	public:
	vector<int> a;

	Poly() {}
	Poly(const vector<int> &_a) : a(_a) {}

	bool friend operator < (const Poly &a, const Poly &b) {
		return a.a.size() > b.a.size();
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> h(n * 2);
	for(int i = 0; i < n * 2; ++i) {
		cin >> h[i];
	}

	Comb C(n * 2, P);		

	vector<int> cnt(N);
	for(int i : h) {
		cnt[i] += 1;
	}

	int sum = 0;
	priority_queue<Poly> q;

	auto calc = [&] (int n) {
		long long tmp = power(2, n);
		return 1LL * C.fac[2 * n] * C.facinv[n] % P * power(tmp, P - 2) % P;
	};	

	for(int i = 0; i < N; ++i) {
		if(cnt[i] >= 2) {
			Poly tmp;
			tmp.a.resize(cnt[i] / 2 + 1);
			for(int j = 0; j + j <= cnt[i]; ++j) {
				long long x = C.C(cnt[i], j * 2);
				tmp.a[j] = x * calc(j) % P;
			}
			q.emplace(tmp);
		}
	}

	while(q.size() > 1) {
		Poly a = q.top();
		q.pop();
		Poly b = q.top();
		q.pop();
		Poly c;
		c.a = poly::multiply(a.a, b.a);
		q.emplace(c);
	}

	if(q.size() == 0) {
		cout << calc(n) << '\n';
		exit(0);
	}

	vector<int> dp = q.top().a;

	for(int i = 0; i < min(n + 1, (int)dp.size()); ++i) {
		dp[i] = 1LL * dp[i] * calc(n - i) % P;
	}

	long long ans = 0;
	for(int i = 0; i < dp.size(); ++i) {
		ans = (ans + 1LL * (i % 2 == 0 ? 1 : -1) * dp[i] + P) % P;
	}

	cout << ans << '\n';

	return 0;
}
