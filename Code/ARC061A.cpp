#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.size();
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		long long t = 0;
		for(int j = i; j < n; ++j) {
			t = t * 10 + s[j] - '0';
			long long tmp = t;
			cerr << "i = " << i << ' ' << "j = " << j << ' ' << "tmp = " << tmp << '\n';
			for(int k = 0; k < i - 1; ++k) {
				tmp *= 2;
			}
			for(int k = j + 2; k < n; ++k) {
				tmp *= 2;
			}
			cerr << "tmp = " << tmp << '\n';
			ans += tmp;
		}
	}
	cout << ans << '\n';
	return 0;
}
