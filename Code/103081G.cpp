#include <bits/stdc++.h>
using namespace std;
const long long inf = numeric_limits<long long> :: max() / 2;
class scc {
  vector<vector<int>> adj;
  vector<vector<int>> rev;
  vector<int> scc_;
  vector<int> vs;
  vector<bool> vis;
  int n;
  int components_;
 public:
  scc() {}
  scc(int _n) : n(_n), scc_(_n), adj(_n), rev(_n), vis(_n), components_(0) {}
  void add_edge(int x, int y) {
    adj[x].push_back(y);
    rev[y].push_back(x);
  }
  void build() {
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        dfs(i);
      }
    }
    vis.assign(n, false);
    reverse(vs.begin(), vs.end());
    for (int i : vs) {
      if (!vis[i]) {
        dfs(i, components_++);
      }
    }
  }
  void dfs(int x) {
    vis[x] = true;
    for (int y : adj[x]) {
      if (!vis[y]) {
        dfs(y);
      }
    }
    vs.push_back(x);
  }
  void dfs(int x, int cnt) {
    vis[x] = true;
    scc_[x] = cnt;
    for (int y : rev[x]) {
      if (!vis[y]) {
        dfs(y, cnt);
      }
    }
  }
  int operator [] (int x) {
    return scc_[x];
  }
  int components() {
    return components_;
  }
};
int main() {
  int n, k; 
  cin >> n >> k;
  vector<int> divisors(n);
  for (int i = 1; i < n; ++i) {
    for (int j = i; j < n; j += i) {
      divisors[j] ++;
    } 
  }
  vector<int> to(n);
  scc scc(n);
  for (int i = 1; i < n; ++i) {
    scc.add_edge(i, (i + divisors[i]) % n);
    to[i] = (i + divisors[i]) % n;
  }
  scc.build();
  vector<vector<int>> step(n, vector<int> (22));
  vector<vector<long long>> sum(n, vector<long long> (22));
  for (int i = 0; i < n; ++i) {
    step[i][0] = to[i];
    sum[i][0] = i;
  }
  for (int j = 0; j < 21; ++j) {
    for (int i = 0; i < n; ++i) {
      step[i][j + 1] = step[step[i][j]][j];
      sum[i][j + 1] = sum[i][j] + sum[step[i][j]][j];
    }
  }
  int m = scc.components();
  vector<int> sz(m);
  for (int i = 0; i < n; ++i) {
    sz[scc[i]] ++;
  }
  vector<int> in(m);
  vector<vector<int>> adj(m);
  for (int i = 1; i < n; ++i) {
    int j = (i + divisors[i]) % n;
    if (scc[j] != scc[i]) {
      adj[scc[j]].push_back(scc[i]);
      in[scc[i]] ++;
    }
  }
  vector<int> dp(m);
  queue<int> q;
  for (int i = 0; i < m; ++i) {
    if (in[i] == 0) {
      q.push(i);
      dp[i] = sz[i];
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int y : adj[x]) {
      dp[y] = max(dp[y], dp[x] + sz[y]);
      if (! --in[y]) {
        q.push(y);
      }
    }
  }
  int s = -1;
  long long ans = inf;
  for (int i = 0; i < n; ++i) {
    if (dp[scc[i]] >= k) {
      long long tmp = 0;
      int x = i;
      for (int j = 20; j >= 0; --j) {
        if (k >> j & 1) {
          tmp += sum[x][j];
          x = step[x][j];
        }
      }
      if (tmp < ans) {
        s = i;
        ans = tmp;
      }
    }
  }
  if (s == -1) {
    cout << -1 << '\n';
    exit(0);
  }
  for (int i = 0; i < k; ++i) {
    cout << s << " \n"[i == k - 1];
    s = to[s];
  }
}
