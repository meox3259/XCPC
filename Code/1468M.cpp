#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> k(n);
    vector<vector<int>> a(n);
    map<int, int> mp;
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      cin >> k[i];
      for (int j = 0; j < k[i]; ++j) {
        int x;
        cin >> x;
        if (mp.find(x) == mp.end()) {
          mp[x] = tot++;
        }
        a[i].push_back(mp[x]);
      }
      sort(a[i].begin(), a[i].end());
    }
    int m = mp.size();
    vector<vector<int>> adj(m);
    for (int i = 0; i < n; ++i) {
      for (int j : a[i]) {
        adj[j].push_back(i);
      }
    }
    vector<int> last(m, -1);
    vector<int> pos(m, -1);
    bool ok = false;
    for (int i = 0; i < m; ++i) {
      for (int j : adj[i]) {
        if (a[j].size() < 400) {
          for (int x : a[j]) {
            if (x >= i) {
              break;
            }
            if (!ok && last[x] == i) {
              cout << pos[x] + 1 << ' ' << j + 1 << '\n';
              ok = true;
              break;
            }
            last[x] = i;
            pos[x] = j; 
          } 
        } 
      }
    }
    if (ok) {
      continue;
    }
    vector<int> f(m);
    for (int i = 0; i < n; ++i) {
      if (a[i].size() >= 400) {
        for (int j : a[i]) {
          f[j] = 1;
        }
        for (int j = 0; j < n; ++j) {
          if (i != j) {
            int cnt = 0;
            for (int k : a[j]) {
              cnt += f[k];
            } 
            if (!ok && cnt >= 2) {
              cout << i + 1 << ' ' << j + 1 << '\n';
              ok = true;
              break;
            }
          } 
        }
        for (int j : a[i]) {
          f[j] = 0;
        }
      } 
    }
    if (!ok) {
      cout << -1 << '\n';
    }
  }
}
