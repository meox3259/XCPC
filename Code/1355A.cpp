#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long a, k;
		cin >> a >> k;
		
		for(long long i = 0; i < k - 1; ++i) {
			vector<int> digit;
			long long t = a;
			while(t) {
				digit.emplace_back(t % 10);
				t /= 10;
			}
			int low = *min_element(digit.begin(), digit.end());
			int high = *max_element(digit.begin(), digit.end());
			if(low == 0) {
				break;
			}
			a += low * high;
		}
		cout << a << '\n';
	}

	return 0;
}
