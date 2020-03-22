#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> l;
	l.resize(n);

	vector<int> sum;
	sum.resize(1001);

	for(int i = 0; i < n; ++i) {
		cin >> l[i];
		++sum[l[i]];
	}
	
	for(int i = 0; i < 1000; ++i) {
		sum[i + 1] += sum[i];
	}

	long long ans = 0;

	sort(l.begin(), l.end());

	/*
	 x + i > j;
	 x + j > i;
	 i + j > x

	 x > j - i
	 x > i - j
	 x < i + j
	 */ 

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			ans += sum[min(1000, l[i] + l[j] - 1)] - sum[l[j] - l[i]];
			
			if(l[j] - l[i] < l[i] && l[i] < l[i] + l[j]) {
				--ans;
			}

			if(l[j] - l[i] < l[j] && l[j] < l[i] + l[j]) {
				--ans;
			}
		}
	}

	cout << ans / 3 << '\n';

	return 0;
}
