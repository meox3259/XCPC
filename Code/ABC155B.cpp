#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	bool f = 1;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if(x % 2 == 0) {
			if(x % 3 != 0 && x % 5 != 0) {
				f = 0;
			}
		}
	}
	if(f) {
		cout << "APPROVED" << '\n';
	} else {
		cout << "DENIED" << '\n';
	}
	return 0;
}
