#include <bits/stdc++.h>
using namespace std;
template <class T> 
class FenwickTree {
  int N;
  vector<T> v;
 public:
  FenwickTree(int N) : N(N), v(N) {}
  void add(int p, T val) {
    for(int i = p + 1; i <= N; i += (i & -i)) {
      v[i - 1] += val;
    }
  }
  T query(int p) {
    T sum = 0;
    for(int i = p + 1; i >= 1; i -= (i & -i)) {
      sum += v[i - 1];
    }
    return sum;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i]; 
  }
  vector<pair<int, int>> P;
  for (int i = 0; i < N; ++i) {
    P.emplace_back(A[i], i);
  }
  sort(P.begin(), P.end(), [&] (auto X, auto Y) {
    return X.first == Y.first ? X.second < Y.second : X.first > Y.first;
  });
  int M;
  cin >> M;
  vector<tuple<int, int, int>> Q;
  for (int i = 0; i < M; ++i) {
    int K, Pos;
    cin >> K >> Pos;
    Q.emplace_back(K, Pos, i);
  }
  vector<int> ans(M);
  sort(Q.begin(), Q.end());
  FenwickTree<int> fw(N);
  int j = 0;
  for (auto [K, Pos, i] : Q) {
    while (j < K) {
      fw.add(P[j].second, 1); 
      j ++;
    }
    int L = -1;
    int R = N;
    while (R - L > 1) {
      int mid = L + R >> 1;
      if (fw.query(mid) >= Pos) {
        R = mid;
      } else {
        L = mid;
      }
    }
    ans[i] = A[R];
  }
  for (int i = 0; i < M; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
