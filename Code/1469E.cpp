#include <bits/stdc++.h>

using namespace std;

const int P1 = 998244353;
const int P2 = 19260817;

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

	while (T --) {
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		string t(s);
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				t[i] = '1';
			} else {
				t[i] = '0';
			}
		}

		Hash G;
		G.init(t, P1, P2);

		map<pair<long long, long long>, bool> vis;
		for (int i = 0; i + k - 1 < n; ++i) {
			vis[G.get_hash(i, i + k - 1)] = true;
		}

		int m = n + 1;
		if (k < 30) {
			m = min(m, 1 << k);
		}

		bool ok = false;
		for (int i = 0; i < m; ++i) {
			int tmp = i;
			vector<int> bit;
			long long X1 = 0;
			long long X2 = 0;
			long long pw1 = 1;
			long long pw2 = 1;
			while (tmp > 0) {
				int v = tmp & 1;
				if (v == 1) {
					X1 = (X1 + pw1) % P1;
					X2 = (X2 + pw2) % P2;
				}
				pw1 = pw1 * 152 % P1;
				pw2 = pw2 * 152 % P2;
				tmp >>= 1;
			}

			if (vis.find(make_pair(X1, X2)) == vis.end()) {
				ok = true;
				int tmp = i;
				vector<int> bit;
				while (tmp > 0) {
					bit.emplace_back(tmp & 1);
					tmp >>= 1;
				}
				
				while (bit.size() < k) {
					bit.emplace_back(0);
				}

				cout << "YES" << '\n';

				while (!bit.empty()) {
					cout << bit.back();
					bit.pop_back();
				}

				cout << '\n';
				
				break;
			}		
		}

		if (!ok) {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
