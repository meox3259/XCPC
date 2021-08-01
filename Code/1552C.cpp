#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    int N, K;
    cin >> N >> K;
    vector<int> X(K);
    vector<int> Y(K);
    for (int i = 0; i < K; ++i) {
      cin >> X[i] >> Y[i];
      X[i] --;
      Y[i] --;
      if (X[i] > Y[i]) {
        swap(X[i], Y[i]);
      }
    }
    int Ans = 0;
    Ans += (N - K) * (N - K - 1) / 2;
    for (int i = 0; i < K; ++i) {
      for (int j = i + 1; j < K; ++j) {
        if (((X[j] > Y[i] || X[j] < X[i]) && (X[i] < Y[j] && Y[j] < Y[i])) || ((Y[j] > Y[i] || Y[j] < X[i]) && (X[i] < X[j] && X[j] < Y[i]))) {
          Ans ++;
        }
      }
    }
    vector<bool> mark(N + N);
    for (int i = 0; i < K; ++i) {
      mark[X[i]] = true;
      mark[Y[i]] = true;
    }
    for (int i = 0; i < K; ++i) {
      int A = 0;
      for (int j = X[i] + 1; j < (Y[i] < X[i] ? Y[i] + N + N : Y[i]); ++j) {
        if (!mark[j % (N + N)]) {
          A ++;
        }    
      }
      int B = 0;
      for (int j = Y[i] + 1; j < (X[i] < Y[i] ? X[i] + N + N : X[i]); ++j) {
        if (!mark[j % (N + N)]) {
          B ++;
        }
      }
      Ans += min(A, B);
    }
    cout << Ans << '\n';
  }
}
