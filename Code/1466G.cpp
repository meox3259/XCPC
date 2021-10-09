#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
const int P1 = 1000000007;
const int P2 = 998244353;
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
  int n, q;
  cin >> n >> q;
  string s, t;
  cin >> s >> t;
  vector<long long> i2(n + 1);
  i2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    i2[i] = i2[i - 1] * 2 % P;
  }
  vector<long long> v2(n + 1);
  v2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    v2[i] = v2[i - 1] * ((P + 1) / 2) % P;
  }
  vector<vector<long long>> suf(n + 1, vector<long long> (26));
  for (int i = 0; i < n; ++i) {
    suf[i][t[i] - 'a'] = i2[n - i - 1];
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      suf[i][j] += suf[i + 1][j];
      suf[i][j] %= P;
    }
  }
  vector<string> all{s};
  int sz = min(18, n);
  for (int i = 0; i < sz; ++i) {
    all.push_back(all.back() + t[i] + all.back());
  }
  while (q--) {
    int k;
    string w;
    cin >> k >> w;
    int p = -1;
    string cur = s;
    for (int i = 0; i <= k; ++i) {
      if (all[i].size() >= w.size()) {
        p = i - 1;
        cur = all[i];
        break;
      }
    }
    if (cur.size() < w.size()) {
      cout << 0 << '\n'; 
      continue;
    }
    Hash h;
    h.init(w, P1, P2);
    Hash h1;
    h1.init(cur, P1, P2);
    int l = w.size();
    int l1 = cur.size();
    int tot = 0;
    for (int i = 0; i + l - 1 < l1; ++i) {
      if (h.get_hash(0, l - 1) == h1.get_hash(i, i + l - 1)) {
        tot++;
      } 
    }
    long long ans = 0;
    ans += 1ll * tot * i2[k - p - 1];
    ans %= P;
    int m = cur.size();
    for (int i = 0; i < l; ++i) {
      if ((i == 0 || h1.get_hash(m - i, m - 1) == h.get_hash(0, i - 1)) && 
          (i == l - 1 || h1.get_hash(0, l - 2 - i) == h.get_hash(i + 1, l - 1))) {
        ans += (suf[p + 1][w[i] - 'a'] - suf[k][w[i] - 'a'] + P) * v2[n - k];
        ans %= P;
      }
    }
    cout << ans << '\n';
  }
}
