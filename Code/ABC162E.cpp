#include <iostream>
#include <vector>

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

int main() {
	int n, k;
	cin >> n >> k;

	long long ans = 0;

	vector<long long> Pow;

	Pow.resize(k + 1);

	for(int i = 1; i <= k; ++i) {
		Pow[i] = power(i, n);
	}

	vector<long long> mu;
	mu.resize(k + 1);

	mu[1] = 1;

	vector<bool> mark;
	mark.resize(k + 1);

	vector<int> pri;

	for(int i = 2; i <= k; ++i) {
		if(!mark[i]) {
			mu[i] = -1;
			pri.emplace_back(i);
		}

		for(int j = 0; j < pri.size() && i * pri[j] <= k; ++j) {
			mark[i * pri[j]] = true;

			if(i % pri[j] == 0) {
				break;
			}

			mu[i * pri[j]] = -mu[i];
		} 
	}

	for(int i = 1; i <= k; ++i) {
		long long f = 1;

		for(int j = i; j <= k; j += i) {
			ans = (ans + mu[j / i] * Pow[k / j] * i % P + P) % P;
		}
	}

	cout << ans << '\n';

	return 0;
}
