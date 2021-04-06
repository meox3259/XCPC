#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  vector<bool> vis(N);
  vector<tuple<int, int, int>> Ans;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < N; ++i) {
    if (!vis[i]) {
      auto dfs = [&] (auto &&f, int X, int Par) -> int {
        vector<int> cities;
        vis[X] = true;
        for (int Y : adj[X]) {
          if (Y != Par) {
            if (!vis[Y]) {
              int Z = f(f, Y, X);
              if (Z == -1) {
                cities.push_back(Y);
              } else {
                mp[minmax(Z, Y)] = true;
                mp[minmax(Y, X)] = true;
                Ans.emplace_back(Z, Y, X);
              }
            } else {
              if (mp.find(minmax(X, Y)) == mp.end()) {
                cities.push_back(Y);
              }
            }
          }
        }
        while (cities.size() >= 2) {
          int A = cities.back();
          cities.pop_back();
          int B = cities.back();
          cities.pop_back();
          Ans.emplace_back(A, X, B);
          mp[minmax(A, X)] = true;
          mp[minmax(X, B)] = true;
        }
        if (!cities.empty()) {
           return cities[0];
        } else {
          return -1;
        }
      };
      dfs(dfs, i, -1);
    }
  }
  cout << Ans.size() << '\n';
  for (auto [X, Y, Z] : Ans) {
    cout << X + 1 << ' ' << Y + 1 << ' ' << Z + 1 << '\n';
  }
}
