#include <bits/stdc++.h>
using namespace std;
int main() {
	long long A, B;
	cin >> A >> B;
	cout << A * B / __gcd(A, B) << '\n';
	return 0;
}
