#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long> :: max() / 2;
int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  long long Ans = INF;
  for (int i = 0; i <= N; ++i) {
    vector<long long> B(A);
    for (int j = 0; j < i; ++j) {
      B.push_back(0);
    }
    sort(B.begin(), B.end());
    long long Max = -INF;
    long long Min = INF;
    deque<long long> Q;
    for (auto V : B) {
      Q.push_back(V);
    }
    while (Q.size() >= 2) {
      long long X = Q.front();
      Q.pop_front();
      long long Y = Q.back();
      Q.pop_back();
      Max = max(Max, X + Y);
      Min = min(Min, X + Y);
    }
    if (!Q.empty()) {
      Max = max(Max, Q.front());
      Min = min(Min, Q.front());
    }
    Ans = min(Ans, Max - Min);
  }
  cout << Ans << '\n';
}
