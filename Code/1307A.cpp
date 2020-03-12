#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, d;
		cin >> n >> d;
		vector<int> a;
		a.resize(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for(int _ = d; _ > 0; --_) {
			for(int i = 1; i < n; ++i) {
				if(a[i] > 0) {
					--a[i];
					++a[i - 1];
					break;
				}
			}
		}
		cout << a[0] << '\n';
	}
	return 0;
}
