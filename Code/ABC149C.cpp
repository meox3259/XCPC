#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	auto isprime = [&] (int n) {
		if(n == 2) {
			return true;
		}
		for(int i = 2; i * i <= 2 * n; ++i) {
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	};
	while(!isprime(n)) {
		++n;
	}
	cout << n << '\n';
	return 0;
}
