#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6 + 5;
const int P = 1e9 + 7;
vector<ll> fac;
vector<ll> inv;
vector<ll> facinv;
ll C(int n, int m) {
	++n;
	++m;
	return fac[n + m] * facinv[n] % P * facinv[m] % P;
}
int main() {
	fac.resize(maxn);
	facinv.resize(maxn);
	inv.resize(maxn);
	fac[0] = 1;
	inv[1] = 1;
	facinv[0] = 1;
	for(int i = 1; i < maxn; ++i) {
		fac[i] = fac[i - 1] * i % P;
		if(i != 1) {
			inv[i] = (P - P / i) * inv[P % i] % P;
		}
		facinv[i] = facinv[i - 1] * inv[i] % P;
	}
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	cout << ((C(r2, c2) - C(r1 - 1, c2) - C(r2, c1 - 1) + C(r1 - 1, c1 - 1)) % P + P) % P << '\n';
	return 0;
}
