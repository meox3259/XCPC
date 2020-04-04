
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;

	if(n == 2) {
		cout << 1 << '\n';
		return 0;
	}
	
	long long ans = 0;

	long long m = n - 1;

	long long t = 1;

	for(long long i = 2; i * i <= (n - 1) * 2; ++i) {
		if(m % i == 0) {
			long long c = 0;

			while(m % i == 0) {
				m /= i;
				++c;
			}

			t *= (c + 1);
		}
	}

	if(m > 1) {
		t *= 2;
	}

	ans += t;

	for(long long i = 2; i * i <= n * 2; ++i) {
		if(n % i == 0) {
			long long t = n;
			
			while(t % i == 0) {
				t /= i;
			}

			if(t % i == 1) {
				++ans;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
