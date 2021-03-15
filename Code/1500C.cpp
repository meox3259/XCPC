#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int> (M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> B(N, vector<int> (M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> B[i][j];
    }
  }
  vector<vector<int>> adj(N);
  vector<int> deg(M);
  for (int j = 0; j < M; ++j) {
    for (int i = 0; i < N - 1; ++i) {
      if (B[i][j] > B[i + 1][j]) {
        adj[i].push_back(j);
        deg[j] ++;
      }
    }
  }
  vector<int> node;
  for (int i = 0; i < M; ++i) {
    if (deg[i] == 0) {
      node.push_back(i);
    }
  }
  vector<bool> ok(N);
  for (int i = 0; i < node.size(); ++i) {
    int c = node[i];
    for (int j = 0; j < N - 1; ++j) {
      if (!ok[j] && B[j][c] < B[j + 1][c]) {
        ok[j] = true; 
        for (int k : adj[j]) {
          if (! --deg[k]) {
            node.push_back(k);
          }
        }
      }
    }
  }
  reverse(node.begin(), node.end());
  vector<int> P(N);
  iota(P.begin(), P.end(), 0);
  for (int i : node) {
    stable_sort(P.begin(), P.end(), [&] (int X, int Y) {
      return A[X][i] < A[Y][i];
    });
  }
  for (int i = 0; i < N; ++i) {
    if (A[P[i]] != B[i]) {
      cout << -1 << '\n';
      exit(0);
    }
  }
  cout << node.size() << '\n';
  for (int i = 0; i < node.size(); ++i) {
    cout << node[i] + 1 << " \n"[i + 1 == node.size()];
  }
  return 0;
}
