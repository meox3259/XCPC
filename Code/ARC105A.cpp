#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> a(4);
	for(int i = 0; i < 4; ++i) {
		cin >> a[i];
	}

	int sum = 0;
	for(int i : a) {
		sum += i;
	}

	for(int i = 0; i < 4; ++i) {
		if(a[i] + a[i] == sum) {
			cout << "Yes" << '\n';
			exit(0);
		}
	}

	for(int i = 0; i < 4; ++i) {
		for(int j = i + 1; j < 4; ++j) {
			if(a[i] + a[i] + a[j] + a[j] == sum) {
				cout << "Yes" << '\n';
				exit(0);
			}
		}
	}

	cout << "No" << '\n';

	return 0;
}
