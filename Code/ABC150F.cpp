#include <bits/stdc++.h>
using namespace std;
const int seed = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a;
	vector<int> b;
	vector<vector<unsigned long long> > h;
	vector<vector<unsigned long long> > rev;
	vector<unsigned long long> Pow;
	h.resize(31);
	rev.resize(31);
	a.resize(n);
	b.resize(n);
	Pow.resize(n);
	Pow[0] = 1;
	for(int i = 1; i < n; ++i) {
		Pow[i] = Pow[i - 1] * seed;
	}
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for(int i = 0; i < 31; ++i) {
		h[i].resize(n);
		rev[i].resize(n);
	}
	for(int j = 0; j < 31; ++j) {
		for(int i = 0; i < n; ++i) {
			h[j][0] = h[j][0] * seed + (a[i] >> j & 1);	
			rev[j][0] = rev[j][0] * seed + ((a[i] >> j & 1) ^ 1);
		}
		for(int i = 1; i < n; ++i) {
			h[j][i] = (h[j][i - 1] - Pow[n - 1] * (a[i - 1] >> j & 1)) * seed + (a[i - 1] >> j & 1);
			rev[j][i] = (rev[j][i - 1] - Pow[n - 1] * ((a[i - 1] >> j & 1) ^ 1)) * seed + ((a[i - 1] >> j & 1) ^ 1);
		}
	}
	vector<unsigned long long> H;
	H.resize(31);
	for(int j = 0; j < 31; ++j) {
		for(int i = 0; i < n; ++i) {
			H[j] = H[j] * seed + (b[i] >> j & 1);
		}
	}
	for(int i = 0; i < n; ++i) {
		bool f = 1;
		int x = a[i] ^ b[0];
		for(int j = 0; j < 31; ++j) {
			if(x >> j & 1) {
				if(rev[j][i] != H[j]) {
					f = 0;
				}
			} else {
				if(h[j][i] != H[j]) {
					f = 0;
				}
			}
		}
		if(f == 1) {
			cout << i << ' ' << x << '\n';
		}
	}
	return 0;
}
