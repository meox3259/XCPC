#include <bits/stdc++.h>
using namespace std;
int power(int X, int T, int P) {
  int ret = 1;
  for (; T; T >>= 1, X = 1LL * X * X % P) {
    if (T & 1) {
      ret = 1LL * ret * X % P;
    }
  }
  return ret;
}
int inv(int X, int P) {
  return power(X, P - 2, P);
}
int main() {
  int P, A, B;
  cin >> P >> A >> B;
  vector<bool> vis(P);
  int X = 1;
  int N = 0;
  while (!vis[X]) {
    N ++;
    vis[X] = true;
    X = 1LL * X * A % P;
  }
  int M = 1;
  int Y = B;
  while (!vis[Y]) {
    M ++;
    Y = 1LL * Y * B % P; 
  }
  if (1LL * N * M != P - 1) {
    cout << "No" << '\n';
    exit(0);
  }
  if (N % 2 == 1) {
    swap(N, M);
    swap(A, B);
  }
  int V = 1;
  cout << "Yes" << '\n';
  vector<int> Ans;
  for (int i = 0; i < N; ++i) {
    Ans.push_back(V);
    if (i != N - 1) {
      V = 1LL * V * A % P;
    }
  }
  V = 1LL * V * B % P;
  int iA = inv(A, P);
  int iB = inv(B, P);
  for (int i = N - 1; i >= 0; i -= 2) {
    for (int j = 1; j < M; ++j) {
      Ans.push_back(V);
      if (j != M - 1) {
        V = 1LL * V * B % P;
      }
    }
    V = 1LL * V * iA % P;
    for (int j = M - 1; j >= 1; --j) {
      Ans.push_back(V);
      if (j != 1) {
        V = 1LL * V * iB % P;
      }
    }
    V = 1LL * V * iA % P;
  }
  Ans.push_back(1);
  for (int i = 0; i < P; ++i) {
    cout << Ans[i] << " \n"[i == P - 1];
  }
}
