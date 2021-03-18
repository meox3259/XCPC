#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> c(N);
  for (int i = 0; i < N; ++i) {
    cin >> c[i];
  }
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  vector<int> Top(N);
  vector<bool> Need(N);
  vector<int> Next(N, -1);
  auto dfs = [&] (auto &&f, int X, int Par) -> long long {
    long long ret = 0;
    int Max = -1;
    bool same = false;
    for (int Y : adj[X]) {
      if (Y != Par) {
        ret += f(f, Y, X);
        if (Max < Top[Y]) {
          Max = Top[Y];
          same = false;
        } else if (Max == Top[Y]) {
          same = true;
        }
      }
    }
    if (Max != -1) {
      for (int Y : adj[X]) {
        if (Y != Par) {
          if (same || Top[Y] < Max) {
            Need[Y] = true;
          } else {
            Next[X] = Y;
          }
        }
      }
      Top[X] = min(c[X], Max);
      ret -= Max;
    } else {
      Top[X] = c[X];
    }
    return ret + Top[X];
  };  
  long long Min = dfs(dfs, 0, -1);
  vector<int> ans;
  Need[0] = true;
  for (int i = 0; i < N; ++i) {
    if (Need[i]) {
      for (int j = i; j != -1; j = Next[j]) {
        if (Top[i] == c[j]) {
          ans.push_back(j);
        }
      } 
    }
  }
  sort(ans.begin(), ans.end());
  cout << Min << ' ' << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
  }
}
