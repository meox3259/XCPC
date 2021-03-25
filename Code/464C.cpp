#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
int main() {
  string S;
  cin >> S;
  int N;
  cin >> N;
  vector<int> B(N);
  vector<vector<int>> A(N);
  vector<int> Len(N);
  for (int i = 0; i < N; ++i) {
    string X;
    cin >> X;
    int M = X.size();
    B[i] = X[0] - '0';
    string T = X.substr(3, M - 3);
    A[i].resize(T.size());
    Len[i] = T.size();
    for (int j = 0; j < T.size(); ++j) {
      A[i][j] = T[j] - '0';
    }
  }
  vector<long long> Last(10);
  vector<long long> ten(10, 10);
  iota(Last.begin(), Last.end(), 0);
  for (int i = N - 1; i >= 0; --i) {
    long long Pw = 1;
    long long S = 0;
    for (int j = 0; j < Len[i]; ++j) {
      Pw = Pw * ten[A[i][j]] % P;
      S = (S * ten[A[i][j]] + Last[A[i][j]]) % P;
    }
    ten[B[i]] = Pw;
    Last[B[i]] = S;
  }
  long long Ans = 0;
  for (char C : S) {
    Ans = (Ans * ten[C - '0'] + Last[C - '0']) % P;
  }
  cout << Ans << '\n';
}
