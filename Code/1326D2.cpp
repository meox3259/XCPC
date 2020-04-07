#include <bits/stdc++.h>

using namespace std;

class Hash {
public:
	vector<long long> hash1;
	vector<long long> hash2;
	vector<vector<long long> > power;
	vector<long long> V;
	void init(string s, long long P1, long long P2) {
		V.resize(2);
		V[0] = P1;
		V[1] = P2;
		hash1.resize(s.size() + 1, 0);
		hash2.resize(s.size() + 1, 0);
		power.resize(2);
		for(int i = 0; i < 2; ++i) {
			power[i].resize(s.size() + 1, 0);
		}
		power[0][0] = 1;
		power[1][0] = 1;
		for(int i = 1; i <= s.size(); ++i) {
			hash1[i] = (152LL * hash1[i - 1] + 1LL * (s[i - 1] - '0')) % V[0];
			hash2[i] = (152LL * hash2[i - 1] + 1LL * (s[i - 1] - '0')) % V[1];
			power[0][i] = power[0][i - 1] * 152 % V[0];
			power[1][i] = power[1][i - 1] * 152 % V[1];
		}
	}
	pair<long long, long long> get_hash(int l, int r) {
		long long X1 = (hash1[r + 1] - hash1[l] * power[0][r - l + 1] + V[0] * V[0]) % V[0];
		long long X2 = (hash2[r + 1] - hash2[l] * power[1][r - l + 1] + V[1] * V[1]) % V[1];
		return {X1, X2};
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		string s;
		cin >> s;

		int n = s.size();

		int p = 0;

		while(s[p] == s[n - 1 - p] && p < n - 1 - p) {
			++p;
		}

		Hash H1;
		H1.init(s, 114514, 1919810);

		reverse(s.begin(), s.end());

		Hash H2;
		H2.init(s, 114514, 1919810);

		int len = 0; 

		for(int i = p; i < n - p; ++i) {
			if(H2.get_hash(p, i) == H1.get_hash(n - 1 - i, n - 1 - p)) {
				len = i - p + 1;
			}
		}

		string t = s.substr(0, p);

		string x = "";

		x += t;
		x += s.substr(p, len);

		reverse(t.begin(), t.end());

		x += t;

		reverse(s.begin(), s.end());

		len = 0;

		for(int i = p; i < n - p; ++i) {
			if(H2.get_hash(n - 1 - i, n - 1 - p) == H1.get_hash(p, i)) {
				len = i - p + 1;
			}
		}

		reverse(t.begin(), t.end());

		string y = "";

		y += t;
		y += s.substr(p, len);

		reverse(t.begin(), t.end());

		y += t;

		if(x.size() > y.size()) {
			cout << x << '\n';
		} else {
			cout << y << '\n';
		}
	}

	return 0;
}
