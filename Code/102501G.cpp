#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, l, n;
  cin >> m >> l >> n;
  vector<string> s(m);
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  map<string, int> mp;
  for (int i = 0; i < m; ++i) {
    mp[s[i]] = i;
  }
  vector<string> a(l);
  vector<string> b(l);
  vector<vector<bool>> mark(m, vector<bool> (m));
  for (int i = 0; i < l; ++i) {
    cin >> a[i] >> b[i];
    mark[mp[a[i]]][mp[b[i]]] = true; 
    mark[mp[b[i]]][mp[a[i]]] = true;
  }
  vector<string> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i]; 
  }
  vector<int> id(n);
  for (int i = 0; i < n; ++i) {
    id[i] = mp[t[i]];
  }
  vector<int> lst(m, -1);
  vector<int> d(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (lst[j] != -1 && !mark[id[i]][j]) {
        d[i]++;
        adj[lst[j]].push_back(i);
      }
    }
    lst[id[i]] = i;
  }
  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    if (!d[i]) {
      q.emplace(-id[i], i);
    }
  }
  vector<int> ans;
  while (!q.empty()) {
    auto [v, x] = q.top();
    q.pop();
    ans.push_back(-v);
    for (int y : adj[x]) {
      if (!--d[y]) {
        q.emplace(-id[y], y);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << s[ans[i]] << " \n"[i == n - 1];
  }
}
