#include <bits/stdc++.h>
using namespace std;
int main() {
	long long A, B, K;
	cin >> A >> B >> K;
	long long t = A;
	A -= min(K, A);
	K -= min(K, t);
	B -= min(K, B);
	cout << A << ' ' << B << '\n';
	return 0;
}
