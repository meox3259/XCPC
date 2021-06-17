#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<long long>> dis(N, vector<long long> (N, Inf));
  for (int i = 0; i < M; ++i) {
    int A, B;
    long long C;
    cin >> A >> B >> C;
    for (int j = 0; j < N; ++j) {
      dis[A][(B + j) % N] = min(dis[A][(B + j) % N], C + j);
    }
  }
  vector<vector<long long>> d(N, vector<long long> (N, Inf));
  for (int S = 0; S < N; ++S) {
    d[S][S] = 0;
    vector<bool> vis(N);
    for (int i = 0; i < N; ++i) {
      int P = -1;
      for (int j = 0; j < N; ++j) {
        if (!vis[j] && (P == -1 || d[S][j] < d[S][P])) {
          P = j;
        } 
      }
      vis[P] = true;
      int D = d[S][P] % N;
      for (int j = 0; j < N; ++j) {
        d[S][(D + j) % N] = min(d[S][(D + j) % N], d[S][P] + dis[P][j]);
      } 
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << d[i][j] << " \n"[j == N - 1];
    }
  }
}
