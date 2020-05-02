#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a, b, n;
	cin >> a >> b >> n;

	long long x = min(n, b - 1);

	cout << (a * x / b) << '\n';
	
	return 0;
}
