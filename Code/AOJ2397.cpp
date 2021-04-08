#include <bits/stdc++.h>
using namespace std;
const int Mod = 1'000'000'009;
class Matrix {
 public:
  int N;
  vector<vector<long long>> M;
  Matrix() {}
  Matrix(int _N) : N(_N), M(_N, vector<long long> (_N)) {}
  void set() {
    for (int i = 0; i < N; ++i) {
      M[i][i] = 1;
    }
  }
  friend Matrix operator * (const Matrix &A, const Matrix &B) {
    Matrix ret(A.N);
    int N = A.N;
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          ret.M[i][j] += A.M[i][k] * B.M[k][j] % Mod; 
          ret.M[i][j] %= Mod;
        }
      }
    }
    return ret;
  }
};
Matrix power(Matrix A, long long T) {
  Matrix ret(A.N);
  ret.set();
  for (; T; T >>= 1, A = A * A) {
    if (T & 1) {
      ret = ret * A;
    }
  }
  return ret;
}
int main() {
  long long W, H;
  int N, T = 0;
  while (cin >> W >> H >> N) {
    if (N == 0 && H == 0 && N == 0) {
      break; 
    }     
    vector<pair<long long, long long>> P;
    for (int i = 0; i < N; ++i) {
      long long X, Y;
      cin >> X >> Y;
      P.emplace_back(X - 1, Y - 1);
    }
    Matrix dp(W); 
    dp.M[0][0] = 1;   
    Matrix G(W);
    for (int i = 0; i < W; ++i) {
      for (int j = 0; j < W; ++j) {
        if (abs(i - j) <= 1) {
          G.M[i][j] = 1;
        }
      }
    }
    vector<long long> S;
    for (auto [X, Y] : P) {
      S.push_back(Y);
    }
    S.push_back(H - 1);
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    map<long long, vector<int>> mp;
    for (auto [X, Y] : P) {
      mp[Y].push_back(X); 
    }
    long long last = 0;
    for (int i = 0; i < S.size(); ++i) {
      if (S[i] == 0) {
        continue;
      }
      if (S[i] != last) {
        Matrix Move = power(G, S[i] - last - 1);  
        dp = dp * Move;
        Matrix Ndp(W);
        vector<bool> mark(W);
        for (int j = 0; j < W; ++j) {
          for (int k = 0; k < W; ++k) {
            if (abs(j - k) <= 1) {
              Ndp.M[0][j] += dp.M[0][k];
              Ndp.M[0][j] %= Mod;
            }
          }
        }
        for (int j : mp[S[i]]) {
          Ndp.M[0][j] = 0;
        }
        swap(dp, Ndp);
        last = S[i];
      }
    }
    T ++;
    cout << "Case " << T << ':' << ' ' << dp.M[0][W - 1] << '\n';
  }
}
