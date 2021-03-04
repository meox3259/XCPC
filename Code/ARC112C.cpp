#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    int p;
    cin >> p;
    p --;
    adj[p].push_back(i);
  }
  vector<int> f(N, 1);
  vector<int> sz(N, 1);
  auto dfs = [&] (auto &&ff, int x) -> void {
    int sum = 0;
    vector<int> seq;
    for (int y : adj[x]) {
      ff(ff, y);
      sz[x] += sz[y];
      if (sz[y] % 2 == 1) {
        seq.push_back(-f[y]); 
      } else {
        if (f[y] < 0) {
          f[x] += f[y];
        } else {
          sum -= f[y]; 
        }
      }
    }
    sort(seq.begin(), seq.end(), greater<int> ());
    seq.push_back(sum);
    for (int i = 0; i < seq.size(); ++i) {
      if (i % 2 == 1) {
        f[x] += seq[i];   
      } else {
        f[x] -= seq[i];
      }
    }
  };
  dfs(dfs, 0);
  cout << (N + f[0]) / 2 << '\n';
  return 0;
}
