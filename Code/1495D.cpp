#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int main() {
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
  vector<vector<int>> dis(N, vector<int> (N, -1));
  for (int S = 0; S < N; ++S) {
    dis[S][S] = 1;
    queue<int> Q;
    Q.push(S);
    while (!Q.empty()) {
      int X = Q.front();
      Q.pop();
      for (int Y : adj[X]) {
        if (dis[S][Y] == -1) {
          dis[S][Y] = dis[S][X] + 1;
          Q.push(Y);
        }
      }
    }
  }
  vector<vector<long long>> ans(N, vector<long long> (N, 1));
  for (int X = 0; X < N; ++X) {
    for (int Y = X; Y < N; ++Y) {
      int cnt = 0;
      for (int i = 0; i < N; ++i) {
        if(dis[X][i] + dis[Y][i] - 1 == dis[X][Y]) {
          cnt ++;
        } 
      } 
      if (cnt > dis[X][Y]) {
        ans[X][Y] = ans[Y][X] = 0;
      } else {
        for (int i = 0; i < N; ++i) {
          if (dis[X][i] + dis[Y][i] - 1 != dis[X][Y]) {
            int Mul = 0;
            for (int j : adj[i]) {
              if (dis[X][j] + 1 == dis[X][i] && dis[Y][j] + 1 == dis[Y][i]) {
                Mul ++;
              } 
            } 
            if (X != Y) {
              ans[X][Y] = ans[X][Y] * Mul % P;
              ans[Y][X] = ans[Y][X] * Mul % P;
            } else {
              ans[X][Y] = ans[X][Y] * Mul % P;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << ans[i][j] << " \n"[j == N - 1];
    }
  }
  return 0;
}
