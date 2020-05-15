#include <bits/stdc++.h>

using namespace std;

class PyramidSequences {
	public:
	long long distinctPairs(int N, int M) {
		--N; --M;

		long long d = __gcd(N, M);
		N /= d; M /= d;

		long long ans = 0;
		ans = ans + 1LL * (N + 1) * (M + 1) / 2;
		ans = ans + 1LL * N * M * (d - 1);

		return ans;
	}
};
