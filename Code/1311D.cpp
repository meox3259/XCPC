#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> ans;
		ans.resize(N + 1);
		int mn = 1'000'000'000;
		int A, B, C;
		for(int i = 1; i <= 10000; ++i) {
			for(int j = i; j <= 100000; j += i) {
				for(int k = j; k <= 100000; k += j) {
					int tmp = 0;
					tmp += abs(a - i);
					tmp += abs(b - j);
					tmp += abs(c - k);
					if(tmp < mn) {
						mn = tmp;
						A = i;
						B = j;
						C = k;
					}
				}
			}
		}
		cout << mn << '\n';
		cout << A << ' ' << B << ' ' << C << '\n';
	}
	return 0;
}
