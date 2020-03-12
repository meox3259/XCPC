#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	long long a, b;
	cin >> n >> a >> b;
	long long t = n / (a + b);
	cout << t * a + min(a, n % (a + b)) << '\n';
	return 0;
}
