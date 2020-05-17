#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

long long power(long long x, long long t) {
	long long ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}

const int N=515;

int n = 512;

struct matrix {
    long long a[N] = {0};
    friend inline matrix operator * (const matrix &A, const matrix &B) {
        matrix res;
        for(int i = 0; i < n; ++i) {
			res.a[i] = 0;
		}

		for(int j = 0; j < n; ++j) {
            for(int i = 0; i < n; ++i) {
                res.a[i] = (res.a[i] + A.a[j] * B.a[(i - j + n) % n] % P) % P;
			}
		}

        return res;
    } 
    friend inline matrix Pow(matrix A, int b) {
        matrix res;
        res.a[0] = 1;
        for(int i = 1; i < n; ++i) {
			res.a[i] = 0;
		}
        for(;b;b>>=1,A = A * A) {
			if(b & 1) {
				res=res*A;
			}
		}
        return res;
    }
}A,t;

class ModCounters {
	public:
	int findExpectedSum(vector <int> p, int A0, int X, int Y, int N, int K)	{
		vector<long long> a(N);
		a[0] = A0;
		for(int i = 1; i < N; ++i) {
			a[i] = (a[i - 1] * X + Y) % 1812447359;
		}

		vector<int> s(N);

		for(int i = 0; i < p.size(); ++i) {
			s[i] = p[i];
		}

		for(int i = p.size(); i < N; ++i) {
			s[i] = a[i] % 512;
		}

		for(int i : s) {
			A.a[i] += 1;
		}

		long long inv = power(N, P - 2);

		t.a[0] = (P + 1 - inv) % P;
		t.a[1] = inv;

		A = A * Pow(t, K);

		long long ans = 0;

		for(int i = 0; i < 512; ++i) {
			ans = (ans + A.a[i] * i) % P;
		}

		return ans;
	}
} B;
/*
int main() {
	int m, n, A0, x, y, k;
	cin >> m;
	vector<int> p(m);
	for(int i = 0; i < m; ++i) {
		cin >> p[i];
	}

	cin >> A0 >> x >> y >> n >> k;

	cout << B.findExpectedSum(p, A0, x, y, n, k) << '\n';

	return 0;
}*/
