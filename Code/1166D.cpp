#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		long long a, b, m; cin >> a >> b >> m;
		if(a == b) {
			cout << 1 << " " << a << endl;
			continue;
		}
		long long p = 2;
		while((1LL << (p - 2)) * (a + m) < b) {
			++p;
		}
		if((1LL << (p - 2)) * (a + 1) > b) {
			cout << -1 << endl;
			continue;
		}
		cout << p << " " << a << " ";
		long long tmp = b - (1LL << (p - 2)) * (a + 1), sum = a;
		for(int i = 2; i < p; ++i) {
			long long w = min(m - 1, tmp / (1LL << (p - i - 1)));
			tmp -= (1LL << (p - i - 1)) * w;
			cout << sum + w + 1 << " ";
			sum += sum + w + 1;
		}
		cout << b << endl;
	}
	return 0;
}
