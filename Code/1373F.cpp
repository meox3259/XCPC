#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;
		
		vector<int> a(n * 2);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		for(int i = 0; i < n; ++i) {
			a[i + n] = a[i];
		}

		vector<int> b(n * 2);
		for(int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		for(int i = 0; i < n; ++i) {
			b[i + n] = b[i];
		}

		long long suma = 0;
		for(int i : a) {
			suma += i;
		}

		long long sumb = 0;
		for(int i : b) {
			sumb += i;
		}

		bool ok = true;
		if(suma > sumb) {
			ok = false;
		} 

		vector<long long> prea(n * 2);
		prea[0] = a[0];
		for(int i = 0; i + 1 < n * 2; ++i) {
			prea[i + 1] = prea[i] + a[i + 1];
		}

		vector<long long> preb(n * 2);
		preb[0] = b[0];
		for(int i = 0; i + 1 < n * 2; ++i) {
			preb[i + 1] = preb[i] + b[i + 1];
		}

		multiset<long long> s;
		for(int i = 1, j = 1; i < n * 2; ++i) {
			 s.emplace(preb[i - 1] - prea[i]);
			 while(i - j >= n) {
				s.erase(s.find(preb[j - 1] - prea[j]));
				j += 1;
			 }
			 if(preb[i] - prea[i] - *s.rbegin() < 0) {
				ok = false;
			 }
		}

		if(ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
