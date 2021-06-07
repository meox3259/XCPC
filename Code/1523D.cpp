#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int N, M, P;
  cin >> N >> M >> P;
  vector<string> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  vector<vector<int>> A(N, vector<int> (M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      A[i][j] = S[i][j] - '0';
    }
  }
  vector<long long> Val(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      Val[i] |= A[i][j] << j; 
    }
  }
  int ONE = 0;
  vector<int> Ans(M);
  for (int _ = 0; _ < 10; ++_) {
    int i = mt() % N;
    vector<int> one;
    for (int j = 0; j < M; ++j) {
      if (A[i][j] == 1) {
        one.push_back(j);
      }
    } 
    int K = one.size();
    vector<int> cnt(1 << K);
    for (int j = 0; j < N; ++j) {
      int ST = 0;
      for (int k = 0; k < K; ++k) {
        if (A[j][one[k]] == 1) {
          ST |= 1 << k;
        }
      }
      cnt[ST] ++;
    }
    for (int j = 0; j < K; ++j) {
      for (int k = 0; k < 1 << K; ++k) {
        if (!(k >> j & 1)) {
          cnt[k] += cnt[k | (1 << j)];
        }
      }
    }
    for (int V = 0; V < 1 << K; ++V) {
      if (cnt[V] >= (N + 1) / 2) {
        int BC = __builtin_popcount(V);
        if (BC > ONE) {
          ONE = BC;
          Ans.assign(M, 0);
          for (int j = 0; j < K; ++j) {
            if (V >> j & 1) {
              Ans[one[j]] = 1;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    cout << Ans[i];
  }
  cout << '\n';
}
