#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;	
	for(int i = n; i; --i) {
		for(int j = 1; j < i; ++j) {
			cout << __builtin_ctz(j) + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
