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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  sort(s.begin(), s.end(), [&] (string x, string y) {
    return x.size() < y.size();
  });
  map<pair<long long, long long>, int> mp;
  map<pair<long long, long long>, int> hav1;
  for (int i = 0; i < n; ++i) {
    Hash h;
    h.init(s[i], 114514191, 191981010);
    for (int j = 0; j < s[i].size(); ++j) {
      if (mp.find(h.get_hash(0, j)) != mp.end()) {
        hav1[h.get_hash(j + 1, (int)s[i].size() - 1)] = 1;
      }
    }
    mp[h.get_hash(0, (int)s[i].size() - 1)] = 1;
  }
  vector<string> t(m);
  for (int i = 0; i < m; ++i) {
    cin >> t[i];
  }
  sort(t.begin(), t.end(), [&] (string x, string y) {
    return x.size() < y.size();
  });
  mp.clear();
  map<pair<long long, long long>, int> hav2;
  for (int i = 0; i < m; ++i) {
    Hash h;
    h.init(t[i], 114514191, 191981010);
    for (int j = 0; j < t[i].size(); ++j) {
      if (mp.find(h.get_hash(j, (int)t[i].size() - 1)) != mp.end()) {
        hav2[h.get_hash(0, j - 1)] = 1;   
      }      
    }
    mp[h.get_hash(0, (int)t[i].size() - 1)] = 1;
  }
  mp.clear();
  vector<bool> a(n);
  for (int i = 0; i < n; ++i) {
    Hash h;
    h.init(s[i], 114514191, 191981010);
    for (int j = 0; j < s[i].size(); ++j) {
      if (mp.find(h.get_hash(0, j)) != mp.end()) {
        if (hav2.find(h.get_hash(j + 1, (int)s[i].size() - 1)) != hav2.end()) {
          a[i] = true; 
          a[mp[h.get_hash(0, j)]] = true;
        }
      } 
    }
    mp[h.get_hash(0, (int)s[i].size() - 1)] = i;
  }
  mp.clear();
  vector<bool> b(m);
  for (int i = 0; i < m; ++i) {
    Hash h;
    h.init(t[i], 114514191, 191981010);
    for (int j = 0; j < t[i].size(); ++j) {
      if (mp.find(h.get_hash(j, (int)t[i].size() - 1)) != mp.end()) {
        if (hav1.find(h.get_hash(0, j - 1)) != hav1.end()) {
          b[i] = true; 
          b[mp[h.get_hash(j, (int)t[i].size() - 1)]] = true;
        }
      } 
    }
    mp[h.get_hash(0, (int)t[i].size() - 1)] = i;
  }
  cout << n - count(a.begin(), a.end(), true) << ' ' << m - count(b.begin(), b.end(), true) << '\n';
}
