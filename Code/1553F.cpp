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
  T range(int L, int R) {
    return query(R) - query(L - 1);
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
  vector<long long> P(N);
  FenwickTree<long long> c(300001);
  FenwickTree<long long> fw(300001);
  for (int i = 0; i < N; ++i) {
    P[i] += 1LL * A[i] * i + c.query(300000);
    long long last = fw.query(A[i] - 1);
    for (int j = 1; A[i] * j <= 300000; ++j) {
      long long cur = fw.query(min(300000, A[i] * (j + 1) - 1));
      P[i] -= 1LL * (cur - last) * A[i] * j;
      last = cur;
    }
    last = 0;
    for (int j = 1, k; j <= A[i]; j = k + 1) {
      k = A[i] / (A[i] / j);
      long long cur = c.query(k);
      P[i] -= 1LL * (A[i] / j) * (cur - last);
      last = cur;
    }
    fw.add(A[i], 1);
    c.add(A[i], A[i]);
  }
  for (int i = 0; i < N - 1; ++i) {
    P[i + 1] += P[i];
  }
  for (int i = 0; i < N; ++i) {
    cout << P[i] << " \n"[i == N - 1];
  }
}
