#include <bits/stdc++.h>

using namespace std;

class FoxAndChess {
	public:
	string ableToMove(string s, string t) {
		string x("");
		string y("");
		for(char c : s) {
			if(c != '.') {
				x = x + c;
			}
		}
		for(char c : t) {
			if(c != '.') {
				y = y + c;
			}
		}

		if(x != y) {
			return "Impossible";
		}

		int n = s.size();

		vector<int> pre(n);
		pre[0] = (s[0] == 'R');
		for(int i = 0; i + 1 < n; ++i) {
			pre[i + 1] = pre[i] + (s[i + 1] == 'R');
		}

		int sum = 0;
		for(int i = 0; i < n; ++i) {
			sum = sum + (t[i] == 'R');
			if(sum > pre[i]) {
				return "Impossible";
			}
		}

		vector<int> suf(n);
		suf[n - 1] = (s[n - 1] == 'L');
		for(int i = n - 1; i >= 1; --i) {
			suf[i - 1] = suf[i] + (s[i - 1] == 'L');
		}

		sum = 0;
		for(int i = n - 1; i >= 0; --i) {
			sum = sum + (t[i] == 'L');
			if(sum > suf[i]) {
				return "Impossible";
			}
		}

		return "Possible";
	}
};
