#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> h(n);
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	long long sum = 0;
	for(long long i : h) {
		sum += i;
	}

	sum -= 1LL * n * (n - 1) / 2;
	for(int i = 0; i < n; ++i) {
		cout << i + sum / n + (i < sum % n) << " \n"[i == n - 1];
	}

	return 0;
}
