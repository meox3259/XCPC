#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<long long>> d(N, vector<long long> (N, Inf));
  vector<vector<long long>> E(N, vector<long long> (N, Inf));
  for (int i = 0; i < M; ++i) {
    int X, Y, W;
    cin >> X >> Y >> W;
    X --;
    Y --;
    d[X][Y] = d[Y][X] = W;
    E[X][Y] = E[Y][X] = W;
  }
  for (int i = 0; i < N; ++i) {
    d[i][i] = 0;
  }
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int Q;
  cin >> Q;
  vector<tuple<int, int, int>> q(Q);
  for (auto &[X, Y, W] : q) {
    cin >> X >> Y >> W;
    X --;
    Y --;
  }
  vector<vector<bool>> ok(N, vector<bool> (N));
  for (int i = 0; i < N; ++i) {
    vector<long long> MaxV(N, -Inf);
    for (auto [X, Y, W] : q) {
      MaxV[Y] = max(MaxV[Y], W - d[X][i]); 
    }
    for (int j = 0; j < N; ++j) {
      if (E[i][j] != Inf && !ok[i][j]) {
        for (int k = 0; k < N; ++k) {
          if (E[i][j] + d[j][k] <= MaxV[k]) {
            ok[i][j] = ok[j][i] = true;
          } 
        } 
      }
    } 
  }
  int Ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (ok[i][j]) {
        Ans ++;
      }
    }
  }
  cout << Ans << '\n';
}
