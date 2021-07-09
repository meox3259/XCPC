#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<bool> vis(N);
  vector<long long> Ans;
  for (int i = 0; i < N; ++i) {
    bool ok = false;
    for (int j = 0; j < N; ++j) {
      if (!vis[j]) {
        long long V = A[j]; 
        long long G = 1;
        for (int k = 0; k < N; ++k) {
          if (k != j && !vis[k]) {
            long long X = __gcd(V, A[k]);
            G = G / __gcd(G, X) * X;
          }
        }
        if (V != G) {
          ok = true;
          Ans.push_back(A[j]);
          vis[j] = true;
          break;
        }
      }
    } 
    if (!ok) {
      cout << "No" << '\n';
      exit(0);
    }
  }
  reverse(Ans.begin(), Ans.end());
  cout << "Yes" << '\n';
  for (int i = 0; i < N; ++i) {
    cout << Ans[i] << " \n"[i == N - 1];
  }
}
