#include <bits/stdc++.h>
using namespace std;
#define ALL(A) A.begin(), A.end()
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  vector<pair<long long, int>> P;
  for (int i = 0; i < N; ++i) {
    P.emplace_back(S[i], i);
  }
  vector<long long> T(N);
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
  }
  sort(ALL(S));
  sort(ALL(P));
  sort(ALL(T));
  vector<tuple<int, int, long long>> ans;
  vector<pair<int, long long>> st;
  for (int i = 0; i < N; ++i) {
    long long D = S[i] - T[i]; 
    int k = P[i].second;
    if (D < 0) {
      st.emplace_back(k, -D);
    } else {
      while (D > 0) {
        if (st.empty()) {
          cout << "NO" << '\n';
          exit(0);
        }
        auto& [j, M] = st.back();
        long long X = min(M, D);
        M -= X;
        D -= X;
        if (M == 0) {
          st.pop_back();
        }
        ans.emplace_back(j, k, X);
      } 
    }
  }
  if (!st.empty()) {
    cout << "NO" << '\n';
    exit(0);
  }
  cout << "YES" << '\n';
  cout << ans.size() << '\n';
  for (auto [i, j, D] : ans) {
    cout << i + 1 << ' ' << j + 1 << ' ' << D << '\n';
  }
  return 0;
}
