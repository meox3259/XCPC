#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
ll h, w, t;
ll power(ll x, ll t) {
	ll ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}
int main() {
	cin >> h >> w >> t;
	ll n = h / __gcd(h, t), m = w / __gcd(w, t);
	ll tmp = (power(2LL, n) + power(2LL, m) + power(2LL, __gcd(n, m)) - 3 + P) % P;
	ll c = __gcd(h, t) * __gcd(w, t);
	cout << power(tmp, c) << '\n';
	return 0;
}
