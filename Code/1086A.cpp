#include <bits/stdc++.h>
using namespace std;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
int main() {
  vector<pair<int, int>> P(3);
  for (int i = 0; i < 3; ++i) {
    cin >> P[i].first >> P[i].second;
  }
  sort(P.begin(), P.end());
  vector<int> X(3);
  vector<int> Y(3);
  for (int i = 0; i < 3; ++i) {
    X[i] = P[i].first;
    Y[i] = P[i].second;
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  vector<pair<int, int>> ans;
  auto solve = [&] (int SX, int SY, int TX, int TY) -> void {
    queue<pair<int, int>> Q; 
    Q.emplace(SX, SY);
    while (!Q.empty()) {
      auto [X, Y] = Q.front();
      Q.pop();
      ans.emplace_back(X, Y);
      if (X == TX && Y == TY) {
        break;
      }
      int D = abs(X - TX) + abs(Y - TY);
      for (int i = 0; i < 4; ++i) {
        int DX = X + dx[i];
        int DY = Y + dy[i];
        int CurD = abs(DX - TX) + abs(DY - TY);
        if (CurD < D) {
          Q.emplace(DX, DY);
          break;
        }
      }
    }
  };
  for (int i = 0; i < 3; ++i) {
    solve(P[i].first, P[i].second, X[1], Y[1]);
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
