#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long> :: max() / 3;
class sgt {
  vector<long long> Max;
 public:
  sgt() {}
  sgt(int N) : Max(N * 4 + 5, -INF) {}
  void update(int L, int R, int X, int P, long long V) {
    if (L == R) {
      Max[X] = V;
      return;
    }
    int Mid = L + R >> 1;
    if (P <= Mid) {
      update(L, Mid, X << 1, P, V);
    } else {
      update(Mid + 1, R, X << 1 | 1, P, V);
    }
    Max[X] = max(Max[X << 1], Max[X << 1 | 1]);
  }
  long long query(int L, int R, int X, int A, int B) {
    if (L > B || R < A) {
      return -INF;
    }
    if (L >= A && R <= B) {
      return Max[X];
    }
    int Mid = L + R >> 1;
    return max(query(L, Mid, X << 1, A, B), query(Mid + 1, R, X << 1 | 1, A, B));
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  long long Sum = 0;
  for (int i = 0; i < N - 1; ++i) {
    Sum += abs(A[i] - A[i + 1]);
  }
  auto solve = [&] (vector<long long> A) -> long long {
    vector<pair<long long, long long>> P;
    for (int i = 0; i < N - 1; ++i) {
      if (A[i] < A[i + 1]) {
        P.emplace_back(A[i], A[i + 1]); 
      }
    }
    sort(P.begin(), P.end());
    long long ret = 0;
    multiset<long long> Max;
    for (int i = 0, j = 0; i < P.size(); ++i) {
      while (j < P.size() && P[j].first <= P[i].first) {
        Max.insert(P[j].second);
        j ++;
      }
      Max.erase(Max.find(P[i].second));
      if (!Max.empty() && *Max.rbegin() >= P[i].second) {
        ret = max(ret, P[i].second - P[i].first);
      }
      Max.insert(P[i].second);
    }
    vector<long long> V(A);
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    sgt sgt(V.size());
    sort(P.begin(), P.end(), [&] (auto A, auto B) -> bool {
      return A.second == B.second ? A.first < B.first : A.second < B.second;
    });
    for (int i = 0; i < P.size(); ++i) {
      ret = max(ret, sgt.query(0, (int)V.size() - 1, 1, 0, lower_bound(V.begin(), V.end(), P[i].first) - V.begin()) - P[i].first); 
      sgt.update(0, (int)V.size() - 1, 1, lower_bound(V.begin(), V.end(), P[i].first) - V.begin(), P[i].second);
    }
    return ret;
  };
  long long Max = solve(A);
  reverse(A.begin(), A.end());
  Max = max(Max, solve(A));
  long long Ans = Sum - Max * 2;
  for (int i = 1; i < N - 1; ++i) {
    Ans = min(Ans, Sum - abs(A[i] - A[i + 1]) + abs(A[0] - A[i + 1]));
  }
  for (int i = 1; i < N - 1; ++i) {
    Ans = min(Ans, Sum - abs(A[i] - A[i - 1]) + abs(A[N - 1] - A[i - 1]));
  }
  cout << Ans << '\n';
}
