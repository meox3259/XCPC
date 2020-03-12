#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int main() {
	int n;
	long long k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		long long tmp = 0;
		for(int j = 0; j < i; ++j) {
			if(a[i] < a[j]) {
				++tmp;
			}
		}
		ans = (ans + tmp * k % P) % P;
		tmp = 0;
		for(int j = 0; j < n; ++j) {
			if(a[i] < a[j]) {
				++tmp;
			}
		}
		ans = (ans + (k * (k - 1) / 2) % P * tmp % P) % P;
	}
	cout << ans % P << '\n';
	return 0;
}
