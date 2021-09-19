#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> pre(n);
  auto bfs = [&] (int s) -> int {
    vector<int> dis(n, -1);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : adj[x]) {
        if (dis[y] == -1) {
          dis[y] = dis[x] + 1;
          pre[y] = x;
          q.push(y);
        }
      }
    }
    return max_element(dis.begin(), dis.end()) - dis.begin();
  };
  int s = bfs(0);
  int t = bfs(s);
  vector<int> path; 
  for (int i = t; i != s; i = pre[i]) {
    path.push_back(i);
  }
  path.push_back(s);
  reverse(path.begin(), path.end());
  vector<bool> vis(n);
  for (int i : path) {
    vis[i] = true;
  }
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      bool ok = false;
      for (int j : adj[i]) {
        if (vis[j]) {
          d[j]++;
          ok = true;
          break;
        }
      }
      if (!ok) {
        cout << -1 << '\n';
        exit(0);
      }
    }
  }
  int cur = 0;
  vector<int> p;
  for (int i : path) {
    for (int j = 0; j < d[i]; ++j) {
      p.push_back(cur + j + 1); 
    } 
    p.push_back(cur);
    cur += d[i] + 1;
  }
  reverse(path.begin(), path.end());
  cur = 0;
  vector<int> q;
  for (int i : path) {
    for (int j = 0; j < d[i]; ++j) {
      q.push_back(cur + j + 1);
    } 
    q.push_back(cur);
    cur += d[i] + 1;
  }
  if (p < q) {
    for (int i = 0; i < n; ++i) {
      cout << p[i] + 1 << " \n"[i == n - 1];
    }
  } else {
    for (int i = 0; i < n; ++i) {
      cout << q[i] + 1 << " \n"[i == n - 1];
    }
  }
}
