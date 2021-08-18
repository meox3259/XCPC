#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x --;
    y --;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<vector<int>> dep(n, vector<int> (2));
  vector<int> sz(n);
  auto pre = [&] (auto &&f, int x, int fa) -> void {
    dep[x][0] = 1;
    sz[x] = 1;
    for (int y : adj[x]) {
      if (y != fa) {
        f(f, y, x);
        dep[x][0] += dep[y][1];
        dep[x][1] += dep[y][0];
        sz[x] += sz[y];
      }
    }
  };
  pre(pre, 0, -1);
  long long ans = accumulate(v.begin(), v.end(), 0LL);
  ans %= P;
  ans += P;
  ans %= P;
  auto dfs = [&] (auto &&f, int x, int fa, int x0, int x1) -> void {
    int t0 = x1;
    int t1 = x0 + 1;
    for (int y : adj[x]) {
      if (y != fa) {
        t0 += dep[y][0];
        t1 += dep[y][1];
      }
    }
    for (int y : adj[x]) {
      if (y != fa) {
        int y0 = t0 - dep[y][0];
        int y1 = t1 - dep[y][1];
        f(f, y, x, y0, y1);
      }
    }
    ans += v[x] * (n - 1);
    ans %= P;
    for (int y : adj[x]) {
      if (y != fa) {
        ans += v[x] * dep[y][1] % P * (n - sz[y]); 
        ans %= P;
        ans -= v[x] * dep[y][0] % P * (n - sz[y]); 
        ans %= P;
        ans += P;
        ans %= P;
      }
    }
    ans += v[x] * x0 % P * (n - x0 - x1);
    ans %= P;
    ans -= v[x] * x1 % P * (n - x0 - x1);
    ans %= P;
    ans += P;
    ans %= P;
  };
  dfs(dfs, 0, -1, 0, 0);
  cout << ans << '\n';
}
