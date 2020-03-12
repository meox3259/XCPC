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
			hash1[i] = (251LL * hash1[i - 1] + 1LL * (s[i - 1] - '0')) % V[0];
			hash2[i] = (251LL * hash2[i - 1] + 1LL * (s[i - 1] - '0')) % V[1];
			power[0][i] = power[0][i - 1] * 251 % V[0];
			power[1][i] = power[1][i - 1] * 251 % V[1];
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
	int n, q;
	string t;
	cin >> n >> t >> q;
	vector<int> st;
	for(int i = 0; i < n; ++i) {
		if(t[i] == '0') {
			st.emplace_back(i);
		}
	}
	string S1 = "", S2 = "";
	for(auto x : st) {
		if(x & 1) {
			S1 += '1'; 
		} else {
			S1 += '0';
		}
	}
	for(auto x : st) {
		if(x & 1) {
			S2 += '0';
		} else {
			S2 += '1';
		}
	}
	Hash C1, C2;
	C1.init(S1, 1234567LL, 7654321LL);
	C2.init(S2, 1234567LL, 7654321LL);
	auto check = [&] (int la, int ra, int lb, int rb) {
		int pos1 = lower_bound(st.begin(), st.end(), la) - st.begin();
		int pos2 = lower_bound(st.begin(), st.end(), ra) - st.begin();
		int pos3 = lower_bound(st.begin(), st.end(), lb) - st.begin();
		int pos4 = lower_bound(st.begin(), st.end(), rb) - st.begin();
		if(pos2 - pos1 != pos4 - pos3) {
			return false;
		}
		pair<long long, long long> X, Y;
		if(la & 1) {
			X = C1.get_hash(pos1, pos2 - 1);
		} else {
			X = C2.get_hash(pos1, pos2 - 1);
		}
		if(lb & 1) {
			Y = C1.get_hash(pos3, pos4 - 1);
		} else {
			Y = C2.get_hash(pos3, pos4 - 1);
		}
		if(X == Y) {
			return true;
		} else {
			return false;
		}
	};
	while(q--) {
		int a, b, len;
		cin >> a >> b >> len;
		--a;
		--b;
		bool f = check(a, a + len, b, b + len);
		if(f == true) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}
	return 0;
}
