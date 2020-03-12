#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	int q;
	cin >> q;
	int r = 0;
	string a = "";
	string b = "";
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			r ^= 1;
		}
		if(t == 2) {
			int f;
			char c;
			cin >> f >> c;
			if(f == 1) {
				if(r == 0) {
					a = a + c; 
				} else {
					b = b + c;
				}
			}
			if(f == 2) {
				if(r == 0) {
					b = b + c;
				} else {
					a = a + c;
				}
			}
		}
	}
	if(r == 1) {
		reverse(s.begin(), s.end());
		reverse(b.begin(), b.end());
		cout << b << s << a << '\n';
	} else {
		reverse(a.begin(), a.end());
		cout << a << s << b << '\n';
	}
	return 0;
}
