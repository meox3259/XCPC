#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

class Matrix {
	public:
	vector<vector<long long> > m;
	
	int n;

	Matrix(int N) {
		n = N;

		m.resize(N);
		for(int i = 0; i < N; ++i) {
			m[i].resize(N);
		}
	}

	void set() {
		for(int i = 0; i < n; ++i) {
			m[i][i] = 1;
		}
	}

	friend Matrix operator * (const Matrix &a, const Matrix &b) {
		int n = a.n;

		Matrix ret(n);

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int k = 0; k < n; ++k) {
					ret.m[i][j] = (ret.m[i][j] + a.m[i][k] * b.m[k][j] % P) % P;
				}
			}
		}

		return ret;
	}

	friend Matrix operator ^ (Matrix x, long long t) {
		int n = x.n;

		Matrix ret(n);
		ret.set();

		for(; t; t >>= 1, x = x * x) {
			if(t & 1) {
				ret = ret * x;
			}
		}

		return ret;
	}
};

int main() {
	long long n, m, L, R;
	cin >> n >> m >> L >> R;

	auto power = [&] (long long x, long long t) {
		long long ret = 1;

		for(; t; t >>= 1, x = x * x % P) {
			if(t & 1) {
				ret = ret * x % P;
			}
		}
		
		return ret;
	};

	if((n * m) & 1LL) {
		cout << power(R - L + 1, m * n) << '\n';
	} else {
		Matrix ans(2);
		
		long long odd = 0;
		long long even = 0;

		even += R / 2;
		even -= (L - 1) / 2;
		odd += (R + 1) / 2;
		odd -= L / 2;

		ans.m[0][0] = even; ans.m[0][1] = odd;
		ans.m[1][0] = odd; ans.m[1][1] = even;

		ans = ans ^ (n * m);

		cout << ans.m[0][0] << '\n';
	}

	return 0;
}
