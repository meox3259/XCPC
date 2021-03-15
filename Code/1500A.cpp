#include <bits/stdc++.h>
using namespace std;
const int M = 5000005;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<vector<pair<int, int>>> P(M);
  vector<vector<int>> V(M);
  for (int i = 0; i < N; ++i) {
    V[A[i]].push_back(i);
  }
  vector<int> S;
  for (int i : A) {
    S.push_back(i);
  }
  sort(S.begin(), S.end());
  S.erase(unique(S.begin(), S.end()), S.end());
  for (int i = 0; i < S.size(); ++i) {
    if (V[S[i]].size() >= 4) {
      cout << "YES" << '\n';
      for (int j = 0; j < 4; ++j) {
        cout << V[S[i]][j] + 1 << " \n"[j == 3];
      }
      exit(0);
    }
    if (P[S[i] + S[i]].size() >= 1 && V[S[i]].size() >= 2) {
      cout << "YES" << '\n';
      cout << P[S[i] + S[i]][0].first + 1 << ' ' << P[S[i] + S[i]][0].second + 1 << ' ' << V[S[i]][0] + 1 << ' ' << V[S[i]][1] + 1 << '\n';
      exit(0);
    }
    for (int j = i + 1; j < S.size(); ++j) {
      if (P[S[i] + S[j]].size() >= 1) {
        cout << "YES" << '\n';
        cout << V[S[i]][0] + 1 << ' ' << V[S[j]][0] + 1 << ' ' 
             << P[S[i] + S[j]][0].first + 1 << ' ' << P[S[i] + S[j]][0].second + 1 << '\n';
        exit(0);
      }
      if (V[S[i]].size() >= 2 && V[S[j]].size() >= 2) {
        cout << "YES" << '\n';
        cout << V[S[i]][0] + 1 << ' ' << V[S[j]][0] + 1 << ' ' << V[S[i]][1] + 1 << ' ' << V[S[j]][1] + 1 << '\n';
        exit(0);
      } 
      P[S[i] + S[j]].emplace_back(V[S[i]][0], V[S[j]][0]);
    }
  }
  cout << "NO" << '\n';
  return 0;
}
