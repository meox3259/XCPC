#include <bits/stdc++.h>

using namespace std;

int main() {
	long long x;
	cin >> x;

	auto f = [&] (long long a) {
		return a * a * a * a * a;
	};
	
	map<long long, int> mp;

	for(long long i = -1000; i <= 1000; ++i) {
		mp[f(i)] = i;
	}

	for(long long i = 0; i <= 1000; ++i) {
		if(mp.count(f(i) - x)) {
			cout << i << ' ' << mp[f(i) - x] << '\n';
			exit(0);
		}
	}

	return 0;
}
