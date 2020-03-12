#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	for(int kase = 0; kase < q; ++kase) {
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		int n = s.size();
		int cnt = 0;
		vector<int> st;
		for(int i = 0; i < n; ++i) {
			if(s[i] == '.') {
				++cnt;
			} else {
				if(cnt > 0) {
					st.emplace_back(cnt);
				}	
				cnt = 0;
			}
		}
		if(cnt > 0) {
			st.emplace_back(cnt);
		}
		int A = 0;
		int B = 0;
		int C = 0;
		for(auto c : st) {
			if(c >= b && c < a) {
				++A;
			}
			if(c >= a && c < 2 * b) {
				++B;
			}
			if(c >= 2 * b) {
				++C;
			}
		}
		if(A > 0) {
			cout << "NO" << '\n';
			continue;
		}
		if(C > 1) {
			cout << "NO" << '\n';
			continue;
		}
		if(C == 0) {
			if(B & 1) {
				cout << "YES" << '\n';
			} else {
				cout << "NO" << '\n';
			}
			continue;
		}
		int Max = *max_element(st.begin(), st.end());
		bool f = false;
		for(int i = 0; i + a <= Max; ++i) {
			int pre = i;
			int suf = Max - i - a;
			if(pre >= b && pre < a) {
				continue;
			}
			if(suf >= b && suf < a) {
				continue;
			}
			if(pre >= 2 * b || suf >= 2 * b) {
				continue;
			}
			int TB = B + (pre >= a) + (suf >= a);
			if(!(TB & 1)) {
				f = true;
			}
		}
		if(f == true) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
	/*
	 	......
		.xxx..
		.......
		xxx....
		.xxx...
		..xxx..
	 */
	return 0;
}
