#include <bits/stdc++.h>

using namespace std;

const int P = 786433;

class RandomPartition {
	public:
		int expectedSum(vector <int> nums, int N, int M, int B1, int B2) {
			vector<int> h;
			h.resize(2 * N);

			for(int i = 0; i < nums.size(); ++i) {
				h[i] = nums[i];
			}

			for(int i = nums.size(); i < 2 * N; ++i) {
				h[i] = (1LL * h[i - 1] * B1 + 1LL * h[i - 2] * B2) % M;
			}

			auto power = [&] (long long x, long long t) {
				long long ret = 1;
				
				for(; t; t >>= 1, x = x * x % P) {
					if(t & 1) {
						ret = ret * x % P;
					}
				}

				return ret;
			};

			sort(h.begin(), h.end());

			long long ans = 0;

			for(int i = 0; i < N; ++i) {
				ans += h[N + i] - h[i];
			}

			ans %= P;
			ans = ans * power(N, P - 2) % P;

			return (int)ans;
		}
};
