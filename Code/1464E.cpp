#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long modpow(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      ret = ret * x % mod;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x --;
    y --;
    adj[x].push_back(y);
    d[y]++;
  }
  vector<int> q;
  for (int i = 0; i < n; ++i) {
    if (d[i] == 0) {
      q.push_back(i);
    } 
  }
  for (int i = 0; i < n; ++i) {
    int x = q[i];
    for (int y : adj[x]) {
      if (--d[y] == 0) {
        q.push_back(y);
      }
    }
  }
  vector<int> sg(n);
  for (int i = n - 1; i >= 0; --i) {
    int x = q[i];
    vector<int> cnt(adj[x].size() + 1);
    for (int y : adj[x]) {
      if (sg[y] < adj[x].size()) {
        cnt[sg[y]] ++;
      }
    }
    while (cnt[sg[x]]) {
      sg[x] ++;
    }
  }
  int k = 512;
  vector<vector<long long>> g(k, vector<long long> (k + 1));
  for (int i = 0; i < k; ++i) {
    g[i][i] = 1;
  }
  long long p = modpow(n + 1, mod - 2);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      g[i][i ^ sg[j]] -= p;
      g[i][i ^ sg[j]] += mod;
      g[i][i ^ sg[j]] %= mod;
    }
  }
  g[0][k] = p;
  for (int i = 0; i < k; ++i) {
    int pivot = i;
    for (int j = i; j < k; ++j) {
      if (g[j][i] > g[pivot][i]) {
        pivot = j;
      }
    }
    swap(g[i], g[pivot]);
    long long v = modpow(g[i][i], mod - 2);
    for (int j = 0; j <= k; ++j) {
      g[i][j] *= v;
      g[i][j] %= mod;
    }
    for (int j = 0; j < k; ++j) {
      if (j != i) {
        long long v = g[j][i];
        for (int l = 0; l <= k; ++l) {
          g[j][l] -= v * g[i][l];
          g[j][l] %= mod;
          if (g[j][l] < 0) {
            g[j][l] += mod;
          }
        }
      }
    }
  }
  cout << (1 + mod - g[0][k]) % mod << '\n';
}
