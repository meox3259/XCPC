#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;

	n %= k;

	cout << min(n, k - n) << '\n'; 

	return 0;
}
