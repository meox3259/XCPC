#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
    X[i] --;
  }
  vector<int> P(N * N, -1);
  for (int i = 0; i < N; ++i) {
    P[X[i]] = i;
  }
  set<int> S;
  vector<int> Ans(N * N);
  for (int i = 0; i < N * N; ++i) {
    if (P[i] != -1) {
      if (S.size() < P[i]) {
        cout << "No" << '\n';
        exit(0);
      } 
      Ans[i] = P[i];
      for (int j = 0; j < P[i]; ++j) {
        Ans[*S.begin()] = P[i];
        S.erase(S.begin());
      }
    } else {
      S.insert(i);
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - 1 - i; ++j) {
      auto itr = S.lower_bound(X[i]);
      if (itr == S.end()) {
        cout << "No" << '\n';
        exit(0);
      } else {
        Ans[*itr] = i;
        S.erase(itr);
      }
    } 
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < N * N; ++i) {
    cout << Ans[i] + 1 << " \n"[i == N * N - 1];
  }
}
