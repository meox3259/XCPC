#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector<int> a;
		a.resize(n);

		vector<int> b;
		b.resize(n);

		a[0] = 1;
		b[0] = 1;

		bool ok = false;

		for(int i = 1; i < n; ++i) {
			if(ok) {
				a[i] = 0;
				b[i] = s[i] - '0';
			} else {
				if(s[i] == '2') {
					a[i] = 1;
					b[i] = 1;
				} else if(s[i] == '0') {
					a[i] = 0;
					b[i] = 0;
				} else {
					ok = true;
					a[i] = s[i] - '0';
					b[i] = 0;
				}
			}
		}
		
		for(auto x : a) {
			cout << x;
		}

		cout << '\n';
	
		for(auto x : b) {
			cout << x;
		}

		cout << '\n';
	}

	return 0;
}
