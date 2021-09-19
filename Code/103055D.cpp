#include <bits/stdc++.h>
using namespace std;
const long long inf = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].emplace_back(y, w);
    adj[y].emplace_back(x, w);
  }
  vector<int> dep(n + 1);
  dep[0] = -1;
  for (int i = 1; i <= n; ++i) {
    dep[i] = dep[i / 2] + 1;
  }
  vector<vector<long long>> dis(n + 1, vector<long long> (20, inf));
  for (int s = 1; s <= n; ++s) {
    priority_queue<pair<long long, int>> q;
    dis[s][dep[s]] = 0;
    q.emplace(0, s);
    while (!q.empty()) {
      auto [d, x] = q.top(); 
      q.pop();
      d = -d;
      if (dis[x][dep[s]] < d) {
        continue;
      }
      for (auto [y, w] : adj[x]) {
        if (dep[y] >= dep[s] && dis[y][dep[s]] > d + w) {
          dis[y][dep[s]] = d + w;
          q.emplace(-dis[y][dep[s]], y);
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int s, t;
    cin >> s >> t;
    int x = s;
    int y = t;
    while (x != y) {
      if (dep[x] < dep[y]) {
        swap(x, y);
      }
      x >>= 1;
    }
    long long ans = inf;
    while (x) {
      ans = min(ans, dis[s][dep[x]] + dis[t][dep[x]]);
      x >>= 1;
    }
    if (ans == inf) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}
