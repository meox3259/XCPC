#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x --;
    y --;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> d(n, -1);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int y : adj[x]) {
      if (d[y] == -1) {
        d[y] = d[x] + 1;
        q.push(y);
      }
    }
  }
  if (count(d.begin(), d.end(), -1) > 0) {
    cout << -1 << '\n';
    exit(0);
  }
  int mx = *max_element(d.begin(), d.end());
  int k = 0;
  while ((1 << k) < mx) {
    k ++;
  }
  cout << k + 1 << '\n';
}
