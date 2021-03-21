#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<long long> L(N);
  vector<long long> R(N);
  for (int i = 0; i < N; ++i) {
    cin >> L[i] >> R[i];
  }
  vector<long long> A(M);
  for (int i = 0; i < M; ++i) {
    cin >> A[i];
  }
  vector<tuple<long long, long long, int>> P;
  for (int i = 0; i < N - 1; ++i) {
    P.emplace_back(L[i + 1] - R[i], R[i + 1] - L[i], i);
  }
  sort(P.begin(), P.end(), [&] (const tuple<long long, long long, int> &X, const tuple<long long, long long, int> &Y) {
    return get<1>(X) < get<1>(Y);
  });
  vector<pair<long long, int>> Q;
  for (int i = 0; i < M; ++i) {
    Q.emplace_back(A[i], i);
  }
  sort(Q.begin(), Q.end());
  int j = 0;
  multiset<pair<long long, int>> S;
  vector<int> B(N - 1);
  for (auto [X, Y, i] : P) {
    while (j < M && Q[j].first <= Y) {
      S.insert(Q[j]); 
      j ++;
    } 
    auto itr = S.lower_bound({X, -1});
    if (itr == S.end()) {
      cout << "No" << '\n';
      exit(0);
    }
    B[i] = itr -> second;
    S.erase(itr);
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < N - 1; ++i) {
    cout << B[i] + 1 << " \n"[i == N - 2];
  }
}
