#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		vector<int> a(3);
		for(int i = 0; i < 3; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		if(a[0] + a[1] < a[2] - 1) {
			cout << "No" << '\n';
		} else {
			cout << "Yes" << '\n';
		}
	}

	return 0;
}
