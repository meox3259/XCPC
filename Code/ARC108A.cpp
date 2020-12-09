#include <bits/stdc++.h>

using namespace std;

int main() {
	long long s, p;
	cin >> s >> p;

	for (long long i = 1; i * i <= p; ++i) {
		if (p % i == 0 && i + (p / i) == s) {
			cout << "Yes" << '\n';
			exit(0);
		}
	}

	cout << "No" << '\n';

	return 0;
}
