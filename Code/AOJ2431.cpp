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
      v[i - 1] = max(v[i - 1], val);
    }
  }
  T query(int p) {
    T Max = 0;
    for(int i = p + 1; i >= 1; i -= (i & -i)) {
      Max = max(Max, v[i - 1]);
    }
    return Max;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
    X[i] --;
  }
  FenwickTree<long long> fw(N);
  for (int i = 0; i < N; ++i) {
    long long V = fw.query(X[i] - 1);
    fw.add(X[i], V + X[i] + 1);
  }
  cout << 1LL * N * (N + 1) / 2 - fw.query(N - 1) << '\n';
}
