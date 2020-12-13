#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> a(4);
	for (int i = 0; i < 4; ++i) {
		cin >> a[i];
	}

	cout << *min_element(a.begin(), a.end()) << '\n';

	return 0;
}
