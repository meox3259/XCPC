#include <bits/stdc++.h>

using namespace std;

class SwapTheString {
	public:
	long long findNumberOfSwaps(string P, int A0, int X, int Y, int N, int K) {
		vector<long long> a(N);
		a[0] = A0;

		for(int i = 1; i < N; ++i) {
			a[i] = (a[i - 1] * X + Y) % 1812447359;
		}

		string s(N, ' ');
		for(int i = 0; i < P.size(); ++i) {
			s[i] = P[i];
		}
		for(int i = P.size(); i < N; ++i) {
			s[i] = (char)(a[i] % 26 + 'a');
		}

		long long ans = 0;

		for(int i = 0; i < K; ++i) {
			vector<int> sum(26);
			for(int j = i; j < N; j += K) {
				int v = s[j] - 'a';
				for(int k = 0; k < v; ++k) {
					ans += sum[k];
				}
				sum[v] += 1;
			}
		}

		return ans;
	}
};
